#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <filesystem>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <queue>

namespace fs = std::filesystem;

struct MarketData {
    std::string timestamp;
    double price;
    int size;
    std::string exchange;
    std::string type;
    std::string symbol;
};

struct MarketDataCompare {
    bool operator()(const MarketData& data1, const MarketData& data2) const {
        if (data1.timestamp != data2.timestamp)
            return data1.timestamp > data2.timestamp;
        else
            return data1.symbol > data2.symbol;
    }
};

void processFile(const std::string& filePath, std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare>& marketDataHeap) {
    std::ifstream file(filePath);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            MarketData entry;

            std::getline(iss, entry.timestamp, ',');
            iss >> entry.price;
            iss.ignore();
            iss >> entry.size;
            iss.ignore();
            std::getline(iss, entry.exchange, ',');
            std::getline(iss, entry.type);
            entry.symbol = std::filesystem::path(filePath).stem().string();

            if (iss.fail()) {
                //std::cerr << "Invalid entry format: " << line << std::endl;
                continue;
            }

            marketDataHeap.push(std::move(entry));
        }
        file.close();
    }
}

void processFilesBatch(const std::vector<std::string>& filePaths, std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare>& marketDataHeap, std::mutex& heapMutex) {
    for (const auto& filePath : filePaths) {
        std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare> localHeap;
        processFile(filePath, localHeap);

        std::lock_guard<std::mutex> lock(heapMutex);
        while (!localHeap.empty()) {
            marketDataHeap.push(std::move(localHeap.top()));
            localHeap.pop();
        }
    }
}

class ThreadPool {
public:
    explicit ThreadPool(size_t numThreads) : stop(false) {
        for (size_t i = 0; i < numThreads; ++i) {
            workers.emplace_back([this] {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queueMutex);
                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
                        if (stop && tasks.empty()) {
                            return;
                        }
                        task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
                });
        }
    }

    template <class F, class... Args>
    void enqueue(F&& f, Args&&... args) {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            tasks.emplace([f = std::forward<F>(f), args = std::make_tuple(std::forward<Args>(args)...)] {
                std::apply(f, args);
                });
        }
        condition.notify_one();
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        for (std::thread& worker : workers) {
            worker.join();
        }
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queueMutex;
    std::condition_variable condition;
    bool stop;
};

void mergeFiles(const std::vector<std::string>& filePaths, const std::string& outputFilePath) {

    std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare> marketDataHeap;
    std::mutex heapMutex;

    const size_t numThreads = std::thread::hardware_concurrency();
    ThreadPool threadPool(numThreads);

    const size_t batchSize = (filePaths.size() + numThreads - 1) / numThreads;
    std::vector<std::vector<std::string>> fileBatches;
    for (size_t i = 0; i < filePaths.size(); i += batchSize) {
        auto start = filePaths.begin() + i;
        auto end = std::min(start + batchSize, filePaths.end());
        fileBatches.emplace_back(start, end);
    }

    std::atomic<int> filesProcessed(0);

    auto mergeBatch = [&](const std::vector<std::string>& batch) {
        std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare> localHeap;
        for (const auto& filePath : batch) {
            processFile(filePath, localHeap);
        }

        std::lock_guard<std::mutex> lock(heapMutex);
        while (!localHeap.empty()) {
            marketDataHeap.push(std::move(localHeap.top()));
            localHeap.pop();
        }

        ++filesProcessed;
    };

    for (const auto& batch : fileBatches) {
        threadPool.enqueue(mergeBatch, batch);
    }

    // Wait for all files to be processed
    while (filesProcessed < fileBatches.size()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::ofstream outputFile(outputFilePath);
    if (outputFile.is_open()) {
        while (!marketDataHeap.empty()) {
            MarketData entry = marketDataHeap.top();
            marketDataHeap.pop();

            outputFile << entry.timestamp << ","
                << std::setprecision(2) << std::fixed << entry.price << ","
                << entry.size << ","
                << entry.exchange << ","
                << entry.type << ","
                << entry.symbol << std::endl;
        }
        outputFile.close();

        std::cout << "Merged and sorted file created successfully: " << outputFilePath << std::endl;
    }
    else {
        std::cerr << "Unable to create the output file: " << outputFilePath << std::endl;
    }
}

int main() {
    std::string directory = "C:/files";
    std::string outputFilePath = "C:/files/output.txt";
    std::vector<std::string> inputFilePaths;
    auto startTime = std::chrono::steady_clock::now();
    // Iterate through each file in the directory
    // Assuming file extension is ".txt"
    for (auto& entry : fs::directory_iterator(directory)) {
        if (entry.path().extension() == ".txt") {
            inputFilePaths.emplace_back(std::move(entry.path().string()));
        }
    }
    mergeFiles(inputFilePaths, outputFilePath);

    auto endTime = std::chrono::steady_clock::now();
    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
    std::cout << "Total time taken: " << elapsedTime << " milliseconds" << std::endl;

    return 0;
}
