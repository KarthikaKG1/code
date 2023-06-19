//#include<iostream>
//#include<string>
//#include<cstring>
//
////std::string inputString = "asdf adsd rtret ryrty urtyuyt ytuu ytuy";
////
//////notepad - new
////
//////app asdf adsd rtret ryrty urtyuyt ytuu ytuy
//class Node {
//	char* data;
//	Node* next;
//	Node* prev;
//public:
//	Node():data(nullptr), next(nullptr),prev(nullptr){}
//
//	Node(char* data, Node* next_, Node* prev_) {
//		this->data = new char[strlen(data) + 1];
//		strcpy_s(this->data, strlen(data) + 1, data);
//		this->next = nullptr;
//		this->prev = nullptr;
//	}
//
//	Node* createNode(char* value)
//	{
//		Node* newNode = new Node();
//		newNode->data = new char[strlen(value) + 1];
//		strcpy_s(newNode->data, strlen(value) + 1, value);
//		newNode->prev = nullptr;
//		newNode->next = nullptr;
//		return newNode;
//	}
//
//	Node* addDoublyList(Node* head, char* val)
//	{
//		Node* newNode = createNode(val);
//		if (head == nullptr)
//		{
//			head = newNode;
//			return head;
//		}
//		else
//		{
//			Node* temp = head;
//			while (temp->next != NULL)
//			{
//				temp = temp->next;
//			}
//			temp->next = newNode;
//			newNode->prev = temp;
//		}
//		return head;
//	}
//	void printList(Node* head) {
//		Node* current = head;
//
//		while (current != nullptr) {
//			std::cout << current->data << " ";
//			std::cout << std::endl;
//			current = current->next;
//		}
//
//		std::cout << std::endl;
//	}
//
//	Node* deleteList(Node* head, int position)
//	{
//		if (head == NULL)
//			return head;
//
//		Node* temp = head;
//		for (int i = 1; i < position; ++i)
//		{
//			temp = temp->next;
//		}
//		temp->prev->next = temp->next;
//
//		if (temp->next != nullptr)
//			temp->next->prev = temp->prev;
//
//		delete temp;
//		return head;
//	}
//};
//
//void readInputArgv(char* str)
//{
//	
//	Node* head = nullptr;
//	int n = strlen(str) + 1;
//	char* word = new char[n];
//	int wordIndex = 0;
//
//	for (int i = 0; i < n; ++i)
//	{ 
//		char ch = str[i];
//		if (ch != ' ')
//			word[wordIndex++] = ch;
//		else {
//			if (wordIndex > 0) {
//				word[wordIndex] = '\0';
//				Node temp;
//				head = temp.addDoublyList(head, word);
//				//memset(word, '\0', n);
//				wordIndex = 0;
//			}
//		}
//	}
//
//	Node temp;
//	head = temp.addDoublyList(head, word);
//	temp.printList(head);
//	temp.deleteList(head, 3);
//	temp.printList(head);
//	delete [] word;
//}
//
//int main(int argc,char* argv[])
//{
//	if (argc < 2) {
//		std::cout << "Please provide a string as an argument." << std::endl;
//		return 1;
//	}
//
//	int numberOfArgument = argc - 1;
//	//When I have multiple string as input argument
//	/*char** inputstring = new char* [numberofargument];
//
//	for (int i = 1; i <= numberofargument; ++i) {
//
//		inputstring[i] = new char[strlen(argv[i]) + 1];
//		strcpy(inputstring[i], argv[1]);
//	}*/
//
//	//single string as input argument
//	char* inputString = new char[strlen(argv[1]) + 1];
//	strcpy_s(inputString,strlen(argv[1]) + 1, argv[1]);
//	
//	readInputArgv(inputString);
//
//    delete [] inputString;	
//}
//


