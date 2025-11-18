# get_next_line

Implementation of a function that reads a file descriptor **line by line**, returning
each line on successive calls. This project is part of the **42 curriculum** and focuses
on static variables, memory management, buffers, and efficient file reading.

> Developed at **42 Telefónica** by **Diego Valladares Ortega**.

---

## 🧩 Overview

The goal of this project is to implement the function:

```c
char *get_next_line(int fd);

This function returns the next line read from a file descriptor, including the newline
character \n if present. It must work with:

- Regular files

- Standard input

- Pipes

- Multiple file descriptors at the same time

- Bonus version with independent buffers per fd

The function must be memory safe, handle partial reads, and avoid leaks,
double frees, and undefined behavior.

🚀 Features
✔️ Mandatory

Reads one line at a time efficiently

Returns NULL on EOF or error

Preserves leftover buffer between calls

Works with any valid file descriptor

Handles incomplete buffers and lines of any length

✔️ Bonus

Supports multiple fds at once

Each fd keeps its own internal buffer

Works with parallel reads like:

get_next_line(fd1);
get_next_line(fd2);
get_next_line(fd1);

📁 Project Structure
src/
  get_next_line.c
  get_next_line_utils.c
  get_next_line_bonus.c
  get_next_line_utils_bonus.c

include/
  get_next_line.h
  get_next_line_bonus.h

tests/
  main.c
  test1.txt
  test2.txt
  test3.txt
  prueba.txt

Makefile
LICENSE
.gitignore
README.md

🔧 How to Compile
Build mandatory version
cc -Wall -Werror -Wextra -Iinclude src/get_next_line.c src/get_next_line_utils.c -c
ar rcs libgnl.a get_next_line.o get_next_line_utils.o

Build mandatory + bonus
make bonus


(If you add a Makefile that supports this — recommended for future projects.)

🧪 Example Test Program

You can test your function using the file in tests/main.c:

cc tests/main.c -L. -lgnl -Iinclude -o test_gnl
./test_gnl


Or test individual files:

./test_gnl tests/test1.txt
./test_gnl tests/test2.txt


You can also test it with standard input:

./test_gnl
<write something>
<press CTRL + D>

📚 What I Learned

File descriptor operations (read)

Handling dynamic buffers and partial reads

Managing static variables in C

String and memory manipulation

Avoiding memory leaks and dangling pointers

Developing scalable logic for multiple file descriptors

Defensive programming and edge-case handling

📄 License

This project is licensed under the MIT License.
See the LICENSE file for more details.
