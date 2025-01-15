# get_next_line

A function that reads a line from a file descriptor. This project will not only allow you to add a very convenient function to your collection, but it will also make you learn a highly interesting new concept in C programming: static variables.

## 📝 Project Overview

The goal of this project is to create a function that returns a line read from a file descriptor. This function will be useful for future projects, especially when you need to read content line by line from a file, stdin, or even a network connection.

### Function Prototype
```c
char *get_next_line(int fd);
```

## 🛠️ Mandatory Part

Your function must:
- Return the line that was read
- Return NULL if there is nothing else to read or if an error occurred
- Work as expected both when reading a file and when reading from stdin
- Return its result without the '\n' (newline character)
- Behave well when reading from multiple file descriptors
- Use only one static variable
- Be memory leak free

### Parameters
- `fd`: The file descriptor to read from

### Return Value
- The line that was read
- NULL if there is nothing else to read or if an error occurred

## 🎯 Bonus Part

The bonus part includes:
- Using only one static variable
- Being able to manage multiple file descriptors simultaneously
- For example, if you can read from fd 3, then 4, then 5, then return to 3, you should not lose the reading thread of each file descriptor.

## 🚀 Getting Started

### Prerequisites
- GCC compiler
- Make (optional)
- Basic understanding of file descriptors and static variables

### Installation
```bash
git clone https://github.com/[your-username]/get_next_line.git
cd get_next_line
```

### Usage
```c
#include "get_next_line.h"
#include <fcntl.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 📚 Project Structure

```
get_next_line/
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
└── README.md
```

### Files Description
- `get_next_line.c`: Main function implementation
- `get_next_line_utils.c`: Helper functions
- `get_next_line.h`: Header file with prototypes and defines

## ⚙️ Configuration

The buffer size can be modified during compilation:
```bash
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

## 🔍 Testing

Test your implementation with:
- Different buffer sizes
- Multiple file descriptors
- Large files
- Empty files
- Files with/without newlines at the end
- Standard input
- Invalid file descriptors

Example test files are provided in the `tests/` directory.

## ⚠️ Requirements

- Allowed functions: read, malloc, free
- All heap allocated memory must be properly freed
- No memory leaks
- Must comply with 42 Norm
- Buffer size must be defined during compilation

## 📝 Notes

- Be careful with the buffer size
- Handle memory allocation failures
- Check for read errors
- Consider edge cases (empty files, no newline at end)
- Watch out for memory leaks