//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int firstPosition(vector<int>& nums, int target) {
//    int n = nums.size();
//    int low = 0;
//    int high = n - 1;
//    int first = -1;
//
//    while (low <= high) {
//        int mid = (low + high) / 2;
//        cout << "mid: " << mid << endl;
//        if (nums[mid] == target) {
//            first = mid;
//            high = mid - 1;
//        }
//        else if (nums[mid] > target) {
//            high = mid - 1;
//        }
//        else {
//            low = mid + 1;
//        }
//    }
//
//    return first;
//}
//
//int lastPosition(vector<int>& nums, int target) {
//    int n = nums.size();
//    int low = 0;
//    int high = n - 1;
//    int last = -1;
//
//    while (low <= high) {
//        int mid = (low + high) / 2;
//        cout << "mid: " << mid << endl;
//        if (nums[mid] == target) {
//            last = mid;
//            low = mid + 1;
//        }
//        else if (nums[mid] > target) {
//            high = mid - 1;
//        }
//        else {
//            low = mid + 1;
//        }
//    }
//
//    return last;
//}
//
//vector<int> searchRange(vector<int>& nums, int target) {
//    int first = firstPosition(nums, target);
//    if (first == -1) return { -1, -1 };
//    int last = lastPosition(nums, target);
//    return { first, last };
//}
//
//int main() {
//    vector<int> nums = { 1, 2, 2, 2, 3, 4, 5 };
//    int target = 2;
//    vector<int> result = searchRange(nums, target);
//    cout << "Result: " << result[0] << ", " << result[1] << endl;
//    return 0;
//}
//
//
//
//

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <ctime>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <sstream>
//#include <chrono>
//
//struct Entry {
//    std::tm timestamp;
//    double price;
//    int size;
//    std::string exchange;
//    std::string type;
//};
//
//struct ThreadData {
//    std::vector<Entry> entries;
//    std::mutex mutex;
//    std::condition_variable cv;
//};
//
//// Custom comparator for sorting entries based on timestamp
//bool compareEntries(const Entry& entry1, const Entry& entry2) {
//    return std::mktime(&entry1.timestamp) < std::mktime(&entry2.timestamp);
//}
//
//// Function to process a file and populate the entries vector
//void processFile(const std::string& filePath, ThreadData& threadData) {
//    std::ifstream file(filePath);
//    if (file.is_open()) {
//        std::string line;
//        while (std::getline(file, line)) {
//            std::istringstream ss(line);
//            Entry entry;
//            char comma;  // To read and discard the commas
//
//            ss >> std::get_time(&entry.timestamp, "%Y-%m-%d %H:%M:%S");
//            ss >> comma;
//            ss >> entry.price;
//            ss >> comma;
//            ss >> entry.size;
//            ss >> comma;
//            std::getline(ss, entry.exchange, ',');
//            ss >> comma;
//            std::getline(ss, entry.type);
//
//            if (ss.fail()) {
//                std::cerr << "Invalid entry format: " << line << std::endl;
//                continue;
//            }
//
//            // Add entry to the thread's data
//            std::lock_guard<std::mutex> lock(threadData.mutex);
//            threadData.entries.push_back(entry);
//        }
//
//        file.close();
//    }
//    else {
//        std::cerr << "Unable to open file: " << filePath << std::endl;
//    }
//
//    // Notify that the file processing is complete
//    threadData.cv.notify_all();
//}
//
//int main() {
//    std::string directory = "/path/to/files/";
//    std::string outputFilePath = "/path/to/output.txt";
//    std::vector<ThreadData> threadDataVec;
//    std::vector<std::thread> threads;
//
//    // Iterate through each file in the directory
//    // Assuming file extension is ".txt"
//    for (const auto& entry : std::filesystem::directory_iterator(directory)) {
//        if (entry.path().extension() == ".txt") {
//            ThreadData threadData;
//            threadDataVec.push_back(threadData);
//
//            // Start a new thread to process the file
//            std::thread thread(processFile, entry.path().string(), std::ref(threadDataVec.back()));
//            threads.push_back(std::move(thread));
//        }
//    }
//
//    // Wait for all threads to finish processing the files
//    for (auto& thread : threads) {
//        thread.join();
//    }
//
//    // Combine and sort the entries from all threads
//    std::vector<Entry> combinedEntries;
//    for (const auto& threadData : threadDataVec) {
//        std::lock_guard<std::mutex> lock(threadData.mutex);
//        combinedEntries.insert(combinedEntries.end(), threadData.entries.begin(), threadData.entries.end());
//    }
//    std::sort(combinedEntries.begin(), combinedEntries.end(), compareEntries);
//
//    // Write the sorted content to a new file
//    std::ofstream outputFile(outputFilePath);
//    if (outputFile.is_open()) {
//        for (const auto& entry : combinedEntries) {
//            std::tm* timestamp = std::localtime(&std::mktime(&entry.timestamp));
//            char timestampStr[20];
//            std::strftime(timestampStr, sizeof(timestampStr), "%Y-%m-%d %H:%M:%S", timestamp);
//            outputFile << timestampStr << "."
//                << std::setw(3) << std::setfill('0') << 0 << ","  // Assuming milliseconds are always ".000"
//                << entry.price << ","
//                << entry.size << ","
//                << entry.exchange << ","
//                << entry.type << std::endl;
//        }
//        outputFile.close();
//        std::cout << "Merged and sorted file created successfully: " << outputFilePath << std::endl;
//    }
//    else {
//        std::cerr << "Unable to create the output file: " << outputFilePath << std::endl;
//        return 1;
//    }
//
//    return 0;
//}
//
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <ctime>
//#include <boost/filesystem.hpp>
//#include <boost/algorithm/string.hpp>
//#include <sstream>
//#include <iomanip>
//
//namespace fs = boost::filesystem;
//
//struct Entry {
//    std::tm timestamp;
//    double price;
//    int size;
//    std::string exchange;
//    std::string type;
//};
//
//// Custom comparator for sorting entries based on timestamp
//bool compareEntries(const Entry& entry1, const Entry& entry2) {
//    return std::mktime(&entry1.timestamp) < std::mktime(&entry2.timestamp);
//}
//
//int main() {
//    std::string directory = "/path/to/files/";
//    std::string outputFilePath = "/path/to/output.txt";
//    std::vector<Entry> combinedEntries;
//
//    // Iterate through each file in the directory
//    // Assuming file extension is ".txt"
//    for (const auto& entry : fs::directory_iterator(directory)) {
//        if (entry.path().extension() == ".txt") {
//            std::ifstream file(entry.path().string());
//            if (file.is_open()) {
//                std::string line;
//                while (std::getline(file, line)) {
//                    std::istringstream ss(line);
//                    Entry entry;
//                    char comma;
//
//                    std::string timestampStr;
//                    ss >> timestampStr;
//                    try {
//                        std::tm tm = boost::posix_time::to_tm(
//                            boost::posix_time::time_from_string(timestampStr)
//                        );
//                        entry.timestamp = tm;
//                    }
//                    catch (const std::exception& e) {
//                        std::cerr << "Failed to parse timestamp: " << timestampStr << std::endl;
//                        continue;
//                    }
//
//                    ss >> comma;
//                    ss >> entry.price;
//                    ss >> comma;
//                    ss >> entry.size;
//                    ss >> comma;
//                    std::getline(ss, entry.exchange, ',');
//                    ss >> comma;
//                    std::getline(ss, entry.type);
//
//                    if (ss.fail()) {
//                        std::cerr << "Invalid entry format: " << line << std::endl;
//                        continue;
//                    }
//                    combinedEntries.push_back(entry);
//                }
//                file.close();
//            }
//        }
//    }
//
//    // Sort the combined entries based on the timestamp
//    std::sort(combinedEntries.begin(), combinedEntries.end(), compareEntries);
//
//    // Write the sorted content to a new file
//    std::ofstream outputFile(outputFilePath);
//    if (outputFile.is_open()) {
//        for (const auto& entry : combinedEntries) {
//            std::tm* timestamp = std::localtime(&std::mktime(&entry.timestamp));
//            char timestampStr[20];
//            std::strftime(timestampStr, sizeof(timestampStr), "%Y-%m-%d %H:%M:%S", timestamp);
//            outputFile << timestampStr << "."
//                << std::setw(3) << std::setfill('0') << 0 << ","  // Assuming milliseconds are always ".000"
//                << entry.price << ","
//                << entry.size << ","
//                << entry.exchange << ","
//                << entry.type << std::endl;
//        }
//        outputFile.close();
//        std::cout << "Merged and sorted file created successfully: " << outputFilePath << std::endl;
//    }
//    else {
//        std::cerr << "Unable to create the output file: " << outputFilePath << std::endl;
//        return 1;
//    }
//
//    return 0;
//}
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <ctime>
//#include <sstream>
//#include <iomanip>
//#include <filesystem>
//
//namespace fs = std::filesystem;
//
//struct Entry {
//    std::tm timestamp;
//    double price;
//    int size;
//    std::string exchange;
//    std::string type;
//};
//
//// Custom comparator for sorting entries based on timestamp
//bool compareEntries(const Entry& entry1, const Entry& entry2) {
//    return std::mktime(const_cast<std::tm*>(&entry1.timestamp)) < std::mktime(const_cast<std::tm*>(&entry2.timestamp));
//}
//
//int main() {
//    std::string directory = "C:/files";
//    std::string outputFilePath = "C:/files/output.txt";
//    std::vector<Entry> combinedEntries;
//
//    // Iterate through each file in the directory
//    // Assuming file extension is ".txt"
//    for (const auto& entry : fs::directory_iterator(directory)) {
//        if (entry.path().extension() == ".txt") {
//            std::ifstream file(entry.path().string());
//            if (file.is_open()) {
//                std::string line;
//                while (std::getline(file, line)) {
//                    std::istringstream ss(line);
//                    Entry entry;
//                    char comma;
//
//                    std::string timestampStr;
//                    ss >> timestampStr;
//                    try {
//                        std::tm tm{};
//
//                        std::istringstream timestampStream(timestampStr);
//                        timestampStream >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
//                        entry.timestamp = tm;
//                    }
//                    catch (const std::exception& e) {
//                        std::cerr << "Failed to parse timestamp: " << timestampStr << std::endl;
//                        continue;
//                    }
//
//                    ss >> comma;
//                    ss >> entry.price;
//                    ss >> comma;
//                    ss >> entry.size;
//                    ss >> comma;
//                    std::getline(ss, entry.exchange, ',');
//                    ss >> comma;
//                    std::getline(ss, entry.type);
//
//                    if (ss.fail()) {
//                        std::cerr << "Invalid entry format: " << line << std::endl;
//                        continue;
//                    }
//                    combinedEntries.push_back(entry);
//                }
//                file.close();
//            }
//        }
//    }
//
//    // Sort the combined entries based on the timestamp
//    std::sort(combinedEntries.begin(), combinedEntries.end(), compareEntries);
//
//    // Write the sorted content to a new file
//    std::ofstream outputFile(outputFilePath);
//    if (outputFile.is_open()) {
//        for (const auto& entry : combinedEntries) {
//            std::tm timestampCopy = entry.timestamp;
//            std::time_t timestamp = std::mktime(&timestampCopy);
//            std::tm localTime;
//            localtime_s(&localTime, &timestamp);
//            char timestampStr[20];
//            std::strftime(timestampStr, sizeof(timestampStr), "%Y-%m-%d %H:%M:%S", &localTime);
//            outputFile << timestampStr << "."
//                << std::setw(3) << std::setfill('0') << 0 << ","  // Assuming milliseconds are always ".000"
//                << entry.price << ","
//                << entry.size << ","
//                << entry.exchange << ","
//                << entry.type << std::endl;
//        }
//        outputFile.close();
//        std::cout << "Merged and sorted file created successfully: " << outputFilePath << std::endl;
//    }
//    else {
//        std::cerr << "Unable to create the output file: " << outputFilePath << std::endl;
//        return 1;
//    }
//
//    return 0;
//}
//working
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <ctime>
//#include <sstream>
//#include <iomanip>
//#include <filesystem>
//#include <thread>
//
//namespace fs = std::filesystem;
//
//struct Entry {
//    std::tm timestamp;
//    double price;
//    int size;
//    std::string exchange;
//    std::string type;
//};
//
//// Custom comparator for sorting entries based on timestamp
//bool compareEntries(const Entry& entry1, const Entry& entry2) {
//    return std::mktime(const_cast<std::tm*>(&entry1.timestamp)) < std::mktime(const_cast<std::tm*>(&entry2.timestamp));
//}
//
//// Function to process a single file
//void processFile(const std::string& filePath, std::vector<Entry>& entries) {
//    std::ifstream file(filePath);
//    if (file.is_open()) {
//        std::string line;
//        while (std::getline(file, line)) {
//            std::istringstream ss(line);
//            Entry entry;
//            char comma;
//
//            std::string timestampStr;
//            ss >> timestampStr;
//            try {
//                std::tm tm{};
//
//                std::istringstream timestampStream(timestampStr);
//                timestampStream >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
//                entry.timestamp = tm;
//            }
//            catch (const std::exception& e) {
//                std::cerr << "Failed to parse timestamp: " << timestampStr << std::endl;
//                continue;
//            }
//
//            ss >> comma;
//            ss >> entry.price;
//            ss >> comma;
//            ss >> entry.size;
//            ss >> comma;
//            std::getline(ss, entry.exchange, ',');
//            ss >> comma;
//            std::getline(ss, entry.type);
//
//            if (ss.fail()) {
//                std::cerr << "Invalid entry format: " << line << std::endl;
//                continue;
//            }
//            entries.push_back(entry);
//        }
//        file.close();
//    }
//}
//
//int main() {
//    std::string directory = "C:/files";
//    std::string outputFilePath = "C:/files/output.txt";
//    std::vector<Entry> combinedEntries;
//
//    // Container to hold the threads
//    std::vector<std::thread> threads;
//
//    // Iterate through each file in the directory
//    // Assuming file extension is ".txt"
//    for (const auto& entry : fs::directory_iterator(directory)) {
//        if (entry.path().extension() == ".txt") {
//            // Start a new thread to process the file
//            threads.emplace_back(processFile, entry.path().string(), std::ref(combinedEntries));
//        }
//    }
//
//    // Wait for all threads to finish
//    for (auto& thread : threads) {
//        thread.join();
//    }
//
//    // Sort the combined entries based on the timestamp
//    std::sort(combinedEntries.begin(), combinedEntries.end(), compareEntries);
//
//    // Write the sorted content to a new file
//    std::ofstream outputFile(outputFilePath);
//    if (outputFile.is_open()) {
//        for (const auto& entry : combinedEntries) {
//            std::tm timestampCopy = entry.timestamp;
//            std::time_t timestamp = std::mktime(&timestampCopy);
//            std::tm localTime;
//            localtime_s(&localTime, &timestamp);
//            char timestampStr[20];
//            std::strftime(timestampStr, sizeof(timestampStr), "%Y-%m-%d %H:%M:%S", &localTime);
//            outputFile << timestampStr << "."
//                << std::setw(3) << std::setfill('0') << 0 << ","  // Assuming milliseconds are always ".000"
//                << entry.price << ","
//                << entry.size << ","
//                << entry.exchange << ","
//                << entry.type << std::endl;
//        }
//        outputFile.close();
//        std::cout << "Merged and sorted file created successfully: " << outputFilePath << std::endl;
//    }
//    else {
//        std::cerr << "Unable to create the output file: " << outputFilePath << std::endl;
//        return 1;
//    }
//
//    return 0;
//}

