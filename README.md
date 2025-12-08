
# ft_printf

ft_printf is a reimplementation of the C standard library function printf.  
This project aims to reproduce (a subset of) the behavior of printf: parsing format strings and printing formatted output for several conversion specifiers, flags, width and precision handling.

This repository contains a lightweight, school-style implementation suitable for learning about parsing, variadic functions and formatting.

---

## Table of Contents

- [Features](#features)
- [Supported conversions and flags](#supported-conversions-and-flags)
- [Installation / Build](#installation--build)
- [Usage](#usage)
- [Examples](#examples)
- [Project rules / Constraints](#project-rules--constraints)
- [File structure (suggested)](#file-structure-suggested)
- [Testing](#testing)
---

## Features

- Supports common conversion specifiers:
  - `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`
- Handles:
  - Field width
  - Precision (for strings, integers and hex)
  - Proper handling of `NULL` strings and pointer `0` values
- Robust error handling for malformed format strings (to the extent required by the project specifications)

---

## Supported conversions and flags

- Conversion specifiers:
  - `%c` — character
  - `%s` — string (prints `(null)` for `NULL`)
  - `%p` — pointer (printed as `0x` followed by lowercase hex)
  - `%d`, `%i` — signed decimal integer
  - `%u` — unsigned decimal integer
  - `%x` — unsigned hex (lowercase)
  - `%X` — unsigned hex (uppercase)
  - `%%` — prints a literal `%`

---

## Installation / Build

If this repository includes a Makefile, use:

```bash
make
```

Common make targets that this project usually supports:

```bash
make            # build the library (e.g. libftprintf.a) or binary
make clean      # remove object files
make fclean     # remove object files and binaries/libraries
make re         # fclean then make
```

Manual build example (compile into static library):

```bash
# Compile object files
gcc -Wall -Wextra -Werror -c *.c

# Create static library
ar rcs libftprintf.a *.o

# Example of linking into a test program
gcc -Wall -Wextra -Werror -o my_test test_main.c libftprintf.a
```

---

## Usage

Include the header for ft_printf in your source:

```c
#include "ft_printf.h"
```

Then call:

```c
int printed = ft_printf("Hello %s! Number: %d\n", "world", 42);
```

`ft_printf` returns the number of characters printed (same as the standard printf).

---

## Examples

Simple examples and expected outputs:

```c
ft_printf("Char: %c\n", 'A');                // Char: A
ft_printf("String: %s\n", "foo");          // String:        foo
ft_printf("Pointer: %p\n", ptr);             // Pointer: 0x7ffeefbff5c8
ft_printf("Percent: %%\n");                  // Percent: %
```

You can compare outputs with the system printf to check compatibility for the supported specifiers.

---

## Project rules / Constraints

(Adapt to the rules of your school or challenge)

- Only a limited set of standard library functions are allowed. Commonly permitted functions:
  - write, malloc, free, va_start, va_arg, va_end
- Forbidden functions typically include:
  - printf, fprintf, sprintf and other formatting helpers from the C standard library
- Keep code norms: 5 function per file when required, no global variables unless allowed, follow my project's style guide (line length, naming, etc.)

---

## [File structure (suggested)](https://github.com/youssenna/ft_printf)


---

## Testing

- Create small test programs that call ft_printf with a variety of format strings and compare against the system printf output.
- Example test runner (very small):

```c
// test_main.c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int a = printf("printf:  %d\n", 42);
    int b = ft_printf("ft_printf: %d\n", 42);
    printf("printf returned: %d, ft_printf returned: %d\n", a, b);
    return 0;
}
```

Compile and run both and compare outputs and return values.

---

#### EDITOR: [yousenna](https://www.linkedin.com/in/youssef-ennajar-213985253/)
