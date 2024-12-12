# Standard Storage Language (SSL)

## Overview
The **Standard Storage Language (SSL)** is a C++ program that provides a simple interface to store and retrieve data using string identifiers. It leverages `std::variant` to handle different types of data (`int`, `double`, and `std::string`) and uses an `unordered_map` for efficient lookups.

The SSL program supports the following commands:
1. `store`: Store data associated with a name.
2. `see`: Retrieve and display data by its name.

## Features
- **Multiple Data Types**: Supports `int`, `double`, and `std::string` (or text).
- **Interactive CLI**: Command-line interface for storing and retrieving data.
- **Input Validation**: Ensures valid input for the specified data type.
- **Flexible Text Input**: Allows multi-word strings or text values.

## Structure

### 1. **`StandardStorage` Class**
   - **Purpose**: Manages data storage and retrieval.
   - **Methods**:
     - `store(const std::string& dataName, const std::variant<int, double, std::string>& data)`: Stores the data.
     - `see(const std::string& dataName)`: Displays the stored data, handling its type dynamically.
   - **Private Members**:
     - `std::unordered_map<std::string, std::variant<int, double, std::string>> storage`: The data container.

### 2. **Utility Functions**
   - `is_integer(const std::string& str)`: Checks if a string represents a valid integer.
   - `is_double(const std::string& str)`: Checks if a string represents a valid floating-point number.

### 3. **Main Function**
   - **Interactive Commands**:
     - `store`: Prompts for a name, type, and value, and stores the data.
     - `see`: Displays the value of a given name, if it exists.
     - `exit`: Terminates the program.

## Usage

### Running the Program
Compile and run the program in a terminal:
```bash
g++ -std=c++17 -o standard_storage standard_storage.cpp
./standard_storage

   - **Private Members**:
     - `std::unordered_map<std::string, std::variant<int, double, std::string>> storage`: The storage container, mapping each data name to a `std::variant` containing the data.

### 2. **Main Function**
   - **Purpose**: A loop that allows the user to interact with the program by entering commands to either store or view data.
   - **Commands**:
     - `store`: Prompts the user to enter the data name and type (`int`, `double`, or `string`) and then stores the value.
     - `see`: Prompts the user to enter the data name and displays the corresponding stored value.
     - `exit`: Exits the program.

## How to Use

1. **Start the program** by running the compiled executable.
2. **Enter a command**:
   - To **store** data, use the `store` command:
     ```
     Enter a command (store or see) or 'exit' to quit: store
     Enter the name of the data: myData
     Enter the type of data (int, double, string): int
     Enter an integer value: 42
     ```
   - To **see** stored data, use the `see` command:
     ```
     Enter a command (store or see) or 'exit' to quit: see
     Enter the name of the data: myData
     Data (myData): 42
     ```
   - To **exit** the program, type `exit`:
     ```
     Enter a command (store or see) or 'exit' to quit: exit
     ```
```
## Example

Enter a command (store or see) or 'exit' to quit: store
Enter the name of the data: age
Enter the type of data (int, double, string, text): int
Enter an integer value: 30

Enter a command (store or see) or 'exit' to quit: store
Enter the name of the data: height
Enter the type of data (int, double, string, text): double
Enter a double value: 5.9

Enter a command (store or see) or 'exit' to quit: store
Enter the name of the data: message
Enter the type of data (int, double, string, text): text
Enter a string (text) value: Hello, world!

Enter a command (store or see) or 'exit' to quit: see
Enter the name of the data: age
Data (age): 30

Enter a command (store or see) or 'exit' to quit: see
Enter the name of the data: height
Data (height): 5.9

Enter a command (store or see) or 'exit' to quit: see
Enter the name of the data: message
Data (message): Hello, world!

Enter a command (store or see) or 'exit' to quit: exit

## Requirements
- A C++ compiler that supports C++17 or higher (for `std::variant`).

## Compilation

To compile the program, use the following command (assuming the source code is saved in `standard_storage.cpp`):

```bash
g++ -std=c++17 -o standard_storage standard_storage.cpp

## License

This project is released under the MIT License.

## Contributing

Feel free to submit issues and pull requests for improvements or bug fixes.