//time working except milli
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <ctime>
//#include <sstream>
//#include <iomanip>
//#include <filesystem>
//#include <thread>
//
//namespace fs = std::filesystem;
//
//struct Entry {
//    std::tm timestamp;
//    double price;
//    int size;
//    std::string exchange;
//    std::string type;
//};
//
//// Custom comparator for sorting entries based on timestamp
//bool compareEntries(const Entry& entry1, const Entry& entry2) {
//    return std::mktime(const_cast<std::tm*>(&entry1.timestamp)) < std::mktime(const_cast<std::tm*>(&entry2.timestamp));
//}
//
//// Function to process a single file
//void processFile(const std::string& filePath, std::vector<Entry>& entries) {
//    std::ifstream file(filePath);
//    if (file.is_open()) {
//        std::string line;
//        while (std::getline(file, line)) {
//            std::istringstream ss(line);
//            Entry entry;
//            char comma;
//
//            std::string dateStr, timeStr;
//            ss >> dateStr >> timeStr;
//            try {
//                std::tm tm{};
//                std::istringstream dateStream(dateStr);
//                dateStream >> std::get_time(&tm, "%Y-%m-%d");
//
//                std::istringstream timeStream(timeStr);
//                timeStream >> std::get_time(&tm, "%H:%M:%S");
//
//                entry.timestamp = tm;
//            }
//            catch (const std::exception& e) {
//                std::cerr << "Failed to parse timestamp: " << dateStr << " " << timeStr << std::endl;
//                continue;
//            }
//
//            ss >> comma;
//            ss >> entry.price;
//            ss >> comma;
//            ss >> entry.size;
//            ss >> comma;
//            std::getline(ss, entry.exchange, ',');
//            ss >> comma;
//            std::getline(ss, entry.type);
//
//            if (ss.fail()) {
//                std::cerr << "Invalid entry format: " << line << std::endl;
//                continue;
//            }
//            entries.push_back(entry);
//        }
//        file.close();
//    }
//}
//
//int main() {
//    std::string directory = "C:/files";
//    std::string outputFilePath = "C:/files/output.txt";
//    std::vector<Entry> combinedEntries;
//
//    // Container to hold the threads
//    std::vector<std::thread> threads;
//
//    // Iterate through each file in the directory
//    // Assuming file extension is ".txt"
//    for (const auto& entry : fs::directory_iterator(directory)) {
//        if (entry.path().extension() == ".txt") {
//            // Start a new thread to process the file
//            threads.emplace_back(processFile, entry.path().string(), std::ref(combinedEntries));
//        }
//    }
//
//    // Wait for all threads to finish
//    for (auto& thread : threads) {
//        thread.join();
//    }
//
//    // Sort the combined entries based on the timestamp
//    std::sort(combinedEntries.begin(), combinedEntries.end(), compareEntries);
//
//    // Write the sorted content to a new file
//    std::ofstream outputFile(outputFilePath);
//    if (outputFile.is_open()) {
//        for (const auto& entry : combinedEntries) {
//            std::ostringstream timestampStream;
//            timestampStream << std::put_time(&entry.timestamp, "%Y-%m-%d %H:%M:%S");
//            std::string timestampStr = timestampStream.str();
//            outputFile << timestampStr << "."
//                << std::setfill('0') << std::setw(3) << 0 << ","  // Assuming milliseconds are always ".000"
//                << entry.price << ","
//                << entry.size << ","
//                << entry.exchange << ","
//                << entry.type << std::endl;
//        }
//        outputFile.close();
//        std::cout << "Merged and sorted file created successfully: " << outputFilePath << std::endl;
//    }
//    else {
//        std::cerr << "Unable to create the output file: " << outputFilePath << std::endl;
//        return 1;
//    }
//
//    return 0;
//}

