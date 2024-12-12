#include <iostream>
#include <unordered_map>
#include <string>
#include <variant>
#include <limits>

class StandardStorage {
public:
    // Store data using a string as a key, with any type of data (variant can hold different types)
    void store(const std::string& dataName, const std::variant<int, double, std::string>& data) {
        storage[dataName] = data;
    }

    // Access stored data by its name
    void see(const std::string& dataName) {
        if (storage.find(dataName) != storage.end()) {
            const auto& data = storage[dataName];
            // Check type of data and print accordingly
            if (std::holds_alternative<int>(data)) {
                std::cout << "Data (" << dataName << "): " << std::get<int>(data) << std::endl;
            }
            else if (std::holds_alternative<double>(data)) {
                std::cout << "Data (" << dataName << "): " << std::get<double>(data) << std::endl;
            }
            else if (std::holds_alternative<std::string>(data)) {
                std::cout << "Data (" << dataName << "): " << std::get<std::string>(data) << std::endl;
            }
        } else {
            std::cout << "Data with name \"" << dataName << "\" not found!" << std::endl;
        }
    }

private:
    std::unordered_map<std::string, std::variant<int, double, std::string>> storage; // Map to hold the data
};

int main() {
    StandardStorage db;
    std::string command;
    
    while (true) {
        std::cout << "Enter a command (store or see) or 'exit' to quit: ";
        std::cin >> command;
        
        if (command == "exit") {
            break; // Exit the program
        } else if (command == "store") {
            // User wants to store data, get the data name and value
            std::string name;
            std::cout << "Enter the name of the data: ";
            std::cin >> name;
            
            std::cout << "Enter the type of data (int, double, string): ";
            std::string type;
            std::cin >> type;
            
            if (type == "int") {
                int value;
                std::cout << "Enter an integer value: ";
                std::cin >> value;
                db.store(name, value);
            } else if (type == "double") {
                double value;
                std::cout << "Enter a double value: ";
                std::cin >> value;
                db.store(name, value);
            } else if (type == "string") {
                std::string value;
                std::cout << "Enter a string value: ";
                std::cin >> value;
                db.store(name, value);
            } else {
                std::cout << "Invalid type! Only 'int', 'double', or 'string' are allowed." << std::endl;
            }
        } else if (command == "see") {
            // User wants to see a stored data, get the data name
            std::string name;
            std::cout << "Enter the name of the data: ";
            std::cin >> name;
            db.see(name);
        } else {
            std::cout << "Unknown command! Please use 'store' or 'see'." << std::endl;
        }
    }

    return 0;
}
