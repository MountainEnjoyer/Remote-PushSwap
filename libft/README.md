*This project has been created as part of the 42 curriculum by zchauve.*

# Libft

## Description

Libft is my first C library at 42. The goal of the project is to understand how the most common standard C functions work by reimplementing them, and to build a reusable toolbox for the next projects of the curriculum.

The library is compiled into a static archive, `libft.a`, and is organised in three parts:

- **Part 1 – Libc functions**: reimplementations of standard functions, with the same prototypes and behaviour as the originals (prefixed with `ft_`).
- **Part 2 – Additional functions**: string and output utilities that are not in the libc, or exist there in a different form.
- **Part 3 – Linked list**: functions to create and manipulate singly linked lists built on the `t_list` structure.

## Instructions

### Requirements

- A C compiler (`cc`)
- `make`
- `ar` (used to create the archive)

### Compilation

At the root of the repository:

```sh
make        # builds libft.a
make clean  # removes object files
make fclean # removes object files and libft.a
make re     # fclean + all
```

All sources are compiled with `-Wall -Wextra -Werror`.

### Using the library in a project

Include the header in your sources:

```c
#include "libft.h"
```

Then link against the archive when compiling:

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -I. -o my_program
```

## Library details

### Part 1 – Libc functions

| Function | Description |
|---|---|
| `ft_isalpha` | Returns 1 if the character is a letter, 0 otherwise |
| `ft_isdigit` | Returns 1 if the character is a digit (`0`–`9`), 0 otherwise |
| `ft_isalnum` | Returns 1 if the character is a letter or a digit, 0 otherwise |
| `ft_isascii` | Returns 1 if the value is in the ASCII table (0–127), 0 otherwise |
| `ft_isprint` | Returns 1 if the character is printable (32–126), 0 otherwise |
| `ft_strlen` | Returns the length of a string |
| `ft_memset` | Fills a memory area with a given byte |
| `ft_bzero` | Sets a memory area to zero |
| `ft_memcpy` | Copies `n` bytes between non-overlapping memory areas |
| `ft_memmove` | Copies `n` bytes, handling overlapping memory areas |
| `ft_strlcpy` | Size-bounded string copy, always NUL-terminated |
| `ft_strlcat` | Size-bounded string concatenation |
| `ft_toupper` | Converts a lowercase letter to uppercase |
| `ft_tolower` | Converts an uppercase letter to lowercase |
| `ft_strchr` | Finds the first occurrence of a character in a string |
| `ft_strrchr` | Finds the last occurrence of a character in a string |
| `ft_strncmp` | Compares at most `n` characters of two strings |
| `ft_memchr` | Finds a byte in a memory area |
| `ft_memcmp` | Compares two memory areas |
| `ft_strnstr` | Finds a substring within the first `len` characters of a string |
| `ft_atoi` | Converts a string to an `int` |
| `ft_calloc` | Allocates zero-initialised memory (returns a freeable pointer when size is 0) |
| `ft_strdup` | Returns a newly allocated copy of a string |

### Part 2 – Additional functions

| Function | Description |
|---|---|
| `ft_substr` | Returns a new substring starting at `start`, of maximum length `len` |
| `ft_strjoin` | Returns a new string made of `s1` followed by `s2` |
| `ft_strtrim` | Returns a copy of `s1` with the characters of `set` removed from both ends |
| `ft_split` | Splits a string on a delimiter and returns a NULL-terminated array of new strings |
| `ft_itoa` | Converts an `int` to a newly allocated string (negatives handled) |
| `ft_strmapi` | Applies a function to each character (with its index) and returns a new string |
| `ft_striteri` | Applies a function to each character of a string, in place |
| `ft_putchar_fd` | Writes a character to a file descriptor |
| `ft_putstr_fd` | Writes a string to a file descriptor |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor |
| `ft_putnbr_fd` | Writes an integer to a file descriptor |

### Part 3 – Linked list

All list functions use the following structure, declared in `libft.h`:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Allocates a new node with the given content and `next` set to NULL |
| `ft_lstadd_front` | Adds a node at the beginning of a list |
| `ft_lstsize` | Returns the number of nodes in a list |
| `ft_lstlast` | Returns the last node of a list |
| `ft_lstadd_back` | Adds a node at the end of a list |
| `ft_lstdelone` | Frees a node and its content (using `del`), without touching the next node |
| `ft_lstclear` | Frees a node and all its successors, then sets the list pointer to NULL |
| `ft_lstiter` | Applies a function to the content of each node |
| `ft_lstmap` | Creates a new list by applying a function to each node's content |

## Resources

### References

- The `man` pages of the original libc functions (`man 3 strlcpy`, `man 3 memmove`, `man 3 calloc`, etc.)
- [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language), B. Kernighan & D. Ritchie
- [cppreference – C reference](https://en.cppreference.com/w/c)
- The 42 Norm (norminette documentation)
- [GNU Make manual](https://www.gnu.org/software/make/manual/make.html)

### Use of AI

AI (Claude) was used in a limited way :

- **README**: AI helped draft the structure of this README, which I then reviewed and completed.