//final working
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <ctime>
//#include <sstream>
//#include <iomanip>
//#include <filesystem>
//#include <thread>
//#include <mutex>
//
//namespace fs = std::filesystem;
//
//struct MarketData {
//    std::string timestamp;
//    double price;
//    int size;
//    std::string exchange;
//    std::string type;
//    std::string symbol;
//};
//
//// Custom comparator for sorting market data based on timestamp
////bool compareMarketData(const MarketData& data1, const MarketData& data2) {
////    return data1.timestamp < data2.timestamp;
////}
//bool compareMarketData(const MarketData& data1, const MarketData& data2) {
//    if (data1.timestamp != data2.timestamp)
//        return data1.timestamp < data2.timestamp;
//    else
//        return data1.symbol < data2.symbol;
//}
//
//// Function to process a single file
//void processFile(const std::string& filePath, std::vector<MarketData>& marketData, std::mutex& mtx) {
//    std::ifstream file(filePath);
//    if (file.is_open()) {
//        std::string line;
//        while (std::getline(file, line)) {
//            std::istringstream iss(line);
//            MarketData entry;
//
//            std::getline(iss, entry.timestamp, ',');
//            iss >> entry.price;
//            iss.ignore();
//            iss >> entry.size;
//            iss.ignore();
//            std::getline(iss, entry.exchange, ',');
//            std::getline(iss, entry.type);
//            entry.symbol = std::filesystem::path(filePath).stem().string();
//
//            if (iss.fail()) {
//                std::cerr << "Invalid entry format: " << line << std::endl;
//                continue;
//            }
//
//            std::lock_guard<std::mutex> lock(mtx);
//            marketData.push_back(entry);
//        }
//        file.close();
//    }
//}
//
//int main() {
//    std::string directory = "C:/files";
//    std::string outputFilePath = "C:/files/output.txt";
//    std::vector<MarketData> combinedMarketData;
//    std::mutex mtx;
//
//    // Container to hold the threads
//    std::vector<std::thread> threads;
//
//    // Iterate through each file in the directory
//    // Assuming file extension is ".txt"
//    for (const auto& entry : fs::directory_iterator(directory)) {
//        if (entry.path().extension() == ".txt") {
//            // Start a new thread to process the file
//            threads.emplace_back(processFile, entry.path().string(), std::ref(combinedMarketData), std::ref(mtx));
//        }
//    }
//
//    // Wait for all threads to finish
//    for (auto& thread : threads) {
//        thread.join();
//    }
//
//    // Sort the combined market data based on the timestamp
//    std::sort(combinedMarketData.begin(), combinedMarketData.end(), compareMarketData);
//
//    // Write the sorted content to a new file
//    std::ofstream outputFile(outputFilePath);
//    if (outputFile.is_open()) {
//        for (const auto& entry : combinedMarketData) {
//            outputFile << entry.timestamp << ","
//                << std::setprecision(2) << std::fixed << entry.price << ","
//                << entry.size << ","
//                << entry.exchange << ","
//                << entry.type << ","
//                << entry.symbol << std::endl;
//        }
//        outputFile.close();
//        std::cout << "Merged and sorted file created successfully: " << outputFilePath << std::endl;
//    }
//    else {
//        std::cerr << "Unable to create the output file: " << outputFilePath << std::endl;
//        return 1;
//    }
//
//    return 0;
//}

//performance improved with threadpool

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <ctime>
//#include <sstream>
//#include <iomanip>
//#include <filesystem>
//#include <thread>
//#include <mutex>
//
//namespace fs = std::filesystem;
//
//struct MarketData {
//    std::string timestamp;
//    double price;
//    int size;
//    std::string exchange;
//    std::string type;
//    std::string symbol;
//};
//
//bool compareMarketData(const MarketData& data1, const MarketData& data2) {
//    if (data1.timestamp != data2.timestamp)
//        return data1.timestamp < data2.timestamp;
//    else
//        return data1.symbol < data2.symbol;
//}
//
//void processFile(const std::string& filePath, std::vector<MarketData>& marketData, std::mutex& mtx) {
//    std::ifstream file(filePath);
//    if (file.is_open()) {
//        std::string line;
//        while (std::getline(file, line)) {
//            std::istringstream iss(line);
//            MarketData entry;
//
//            std::getline(iss, entry.timestamp, ',');
//            iss >> entry.price;
//            iss.ignore();
//            iss >> entry.size;
//            iss.ignore();
//            std::getline(iss, entry.exchange, ',');
//            std::getline(iss, entry.type);
//            entry.symbol = std::filesystem::path(filePath).stem().string();
//
//            if (iss.fail()) {
//                std::cerr << "Invalid entry format: " << line << std::endl;
//                continue;
//            }
//
//            std::lock_guard<std::mutex> lock(mtx);
//            marketData.push_back(entry);
//        }
//        file.close();
//    }
//}
//
//void parallelSort(std::vector<MarketData>& data, std::size_t start, std::size_t end) {
//    std::sort(data.begin() + start, data.begin() + end, compareMarketData);
//}
//
//int main() {
//    std::string directory = "C:/files";
//    std::string outputFilePath = "C:/files/output.txt";
//    std::vector<MarketData> combinedMarketData;
//    std::mutex mtx;
//
//    std::vector<std::thread> threads;
//    for (const auto& entry : fs::directory_iterator(directory)) {
//        if (entry.path().extension() == ".txt") {
//            threads.emplace_back(processFile, entry.path().string(), std::ref(combinedMarketData), std::ref(mtx));
//        }
//    }
//
//    for (auto& thread : threads) {
//        thread.join();
//    }
//
//    std::size_t numThreads = std::thread::hardware_concurrency();
//    std::size_t dataSize = combinedMarketData.size();
//    std::size_t chunkSize = dataSize / numThreads;
//
//    std::vector<std::thread> sortThreads;
//    for (std::size_t i = 0; i < numThreads; ++i) {
//        std::size_t start = i * chunkSize;
//        std::size_t end = (i == numThreads - 1) ? dataSize : start + chunkSize;
//        sortThreads.emplace_back(parallelSort, std::ref(combinedMarketData), start, end);
//    }
//
//    for (auto& thread : sortThreads) {
//        thread.join();
//    }
//
//    std::ofstream outputFile(outputFilePath);
//    if (outputFile.is_open()) {
//        for (const auto& entry : combinedMarketData) {
//            outputFile << entry.timestamp << ","
//                << std::setprecision(2) << std::fixed << entry.price << ","
//                << entry.size << ","
//                << entry.exchange << ","
//                << entry.type << ","
//                << entry.symbol << std::endl;
//        }
//        outputFile.close();
//        std::cout << "Merged and sorted file created successfully: " << outputFilePath << std::endl;
//    }
//    else {
//        std::cerr << "Unable to create the output file: " << outputFilePath << std::endl;
//        return 1;
//    }
//
//    return 0;
//}

//finally worked 

