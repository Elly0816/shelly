# Shelly - A Simple File Operation Shell

Shelly is a lightweight command-line utility that provides basic file operations like reading, writing, and getting file sizes.

## Features

- Read contents of text files
- Write text to files
- Get file size in bytes

## Usage

```bash
shelly <command> <filename>
```

### Available Commands

1. `read` - Read and display file contents
   ```bash
   shelly read example.txt
   ```

2. `write` - Write text to a file
   ```bash
   shelly write example.txt
   ```
   After running this command, type your text and press Enter twice to finish.

3. `size` - Get file size in bytes
   ```bash
   shelly size example.txt
   ```

## Building

The project can be built using a C compiler like gcc:

```bash
gcc -o shelly shelly.c functions.c -I.
```

## Error Handling

The utility includes error handling for common scenarios:
- Missing filename arguments
- File not found
- File access permissions
- Memory allocation failures

## Project Structure

- `shelly.c` - Main program entry point
- `functions.c` - Core functionality implementation
- `shelly.h` - Header file with declarations and constants
