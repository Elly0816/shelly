# Shelly - A Simple File Operation Shell

Shelly is a lightweight command-line application implemented in C that facilitates common file operations. Designed with simplicity and clarity in mind, Shelly allows users to quickly read, write, and examine the size of both text and binary files directly from the terminal.

## Detailed Overview

This project is structured to separate command processing, file operations, and utility functions across distinct source files. The modular design makes Shelly easy to maintain and extend. In addition to basic text file operations, Shelly can handle structured binary data for student records.

### Key Functionalities

- **Read Text Files:** Open and display the contents of specified text files.
- **Write Text Files:** Create or overwrite files with user-entered text.
- **Determine File Size:** Calculate and display the total number of bytes in a file.
- **Binary File Operations:** 
  - **bwrite:** Write structured student data to a binary file. The `-a` flag enables appending data.
  - **bread:** Read and display student records from the binary file.

## Usage

Use Shelly with a command and, where necessary, a filename or additional flags:
```bash
shelly <command> <filename>
```

### Commands

- **read:** Read and display the contents of a text file.
  ```bash
  shelly read example.txt
  ```
- **write:** Write user-provided text to a file. After invoking, type your text and press Enter twice to finish.
  ```bash
  shelly write example.txt
  ```
- **size:** Display the size of a file in bytes.
  ```bash
  shelly size example.txt
  ```
- **bwrite:** Write structured student record into a binary file. Use the `-a` flag to append.
  ```bash
  shelly bwrite -a
  ```
- **bread:** Read and display student records from the binary file.
  ```bash
  shelly bread
  ```

## Building the Project

Compile the source code using gcc. Make sure to include all relevant files:
```bash
gcc -o shelly shelly.c functions.c -I.
```

## Error Handling

Shelly implements error checking for:
- Missing command arguments.
- File creation or access issues.
- Invalid user input.
- Memory allocation failures.

## Project Structure

- `shelly.c` – Main entry point managing command parsing and dispatch.
- `functions.c` – Contains core implementation for file operations.
- `shelly.h` – Header file with declarations, structures, and function prototypes.

## Future Enhancements

Future improvements may include:
- Advanced command-line option parsing.
- Additional file operations and improved binary data management.
- Logging for debugging and audit purposes.
- Interactive help and version display.