//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <ctime>
//#include <sstream>
//#include <iomanip>
//#include <filesystem>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <functional>
//#include <queue>
//
//namespace fs = std::filesystem;
//
//struct MarketData {
//    std::string timestamp;
//    double price;
//    int size;
//    std::string exchange;
//    std::string type;
//    std::string symbol;
//};
//
//bool compareMarketData(const MarketData& data1, const MarketData& data2) {
//    if (data1.timestamp != data2.timestamp)
//        return data1.timestamp < data2.timestamp;
//    else
//        return data1.symbol < data2.symbol;
//}
//
//void processFile(const std::string& filePath, std::vector<MarketData>& marketData) {
//    std::ifstream file(filePath);
//    if (file.is_open()) {
//        std::string line;
//        while (std::getline(file, line)) {
//            std::istringstream iss(line);
//            MarketData entry;
//
//            std::getline(iss, entry.timestamp, ',');
//            iss >> entry.price;
//            iss.ignore();
//            iss >> entry.size;
//            iss.ignore();
//            std::getline(iss, entry.exchange, ',');
//            std::getline(iss, entry.type);
//            entry.symbol = std::filesystem::path(filePath).stem().string();
//
//            if (iss.fail()) {
//                std::cerr << "Invalid entry format: " << line << std::endl;
//                continue;
//            }
//
//            marketData.push_back(entry);
//        }
//        file.close();
//    }
//}
//
//class ThreadPool {
//public:
//    explicit ThreadPool(size_t numThreads) : stop(false) {
//        for (size_t i = 0; i < numThreads; ++i) {
//            workers.emplace_back([this] {
//                while (true) {
//                    std::function<void()> task;
//                    {
//                        std::unique_lock<std::mutex> lock(queueMutex);
//                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
//                        if (stop && tasks.empty()) {
//                            return;
//                        }
//                        task = std::move(tasks.front());
//                        tasks.pop();
//                    }
//                    task();
//                }
//                });
//        }
//    }
//
//    template <class F, class... Args>
//    void enqueue(F&& f, Args&&... args) {
//        {
//            std::unique_lock<std::mutex> lock(queueMutex);
//            tasks.emplace([f = std::forward<F>(f), args = std::make_tuple(std::forward<Args>(args)...)] {
//                std::apply(f, args);
//                });
//        }
//        condition.notify_one();
//    }
//
//    ~ThreadPool() {
//        {
//            std::unique_lock<std::mutex> lock(queueMutex);
//            stop = true;
//        }
//        condition.notify_all();
//        for (std::thread& worker : workers) {
//            worker.join();
//        }
//    }
//
//private:
//    std::vector<std::thread> workers;
//    std::queue<std::function<void()>> tasks;
//    std::mutex queueMutex;
//    std::condition_variable condition;
//    bool stop;
//};
//
//void parallelSort(std::vector<MarketData>& data, std::size_t start, std::size_t end) {
//    std::sort(data.begin() + start, data.begin() + end, compareMarketData);
//}
//
//int main() {
//    std::string directory = "C:/files";
//    std::string outputFilePath = "C:/files/output.txt";
//    std::vector<MarketData> combinedMarketData;
//    std::mutex mtx;
//    std::condition_variable cv;
//    std::atomic<int> completedFiles(0);
//    int totalFiles = 0;
//
//    // Thread pool
//    size_t numThreads = std::thread::hardware_concurrency();
//    ThreadPool threadPool(numThreads);
//
//    // Task queue
//    std::queue<std::function<void()>> taskQueue;
//    std::mutex taskQueueMutex;
//    std::condition_variable taskQueueCondition;
//
//    auto startTime = std::chrono::steady_clock::now();
//    // Function to process a file and update combinedMarketData
//    auto processFileTask = [&](const std::string& filePath) {
//        std::vector<MarketData> marketData;
//        processFile(filePath, marketData);
//
//        {
//            std::lock_guard<std::mutex> lock(mtx);
//            combinedMarketData.insert(combinedMarketData.end(), marketData.begin(), marketData.end());
//        }
//
//        {
//            std::lock_guard<std::mutex> lock(taskQueueMutex);
//            ++completedFiles;
//
//            if (completedFiles == totalFiles) {
//                cv.notify_one();
//            }
//        }
//
//        taskQueueCondition.notify_one();
//    };
//
//    // Iterate through each file in the directory
//    // Assuming file extension is ".txt"
//    for (const auto& entry : fs::directory_iterator(directory)) {
//        if (entry.path().extension() == ".txt") {
//            // Add processFileTask to the task queue
//            {
//                std::lock_guard<std::mutex> lock(taskQueueMutex);
//                taskQueue.emplace(std::bind(processFileTask, entry.path().string()));
//            }
//
//            // Increment the total files count
//            ++totalFiles;
//        }
//    }
//
//    // Function to process tasks from the queue
//    auto processTaskQueue = [&]() {
//        while (true) {
//            std::function<void()> task;
//            {
//                std::unique_lock<std::mutex> lock(taskQueueMutex);
//                taskQueueCondition.wait(lock, [&]() { return !taskQueue.empty(); });
//                if (taskQueue.empty()) {
//                    return;
//                }
//                task = std::move(taskQueue.front());
//                taskQueue.pop();
//            }
//            task();
//        }
//    };
//
//    // Enqueue task processing in the thread pool
//    for (size_t i = 0; i < numThreads; ++i) {
//        threadPool.enqueue(processTaskQueue);
//    }
//
//    // Wait for all files to be processed
//    {
//        std::unique_lock<std::mutex> lock(mtx);
//        cv.wait(lock, [&]() { return completedFiles == totalFiles; });
//    }
//
//    // Sort the combined market data in parallel
//    std::size_t dataSize = combinedMarketData.size();
//    std::size_t chunkSize = dataSize / numThreads;
//    std::size_t start = 0;
//
//    for (std::size_t i = 0; i < numThreads - 1; ++i) {
//        std::size_t end = start + chunkSize;
//        threadPool.enqueue([&](std::size_t s, std::size_t e) {
//            parallelSort(combinedMarketData, s, e);
//
//            {
//                std::lock_guard<std::mutex> lock(mtx);
//                ++completedFiles;
//
//                if (completedFiles == totalFiles) {
//                    cv.notify_one();
//                }
//            }
//
//            taskQueueCondition.notify_one();
//            }, start, end);
//        start = end;
//    }
//
//    // Last task handles the remaining elements
//    parallelSort(combinedMarketData, start, dataSize);
//
//    // Wait for all tasks to finish
//    {
//        std::unique_lock<std::mutex> lock(mtx);
//        cv.wait(lock, [&]() { return completedFiles == totalFiles; });
//    }
//
//    auto endTime = std::chrono::steady_clock::now();
//    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
//    std::cout << "Total time taken: " << elapsedTime << " milliseconds" << std::endl;
//    
//
//     //Write the sorted content to a new file
//    std::ofstream outputFile(outputFilePath);
//    if (outputFile.is_open()) {
//        for (const auto& entry : combinedMarketData) {
//            outputFile << entry.timestamp << ","
//                << std::setprecision(2) << std::fixed << entry.price << ","
//                << entry.size << ","
//                << entry.exchange << ","
//                << entry.type << ","
//                << entry.symbol << std::endl;
//        }
//        outputFile.close();
//        std::cout << "Merged and sorted file created successfully: " << outputFilePath << std::endl;
//    }
//    else {
//        std::cerr << "Unable to create the output file: " << outputFilePath << std::endl;
//        return 1;
//    }
//
//    // Notify the condition variable to wake up the waiting threads
//    cv.notify_all();
//
//    // Wait for all worker threads to finish
//    threadPool.~ThreadPool();
//
//    return 0;
//}

