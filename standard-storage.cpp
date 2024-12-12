#include <iostream>
#include <unordered_map>
#include <string>
#include <variant>
#include <limits>
#include <cctype>
#include <sstream>

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

// Utility function to check if a string is a valid integer
bool is_integer(const std::string& str) {
    if (str.empty()) return false;
    for (size_t i = 0; i < str.length(); ++i) {
        if (i == 0 && str[i] == '-') continue; // Allow negative sign at the beginning
        if (!isdigit(str[i])) return false;
    }
    return true;
}

// Utility function to check if a string is a valid double
bool is_double(const std::string& str) {
    std::istringstream stream(str);
    double val;
    stream >> val;
    return !stream.fail() && stream.eof();
}

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
            
            std::cout << "Enter the type of data (int, double, string, text): ";
            std::string type;
            std::cin >> type;
            
            if (type == "int") {
                int value;
                std::cout << "Enter an integer value: ";
                while (!(std::cin >> value)) {
                    std::cout << "Invalid input! Please enter a valid integer: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                db.store(name, value);
            } else if (type == "double") {
                double value;
                std::cout << "Enter a double value: ";
                while (!(std::cin >> value)) {
                    std::cout << "Invalid input! Please enter a valid double: ";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                db.store(name, value);
            } else if (type == "string" || type == "text") {
                std::string value;
                std::cout << "Enter a string (text) value: ";
                std::cin.ignore();  // Clear the newline left over in the input buffer
                std::getline(std::cin, value); // Allow multi-word input
                db.store(name, value);
            } else {
                std::cout << "Invalid type! Only 'int', 'double', 'string', or 'text' are allowed." << std::endl;
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
