
# This project has been created as part of the 42 curriculum by [yousenna](https://github.com/youssenna)*

# ft_printf
## Description

This project is a custom implementation of the C standard library's `printf()` function. The goal is to recreate printf's functionality from scratch, handling various format specifiers, conversions, and output formatting.

### Learning Goals

- Master **variadic functions** in C (`va_start`, `va_arg`, `va_end`)
- Understand **format string parsing** and pattern matching
- Practice **type conversions** and formatted output
- Improve skills in **modular code design**
- Learn low-level I/O operations with `write()`

## Features

- ✅ Handles multiple conversion specifiers (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`)
- ✅ Returns the number of characters printed (like standard printf)
- ✅ Proper NULL handling for strings and pointers
- ✅ Memory-safe implementation with no memory leaks
- ✅ Follows 42 School norminette coding standards

## Supported Conversion Specifiers

| Specifier | Description | Example Output |
|-----------|-------------|----------------|
| `%c` | Single character | `A` |
| `%s` | String | `Hello` or `(null)` |
| `%p` | Pointer address | `0x7ffeefbff5c8` |
| `%d` | Signed decimal integer | `-42` |
| `%i` | Signed integer (same as %d) | `42` |
| `%u` | Unsigned decimal integer | `4294967295` |
| `%x` | Hexadecimal (lowercase) | `2a` |
| `%X` | Hexadecimal (uppercase) | `2A` |
| `%%` | Literal percent sign | `%` |

## Installation

Clone the repository:

```bash
git clone https://github.com/youssenna/ft_printf.git
cd ft_printf
```

Build the library:

```bash
make
```

This will create `libftprintf.a` that you can link with your projects.

### Makefile Targets

```bash
make        # Build the library
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Rebuild everything from scratch
```

## Usage

### Basic Usage

1. Include the header in your source file:
```c
#include "ft_printf.h"
```

2. Create a test program:
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s!\n", "World");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    return (0);
}
```

3. Compile with your program:
```bash
gcc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

### Return Value

Like the standard `printf()`, `ft_printf()` returns the **total number of characters printed**:

```c
int count = ft_printf("Hello %s!", "World");
// count will be 12 (including "Hello World!")
```

## Examples

### Basic Conversions

```c
// Characters and Strings
ft_printf("Char: %c\n", 'A');                    // Output: Char: A
ft_printf("String: %s\n", "Hello");              // Output: String: Hello
ft_printf("NULL string: %s\n", NULL);            // Output: NULL string: (null)

// Numbers
ft_printf("Integer: %d\n", 42);                  // Output: Integer: 42
ft_printf("Negative: %d\n", -42);                // Output: Negative: -42
ft_printf("Unsigned: %u\n", 4294967295);         // Output: Unsigned: 4294967295

// Hexadecimal
ft_printf("Hex (lower): %x\n", 255);             // Output: Hex (lower): ff
ft_printf("Hex (upper): %X\n", 255);             // Output: Hex (upper): FF

// Pointers
int *ptr = NULL;
ft_printf("Pointer: %p\n", ptr);                 // Output: Pointer: 0x0 or (nil)

// Percent sign
ft_printf("Percentage: 100%%\n");                // Output: Percentage: 100%
```

### Mixed Format Strings

```c
ft_printf("Name: %s, Age: %d, Score: %u%%\n", "Alice", 25, 95);
// Output: Name: Alice, Age: 25, Score: 95%

ft_printf("Address: %p, Value: %d, Hex: %x\n", &var, var, var);
// Output: Address: 0x7fff5fbff5c8, Value: 42, Hex: 2a
```

### Comparison with Standard printf

```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int std_ret, ft_ret;
    
    std_ret = printf("Standard: %d %s\n", 42, "test");
    ft_ret = ft_printf("Custom:   %d %s\n", 42, "test");
    
    printf("printf returned: %d\n", std_ret);
    ft_printf("ft_printf returned: %d\n", ft_ret);
    
    return (0);
}
```

## Project Structure

```
ft_printf/
├── ft_printf.h          # Header file with prototypes
├── ft_printf.c          # Main function and format parser
├── ft_putchar.c         # Character output (%c)
├── ft_putstr.c          # String output (%s)
├── ft_putnbr.c          # Integer output (%d, %i)
├── ft_putunsig.c        # Unsigned integer output (%u)
├── ft_puthex.c          # Hexadecimal output (%x, %X)
├── ft_putaddr.c         # Pointer address output (%p)
├── Makefile             # Build configuration
└── README.md            # This file
```

## Implementation Details

### How It Works

1. **Format String Parsing**: Scans the format string character by character
2. **Specifier Detection**: When `%` is found, identifies the conversion specifier
3. **Type Handling**: Routes to appropriate conversion function based on specifier
4. **Character Counting**: Tracks and returns total characters written
5. **Error Handling**: Manages NULL pointers and edge cases

### Core Algorithm

```
Input: format string + variadic arguments
│
├─→ Regular character? → Write directly
│
└─→ '%' found?
    ├─→ Identify specifier (c, s, d, i, u, x, X, p, %)
    ├─→ Extract argument with va_arg()
    ├─→ Convert to string/output format
    ├─→ Write to stdout using write()
    └─→ Count characters written