//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <iomanip>
//#include <string>
//#include <chrono>
//#include <ctime>
//#include <random>
//
//void createFiles() {
//    std::string directory = "C:/files";
//    std::string baseFileName = "file";
//    std::string fileExtension = ".txt";
//
//    double initialPrice = 46.14;
//    int initialSize = 120;
//    std::string initialExchange = "NYSE_ARCA";
//    std::string initialType = "Ask";
//
//    std::random_device rd;
//    std::mt19937 gen(rd());
//    std::uniform_int_distribution<int> distribution(0, 1000);
//
//    for (int i = 0; i < 9990; ++i) {
//        std::ostringstream fileNameStream;
//        fileNameStream << directory << "/" << i << baseFileName  << fileExtension;
//        std::string filePath = fileNameStream.str();
//
//        std::ofstream file(filePath);
//        if (file.is_open()) {
//            // Write the headers in the first line
//            file << "Timestamp, Price, Size, Exchange, Type" << std::endl;
//
//            std::chrono::system_clock::time_point timestamp = std::chrono::system_clock::now();
//            for (int j = 0; j < 50; ++j) {
//                // Generate a random number of milliseconds to add to the timestamp
//                int millisecondsToAdd = distribution(gen);
//
//                // Add the random milliseconds to the timestamp
//                timestamp += std::chrono::milliseconds(millisecondsToAdd);
//
//                // Convert the timestamp to time_t for formatting
//                std::time_t time = std::chrono::system_clock::to_time_t(timestamp);
//                std::tm localTime = {};
//                localtime_s(&localTime, &time);
//
//                // Write the line with the formatted timestamp
//                file << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << "."
//                    << std::setfill('0') << std::setw(3) << millisecondsToAdd << ","
//                    << std::setprecision(2) << std::fixed << initialPrice << ","
//                    << initialSize << ","
//                    << initialExchange << ","
//                    << initialType << std::endl;
//            }
//
//            file.close();
//            std::cout << "File created: " << filePath << std::endl;
//        }
//        else {
//            std::cerr << "Unable to create the file: " << filePath << std::endl;
//        }
//    }
//}
//
//int main() {
//    createFiles();
//    return 0;
//}


//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <ctime>
//#include <sstream>
//#include <iomanip>
//#include <filesystem>
//#include <queue>
//
//namespace fs = std::filesystem;
//
//struct MarketData {
//    std::string timestamp;
//    double price;
//    int size;
//    std::string exchange;
//    std::string type;
//    std::string symbol;
//};
//
//struct MarketDataCompare {
//    bool operator()(const MarketData& data1, const MarketData& data2) const {
//        if (data1.timestamp != data2.timestamp)
//            return data1.timestamp > data2.timestamp;
//        else
//            return data1.symbol > data2.symbol;
//    }
//};
//
//void processFile(const std::string& filePath, std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare>& marketDataHeap) {
//    std::ifstream file(filePath);
//    if (file.is_open()) {
//        std::string line;
//        while (std::getline(file, line)) {
//            std::istringstream iss(line);
//            MarketData entry;
//
//            std::getline(iss, entry.timestamp, ',');
//            iss >> entry.price;
//            iss.ignore();
//            iss >> entry.size;
//            iss.ignore();
//            std::getline(iss, entry.exchange, ',');
//            std::getline(iss, entry.type);
//            entry.symbol = std::filesystem::path(filePath).stem().string();
//
//            if (iss.fail()) {
//                std::cerr << "Invalid entry format: " << line << std::endl;
//                continue;
//            }
//
//            marketDataHeap.push(entry);
//        }
//        file.close();
//    }
//}
//
//void mergeFiles(const std::vector<std::string>& filePaths, const std::string& outputFilePath) {
//    std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare> marketDataHeap;
//
//    for (const auto& filePath : filePaths) {
//        processFile(filePath, marketDataHeap);
//    }
//
//    std::ofstream outputFile(outputFilePath);
//    if (outputFile.is_open()) {
//        while (!marketDataHeap.empty()) {
//            MarketData entry = marketDataHeap.top();
//            marketDataHeap.pop();
//
//            outputFile << entry.timestamp << ","
//                << std::setprecision(2) << std::fixed << entry.price << ","
//                << entry.size << ","
//                << entry.exchange << ","
//                << entry.type << ","
//                << entry.symbol << std::endl;
//        }
//        outputFile.close();
//        std::cout << "Merged and sorted file created successfully: " << outputFilePath << std::endl;
//    }
//    else {
//        std::cerr << "Unable to create the output file: " << outputFilePath << std::endl;
//    }
//}
//
//int main() {
//    std::string directory = "C:/files";
//    std::string outputFilePath = "C:/files/output.txt";
//    std::vector<std::string> inputFilePaths;
//
//    // Iterate through each file in the directory
//    // Assuming file extension is ".txt"
//    for (const auto& entry : fs::directory_iterator(directory)) {
//        if (entry.path().extension() == ".txt") {
//            inputFilePaths.push_back(entry.path().string());
//        }
//    }
//
//    mergeFiles(inputFilePaths, outputFilePath);
//
//    return 0;
//}

