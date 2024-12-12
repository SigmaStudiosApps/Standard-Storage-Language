# Standard Storage Language (SSL)

## Overview
The **Standard Storage Language (SSL)** is a simple C++ program that allows users to store and retrieve different types of data using a string identifier (data name). It uses the `std::variant` class to store different types of data, such as `int`, `double`, and `std::string`. The data is stored in an unordered map, which allows for efficient lookups by the data name.

The SSL program offers two primary commands:
1. `store`: Store data associated with a name.
2. `see`: Retrieve and display stored data by its name.

## Features
- Store different data types: integers, floating-point numbers, and strings.
- Retrieve data by name and display it according to its type.
- Command-line interface for interaction.

## Structure

### 1. **StandardStorage Class**
   - **Purpose**: This class handles data storage and retrieval operations.
   - **Methods**:
     - `store(const std::string& dataName, const std::variant<int, double, std::string>& data)`: Stores data with a given name and value. The value can be of type `int`, `double`, or `std::string`.
     - `see(const std::string& dataName)`: Retrieves and displays data stored under the provided name. It checks the type of the data and prints it accordingly.

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

## Example

Here’s an example of how the program works:

Enter a command (store or see) or 'exit' to quit: store Enter the name of the data: age Enter the type of data (int, double, string): int Enter an integer value: 30

Enter a command (store or see) or 'exit' to quit: store Enter the name of the data: height Enter the type of data (int, double, string): double Enter a double value: 5.9

Enter a command (store or see) or 'exit' to quit: see Enter the name of the data: age Data (age): 30

Enter a command (store or see) or 'exit' to quit: see Enter the name of the data: height Data (height): 5.9

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
