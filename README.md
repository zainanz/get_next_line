# Get Next Line (42 Project)

The **Get Next Line** project is part of the 42 curriculum. Its objective is to implement a function that reads and returns one line at a time from a file descriptor.

## 📚 Project Overview

The function reads from a file or input stream until it encounters a newline character `\n` or reaches the end of the file. It handles memory allocation and buffering internally, ensuring each call to the function returns the next line in the input.

## 🧠 Function Prototype

```c
char *get_next_line(int fd);
```

- **`fd`**: The file descriptor to read from.
- Returns the next line, including the newline character (`\n`) if present, or `NULL` if there is nothing more to read or an error occurs.

## ⚙️ BUFFER_SIZE

The size of the internal read buffer can be specified at compile time:

```bash
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

If `BUFFER_SIZE` is not defined during compilation, the code uses a default value set in the source files.

## ✅ Usage Example

```c
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
```

## 📁 Project Files

- `get_next_line.c`: Main logic for reading lines
- `get_next_line_utils.c`: Helper functions
- `get_next_line.h`: Header file with declarations

## 📝 Notes

- The function must handle multiple file descriptors simultaneously in bonus.
- Proper memory management is essential — no leaks allowed.
- You must not read more data than necessary.

---