//void mergeFiles(const std::vector<std::string>& filePaths, const std::string& outputFilePath) {
//    std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare> marketDataHeap;
//    std::mutex heapMutex;
//
//    ThreadPool threadPool(std::thread::hardware_concurrency());
//
//    std::atomic<int> filesProcessed(0);
//
//    auto mergeFile = [&](const std::string& filePath) {
//        std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare> localHeap;
//        processFile(filePath, localHeap);
//
//        std::lock_guard<std::mutex> lock(heapMutex);
//        while (!localHeap.empty()) {
//            marketDataHeap.push(localHeap.top());
//            localHeap.pop();
//        }
//
//        ++filesProcessed;
//    };
//
//    for (const auto& filePath : filePaths) {
//        threadPool.enqueue(mergeFile, filePath);
//    }
//
//    // Wait for all files to be processed
//    while (filesProcessed < filePaths.size()) {
//        //std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }
//
//    std::ofstream outputFile(outputFilePath);
//    if (outputFile.is_open()) {
//        while (!marketDataHeap.empty()) {
//            MarketData entry = marketDataHeap.top();
//            marketDataHeap.pop();
//
//            outputFile << entry.timestamp << ","
//                << std::setprecision(2) << std::fixed << entry.price << ","
//                << entry.size << ","
//                << entry.exchange << ","
//                << entry.type << ","
//                << entry.symbol << std::endl;
//        }
//        outputFile.close();
//
//    std::cout << "Merged and sorted file created successfully: " << outputFilePath << std::endl;
//    }
//    else {
//        std::cerr << "Unable to create the output file: " << outputFilePath << std::endl;
//    }
//}
//optimized for 10 sec
// 
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <ctime>
//#include <sstream>
//#include <iomanip>
//#include <filesystem>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <functional>
//#include <queue>
//
//namespace fs = std::filesystem;
//
//struct MarketData {
//    std::string timestamp;
//    double price;
//    int size;
//    std::string exchange;
//    std::string type;
//    std::string symbol;
//};
//
//struct MarketDataCompare {
//    bool operator()(const MarketData& data1, const MarketData& data2) const {
//        if (data1.timestamp != data2.timestamp)
//            return data1.timestamp > data2.timestamp;
//        else
//            return data1.symbol > data2.symbol;
//    }
//};
//
//void processFile(const std::string& filePath, std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare>& marketDataHeap) {
//    std::ifstream file(filePath);
//    if (file.is_open()) {
//        std::string line;
//        while (std::getline(file, line)) {
//            std::istringstream iss(line);
//            MarketData entry;
//
//            std::getline(iss, entry.timestamp, ',');
//            iss >> entry.price;
//            iss.ignore();
//            iss >> entry.size;
//            iss.ignore();
//            std::getline(iss, entry.exchange, ',');
//            std::getline(iss, entry.type);
//            entry.symbol = std::filesystem::path(filePath).stem().string();
//
//            if (iss.fail()) {
//                //std::cerr << "Invalid entry format: " << line << std::endl;
//                continue;
//            }
//
//            marketDataHeap.push(entry);
//        }
//        file.close();
//    }
//}
//void processFilesBatch(const std::vector<std::string>& filePaths, std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare>& marketDataHeap, std::mutex& heapMutex) {
//    for (const auto& filePath : filePaths) {
//        std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare> localHeap;
//        processFile(filePath, localHeap);
//
//        std::lock_guard<std::mutex> lock(heapMutex);
//        while (!localHeap.empty()) {
//            marketDataHeap.push(std::move(localHeap.top()));
//            localHeap.pop();
//        }
//    }
//}
//class ThreadPool {
//public:
//    explicit ThreadPool(size_t numThreads) : stop(false) {
//        for (size_t i = 0; i < numThreads; ++i) {
//            workers.emplace_back([this] {
//                while (true) {
//                    std::function<void()> task;
//                    {
//                        std::unique_lock<std::mutex> lock(queueMutex);
//                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
//                        if (stop && tasks.empty()) {
//                            return;
//                        }
//                        task = std::move(tasks.front());
//                        tasks.pop();
//                    }
//                    task();
//                }
//                });
//        }
//    }
//
//    template <class F, class... Args>
//    void enqueue(F&& f, Args&&... args) {
//        {
//            std::unique_lock<std::mutex> lock(queueMutex);
//            tasks.emplace([f = std::forward<F>(f), args = std::make_tuple(std::forward<Args>(args)...)] {
//                std::apply(f, args);
//                });
//        }
//        condition.notify_one();
//    }
//
//    ~ThreadPool() {
//        {
//            std::unique_lock<std::mutex> lock(queueMutex);
//            stop = true;
//        }
//        condition.notify_all();
//        for (std::thread& worker : workers) {
//            worker.join();
//        }
//    }
//
//private:
//    std::vector<std::thread> workers;
//    std::queue<std::function<void()>> tasks;
//    std::mutex queueMutex;
//    std::condition_variable condition;
//    bool stop;
//};
//
//void mergeFiles(const std::vector<std::string>& filePaths, const std::string& outputFilePath) {
//    std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare> marketDataHeap;
//    std::mutex heapMutex;
//
//    const size_t numThreads = std::thread::hardware_concurrency();
//    ThreadPool threadPool(numThreads);
//
//    const size_t batchSize = (filePaths.size() + numThreads - 1) / numThreads;
//    std::vector<std::vector<std::string>> fileBatches;
//    for (size_t i = 0; i < filePaths.size(); i += batchSize) {
//        auto start = filePaths.begin() + i;
//        auto end = std::min(start + batchSize, filePaths.end());
//        fileBatches.emplace_back(start, end);
//    }
//
//    std::atomic<int> filesProcessed(0);
//
//    auto mergeBatch = [&](const std::vector<std::string>& batch) {
//        processFilesBatch(batch, marketDataHeap, heapMutex);
//        ++filesProcessed;
//    };
//
//    for (const auto& batch : fileBatches) {
//        threadPool.enqueue(mergeBatch, batch);
//    }
//
//    // Wait for all files to be processed
//    while (filesProcessed < fileBatches.size()) {
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }
//
//    std::ofstream outputFile(outputFilePath);
//    if (outputFile.is_open()) {
//        while (!marketDataHeap.empty()) {
//            MarketData entry = marketDataHeap.top();
//            marketDataHeap.pop();
//    
//            outputFile << entry.timestamp << ","
//                << std::setprecision(2) << std::fixed << entry.price << ","
//                << entry.size << ","
//                << entry.exchange << ","
//                << entry.type << ","
//                << entry.symbol << std::endl;
//        }
//        outputFile.close();
//    
//    std::cout << "Merged and sorted file created successfully: " << outputFilePath << std::endl;
//    }
//    else {
//        std::cerr << "Unable to create the output file: " << outputFilePath << std::endl;
//    }
//}
//
//int main() {
//    std::string directory = "C:/files";
//    std::string outputFilePath = "C:/files/output.txt";
//    std::vector<std::string> inputFilePaths;
//    auto startTime = std::chrono::steady_clock::now();
//    // Iterate through each file in the directory
//    // Assuming file extension is ".txt"
//    for (const auto& entry : fs::directory_iterator(directory)) {
//        if (entry.path().extension() == ".txt") {
//            inputFilePaths.push_back(std::move(entry.path().string()));
//        }
//    }
//    mergeFiles(inputFilePaths, outputFilePath);
//
//    auto endTime = std::chrono::steady_clock::now();
//    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
//    std::cout << "Total time taken: " << elapsedTime << " milliseconds" << std::endl;
//
//    return 0;
//}