│
Output: Total character count
```

### Allowed Functions

This project only uses:
- `write` - for output
- `malloc` - for dynamic memory allocation
- `free` - for memory cleanup
- `va_start`, `va_arg`, `va_end` - for variadic arguments

**Not allowed**: Any standard library functions like `printf`, `sprintf`, `snprintf`, etc.

## Testing

### Manual Testing

Create a test file to compare outputs:

```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    printf("=== Testing Characters ===\n");
    printf("STD: %c\n", 'A');
    ft_printf("FT:  %c\n", 'A');
    
    printf("\n=== Testing Strings ===\n");
    printf("STD: %s\n", "Hello");
    ft_printf("FT:  %s\n", "Hello");
    
    printf("\n=== Testing NULL ===\n");
    printf("STD: %s\n", (char *)NULL);
    ft_printf("FT:  %s\n", (char *)NULL);
    
    printf("\n=== Testing Numbers ===\n");
    printf("STD: %d, %i, %u\n", -42, 42, 4294967295u);
    ft_printf("FT:  %d, %i, %u\n", -42, 42, 4294967295u);
    
    printf("\n=== Testing Hex ===\n");
    printf("STD: %x, %X\n", 255, 255);
    ft_printf("FT:  %x, %X\n", 255, 255);
    
    int var = 42;
    printf("\n=== Testing Pointers ===\n");
    printf("STD: %p\n", &var);
    ft_printf("FT:  %p\n", &var);
    
    return (0);
}
```

### Automated Testing

Use testers like:
- [printfTester](https://github.com/Tripouille/printfTester)
- [ft_printf_tester](https://github.com/paulo-santana/ft_printf_tester)
- [42TESTERS-PRINTF](https://github.com/xicodomingues/francinette)

```bash
# Example with printfTester
git clone https://github.com/Tripouille/printfTester.git
cd printfTester
make m
# Follow tester instructions
```

## Common Pitfalls

⚠️ **Buffer Overflow**: Always check string lengths before writing
⚠️ **Memory Leaks**: Free all allocated memory before returning
⚠️ **NULL Handling**: Test with NULL pointers for `%s` and `%p`
⚠️ **Negative Numbers**: Ensure proper handling of negative integers
⚠️ **Return Value**: Must match the exact character count printed
⚠️ **Write Errors**: Handle cases where `write()` might fail

## Project Constraints

- Maximum 5 functions per file (42 norm)
- No global variables
- Functions must not exceed 25 lines
- Follow 42 School norminette standards
- Only allowed functions: `write`, `malloc`, `free`, `va_start`, `va_arg`, `va_end`

## Resources

- [Variadic Functions in C](https://en.cppreference.com/w/c/variadic)
- [printf Format Specifiers](https://www.cplusplus.com/reference/cstdio/printf/)
- [Understanding write() System Call](https://man7.org/linux/man-pages/man2/write.2.html)
- [42 Cursus - ft_printf Guide](https://harm-smits.github.io/42docs/projects/ft_printf)

## Author

**Youssef Ennajar** - [LinkedIn](https://www.linkedin.com/in/youssef-ennajar-213985253/) | [GitHub](https://github.com/youssenna)

---

*Created as part of the 42 Network curriculum*