//Single Queue
// 
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <ctime>
//#include <sstream>
//#include <iomanip>
//#include <filesystem>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <functional>
//#include <queue>
//
//namespace fs = std::filesystem;
//
//struct MarketData {
//    std::string timestamp;
//    double price;
//    int size;
//    std::string exchange;
//    std::string type;
//    std::string symbol;
//};
//
//struct MarketDataCompare {
//    bool operator()(const MarketData& data1, const MarketData& data2) const {
//        if (data1.timestamp != data2.timestamp)
//            return data1.timestamp > data2.timestamp;
//        else
//            return data1.symbol > data2.symbol;
//    }
//};
//
//void processFile(const std::string& filePath, std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare>& marketDataHeap) {
//    std::ifstream file(filePath);
//    if (file.is_open()) {
//        std::string line;
//        while (std::getline(file, line)) {
//            std::istringstream iss(line);
//            MarketData entry;
//
//            std::getline(iss, entry.timestamp, ',');
//            iss >> entry.price;
//            iss.ignore();
//            iss >> entry.size;
//            iss.ignore();
//            std::getline(iss, entry.exchange, ',');
//            std::getline(iss, entry.type);
//            entry.symbol = std::filesystem::path(filePath).stem().string();
//
//            if (iss.fail()) {
//                //std::cerr << "Invalid entry format: " << line << std::endl;
//                continue;
//            }
//
//            marketDataHeap.push(entry);
//        }
//        file.close();
//    }
//}
//
//class ThreadPool {
//public:
//    explicit ThreadPool(size_t numThreads) : stop(false) {
//        for (size_t i = 0; i < numThreads; ++i) {
//            workers.emplace_back([this] {
//                while (true) {
//                    std::function<void()> task;
//                    {
//                        std::unique_lock<std::mutex> lock(queueMutex);
//                        condition.wait(lock, [this] { return stop || !tasks.empty(); });
//                        if (stop && tasks.empty()) {
//                            return;
//                        }
//                        task = std::move(tasks.front());
//                        tasks.pop();
//                    }
//                    task();
//                }
//                });
//        }
//    }
//
//    template <class F, class... Args>
//    void enqueue(F&& f, Args&&... args) {
//        {
//            std::unique_lock<std::mutex> lock(queueMutex);
//            tasks.emplace([f = std::forward<F>(f), args = std::make_tuple(std::forward<Args>(args)...)] {
//                std::apply(f, args);
//                });
//        }
//        condition.notify_one();
//    }
//
//    ~ThreadPool() {
//        {
//            std::unique_lock<std::mutex> lock(queueMutex);
//            stop = true;
//        }
//        condition.notify_all();
//        for (std::thread& worker : workers) {
//            worker.join();
//        }
//    }
//
//private:
//    std::vector<std::thread> workers;
//    std::queue<std::function<void()>> tasks;
//    std::mutex queueMutex;
//    std::condition_variable condition;
//    bool stop;
//};
//
//void mergeFiles(const std::vector<std::string>& filePaths, const std::string& outputFilePath) {
//    std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare> marketDataHeap;
//    std::mutex heapMutex;
//
//    const size_t numThreads = std::thread::hardware_concurrency();
//    ThreadPool threadPool(numThreads);
//
//    std::atomic<int> filesProcessed(0);
//
//    auto processFilesBatch = [&](const std::vector<std::string>& batch) {
//        std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare> localHeap;
//        for (const auto& filePath : batch) {
//            processFile(filePath, localHeap);
//        }
//
//        {
//            std::lock_guard<std::mutex> lock(heapMutex);
//            while (!localHeap.empty()) {
//                marketDataHeap.push(std::move(localHeap.top()));
//                localHeap.pop();
//            }
//        }
//
//        ++filesProcessed;
//    };
//
//    const size_t batchSize = (filePaths.size() + numThreads - 1) / numThreads;
//    for (size_t i = 0; i < filePaths.size(); i += batchSize) {
//        auto start = filePaths.begin() + i;
//        auto end = std::min(start + batchSize, filePaths.end());
//        threadPool.enqueue(processFilesBatch, std::vector<std::string>(start, end));
//    }
//
//    // Wait for all files to be processed
//    while (filesProcessed < numThreads) {
//        std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }
//
//    std::ofstream outputFile(outputFilePath);
//    if (outputFile.is_open()) {
//        while (!marketDataHeap.empty()) {
//            MarketData entry = marketDataHeap.top();
//            marketDataHeap.pop();
//
//            outputFile << entry.timestamp << ","
//                << std::setprecision(2) << std::fixed << entry.price << ","
//                << entry.size << ","
//                << entry.exchange << ","
//                << entry.type << ","
//                << entry.symbol << std::endl;
//        }
//        outputFile.close();
//
//        std::cout << "Merged and sorted file created successfully: " << outputFilePath << std::endl;
//    }
//    else {
//        std::cerr << "Unable to create the output file: " << outputFilePath << std::endl;
//    }
//}
//
//int main() {
//    std::string directory = "C:/files";
//    std::string outputFilePath = "C:/files/output.txt";
//    std::vector<std::string> inputFilePaths;
//    auto startTime = std::chrono::steady_clock::now();
//    // Iterate through each file in the directory
//    // Assuming file extension is ".txt"
//    for (const auto& entry : fs::directory_iterator(directory)) {
//        if (entry.path().extension() == ".txt") {
//            inputFilePaths.emplace_back(std::move(entry.path().string()));
//        }
//    }
//    mergeFiles(inputFilePaths, outputFilePath);
//
//    auto endTime = std::chrono::steady_clock::now();
//    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
//    std::cout << "Total time taken: " << elapsedTime << " milliseconds" << std::endl;
//
//    return 0;
//}
// 
//Multiple queue 
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <ctime>
//#include <sstream>
//#include <iomanip>
//#include <filesystem>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <functional>
//#include <queue>
//
//namespace fs = std::filesystem;
//
//struct MarketData {
//    std::string timestamp;
//    double price;
//    int size;
//    std::string exchange;
//    std::string type;
//    std::string symbol;
//};
//
//struct MarketDataCompare {
//    bool operator()(const MarketData& data1, const MarketData& data2) const {
//        if (data1.timestamp != data2.timestamp)
//            return data1.timestamp > data2.timestamp;
//        else
//            return data1.symbol > data2.symbol;
//    }
//};
//
//void processFile(const std::string& filePath, std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare>& marketDataHeap) {
//    std::ifstream file(filePath);
//    if (file.is_open()) {
//        std::string line;
//        while (std::getline(file, line)) {
//            std::istringstream iss(line);
//            MarketData entry;
//
//            std::getline(iss, entry.timestamp, ',');
//            iss >> entry.price;
//            iss.ignore();
//            iss >> entry.size;
//            iss.ignore();
//            std::getline(iss, entry.exchange, ',');
//            std::getline(iss, entry.type);
//            entry.symbol = std::filesystem::path(filePath).stem().string();
//
//            if (iss.fail()) {
//                //std::cerr << "Invalid entry format: " << line << std::endl;
//                continue;
//            }
//
//            marketDataHeap.push(entry);
//        }
//        file.close();
//    }
//}
//
//void mergeQueues(std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare>& queue1, std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare>& queue2) {
//    while (!queue2.empty()) {
//        queue1.push(std::move(queue2.top()));
//        queue2.pop();
//    }
//}
//
//void mergeFiles(const std::vector<std::string>& filePaths, const std::string& outputFilePath) {
//    const size_t numThreads = std::thread::hardware_concurrency();
//    const size_t batchSize = (filePaths.size() + numThreads - 1) / numThreads;
//
//    std::vector<std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare>> marketDataQueues(numThreads);
//    std::vector<std::thread> threads;
//
//    // Process files in batches using multiple threads
//    for (size_t i = 0; i < filePaths.size(); i += batchSize) {
//        auto start = filePaths.begin() + i;
//        auto end = std::min(start + batchSize, filePaths.end());
//
//        threads.emplace_back([start, end, &marketDataQueues]() {
//            std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare> localQueue;
//            for (auto it = start; it != end; ++it) {
//                processFile(*it, localQueue);
//            }
//            marketDataQueues.emplace_back(std::move(localQueue));
//            });
//    }
//
//    // Wait for all threads to finish
//    for (auto& thread : threads) {
//        thread.join();
//    }
//
//    // Merge the market data queues in a multithreaded manner
//    while (marketDataQueues.size() > 1) {
//        size_t size = marketDataQueues.size();
//        size_t mergeThreads = size / 2;
//
//        threads.clear();
//        for (size_t i = 0; i < mergeThreads; ++i) {
//            threads.emplace_back([=, &marketDataQueues]() {  // Explicitly capture mergeThreads by value [=]
//                mergeQueues(marketDataQueues[i], marketDataQueues[i + mergeThreads]);
//                });
//        }
//
//        // Wait for merge threads to finish
//        for (auto& thread : threads) {
//            thread.join();
//        }
//
//        // Remove the merged queues
//        marketDataQueues.resize(size - mergeThreads);
//    }
//
//    // Write the merged and sorted market data to the output file
//    std::ofstream outputFile(outputFilePath);
//    if (outputFile.is_open()) {
//        std::priority_queue<MarketData, std::vector<MarketData>, MarketDataCompare>& mergedQueue = marketDataQueues[0];
//        while (!mergedQueue.empty()) {
//            MarketData entry = mergedQueue.top();
//            mergedQueue.pop();
//
//            outputFile << entry.timestamp << ","
//                << std::setprecision(2) << std::fixed << entry.price << ","
//                << entry.size << ","
//                << entry.exchange << ","
//                << entry.type << ","
//                << entry.symbol << std::endl;
//        }
//        outputFile.close();
//
//        std::cout << "Merged and sorted file created successfully: " << outputFilePath << std::endl;
//    }
//    else {
//        std::cerr << "Unable to create the output file: " << outputFilePath << std::endl;
//    }
//}
//
//int main() {
//    std::string directory = "C:/files";
//    std::string outputFilePath = "C:/files/output.txt";
//    std::vector<std::string> inputFilePaths;
//    auto startTime = std::chrono::steady_clock::now();
//
//    // Iterate through each file in the directory
//    // Assuming file extension is ".txt"
//    for (auto& entry : fs::directory_iterator(directory)) {
//        if (entry.path().extension() == ".txt") {
//            inputFilePaths.emplace_back(std::move(entry.path().string()));
//        }
//    }
//
//    mergeFiles(inputFilePaths, outputFilePath);
//
//    auto endTime = std::chrono::steady_clock::now();
//    auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
//    std::cout << "Total time taken: " << elapsedTime << " milliseconds" << std::endl;
//
//    return 0;
//}

//local queues

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