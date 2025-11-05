# 🖨️ ft_printf

> *Because ft_putnbr() and ft_putstr() aren't enough*

[![42 Project](https://img.shields.io/badge/42-Project-00babc?style=flat-square&logo=42)](https://42.fr)
[![Norm](https://img.shields.io/badge/Norm-v3-blue?style=flat-square)]()
[![Language](https://img.shields.io/badge/Language-C-orange?style=flat-square&logo=c)]()
[![Grade](https://img.shields.io/badge/Grade-125%2F100-success?style=flat-square)]()

---

## 📖 About The Project

**ft_printf** is a recreation of the famous C library function `printf()`. This 42 project teaches you about variadic functions, type handling, and formatted output - essential skills for any C programmer.

By recoding printf, you'll discover:
- How variadic functions work under the hood
- The complexity of format string parsing
- Memory management and buffer handling
- The art of mimicking library functions

This isn't just about copying printf - it's about understanding one of the most fundamental functions in C programming.

---

## 🎯 Project Objectives

- ✅ **Variadic Functions** - Master `va_start`, `va_arg`, `va_end`
- ✅ **Format Parsing** - Handle multiple conversion specifiers
- ✅ **Type Handling** - Work with different data types
- ✅ **Buffer Management** - Optimize output operations
- ✅ **Edge Cases** - Handle NULL, negative numbers, and more
- ✅ **Code Reusability** - Build modular, maintainable code

---

## 🔧 Mandatory Requirements

### Supported Conversions

The function must handle the following conversions:

| Specifier | Description | Example |
|-----------|-------------|---------|
| `%c` | Single character | `'a'` |
| `%s` | String of characters | `"Hello"` |
| `%p` | Pointer address in hexadecimal | `0x7fff5fbff7ac` |
| `%d` | Decimal (base 10) number | `42` |
| `%i` | Integer in base 10 | `-42` |
| `%u` | Unsigned decimal number | `4294967295` |
| `%x` | Hexadecimal (lowercase) | `2a` |
| `%X` | Hexadecimal (uppercase) | `2A` |
| `%%` | Percent sign | `%` |

### Function Prototype

```c
int ft_printf(const char *format, ...);
```

### Return Value

Returns the number of characters printed (excluding the null byte), just like the original printf.

---

## ⭐ Bonus Features

If the mandatory part is perfect, you can implement:

### Format Flags

- `-` : Left-justify within the given field width
- `0` : Zero-padding for numeric types
- `.` : Precision for numbers and strings
- `#` : Alternate form (0x for hex, 0 for octal)
- ` ` : Space flag for positive numbers
- `+` : Always show sign for numbers

### Field Width & Precision

```c
ft_printf("%10s", "hello");     // "     hello"
ft_printf("%-10s", "hello");    // "hello     "
ft_printf("%.3s", "hello");     // "hel"
ft_printf("%5.3d", 42);         // "  042"
```

---

## 🚀 Getting Started

### Prerequisites

- `gcc` or `clang`
- `make`
- A UNIX-based system (Linux, macOS)

### Installation

```bash
# Clone the repository
git clone https://github.com/medob6/ft_printf.git
cd ft_printf

# Compile the library
make

# This creates libftprintf.a
```

### Compilation Flags

The project compiles with:
```bash
-Wall -Wextra -Werror
```

---

## 💻 Usage

### Basic Usage

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello, %s!\n", "World");
    ft_printf("Characters printed: %d\n", len);
    
    return (0);
}
```

### Compile Your Program

```bash
# Compile with ft_printf
gcc main.c libftprintf.a -I. -o my_program

# Run
./my_program
```

---

## 📝 Examples

### Character and String Output

```c
ft_printf("Character: %c\n", 'A');
// Output: Character: A

ft_printf("String: %s\n", "Hello 42!");
// Output: String: Hello 42!

ft_printf("Null string: %s\n", NULL);
// Output: Null string: (null)
```

### Numbers

```c
ft_printf("Decimal: %d\n", 42);
// Output: Decimal: 42

ft_printf("Negative: %d\n", -42);
// Output: Negative: -42

ft_printf("Unsigned: %u\n", 4294967295);
// Output: Unsigned: 4294967295
```

### Hexadecimal

```c
ft_printf("Hex (lower): %x\n", 255);
// Output: Hex (lower): ff

ft_printf("Hex (upper): %X\n", 255);
// Output: Hex (upper): FF
```

### Pointers

```c
int n = 42;
ft_printf("Address: %p\n", &n);
// Output: Address: 0x7ffd5e8c4a4c

ft_printf("NULL pointer: %p\n", NULL);
// Output: NULL pointer: 0x0 (or (nil) depending on implementation)
```

### Multiple Conversions

```c
ft_printf("Name: %s, Age: %d, Grade: %c\n", "John", 25, 'A');
// Output: Name: John, Age: 25, Grade: A
```

### Percent Sign

```c
ft_printf("Percentage: 100%%\n");
// Output: Percentage: 100%
```

---

## 🏗️ Project Structure

```
ft_printf/
├── 📄 Makefile              # Build automation
├── 📄 ft_printf.h           # Header file
├── 📄 ft_printf.c           # Main function
├── 📁 src/                  # Source files
│   ├── ft_print_char.c      # Character handler
│   ├── ft_print_str.c       # String handler
│   ├── ft_print_ptr.c       # Pointer handler
│   ├── ft_print_nbr.c       # Number handler
│   ├── ft_print_unsigned.c  # Unsigned handler
│   ├── ft_print_hex.c       # Hexadecimal handler
│   └── ft_utils.c           # Helper functions
├── 📁 bonus/                # Bonus features (if implemented)
└── 📄 libftprintf.a         # Compiled library
```

---

## 🔨 Makefile Targets

```bash
make          # Compile the mandatory part
make bonus    # Compile with bonus features
make clean    # Remove object files
make fclean   # Remove object files and library
make re       # Recompile everything
```

---

## 🧪 Testing

### Manual Testing

Create a test file:

```c
#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ft_len;
    int std_len;

    // Test character
    ft_len = ft_printf("ft : %c\n", 'A');
    std_len = printf("std: %c\n", 'A');
    printf("ft_printf: %d, printf: %d\n\n", ft_len, std_len);

    // Test string
    ft_len = ft_printf("ft : %s\n", "Hello World");
    std_len = printf("std: %s\n", "Hello World");
    printf("ft_printf: %d, printf: %d\n\n", ft_len, std_len);

    // Test numbers
    ft_len = ft_printf("ft : %d\n", -42);
    std_len = printf("std: %d\n", -42);
    printf("ft_printf: %d, printf: %d\n\n", ft_len, std_len);

    // Test hex
    ft_len = ft_printf("ft : %x\n", 255);
    std_len = printf("std: %x\n", 255);
    printf("ft_printf: %d, printf: %d\n\n", ft_len, std_len);

    return (0);
}
```

Compile and run:
```bash
gcc test.c libftprintf.a -I. -o test
./test
```

### Automated Testers

Popular ft_printf testers:

```bash
# Tripouille's printf tester
git clone https://github.com/Tripouille/printfTester.git
cd printfTester
make m  # Test mandatory
make b  # Test bonus

# Paulo Santana's tester
git clone https://github.com/paulo-santana/ft_printf_tester.git
cd ft_printf_tester
make test
```

---

## 🎓 Key Concepts

### 1. Variadic Functions

```c
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    int count;

    va_start(args, format);
    // Process format string
    // Use va_arg(args, type) to get arguments
    count = process_format(format, args);
    va_end(args);

    return (count);
}
```

### 2. Format String Parsing

```c
while (*format)
{
    if (*format == '%')
    {
        format++;
        count += handle_conversion(*format, args);
    }
    else
        count += ft_putchar(*format);
    format++;
}
```

### 3. Type Handling

```c
int handle_conversion(char specifier, va_list args)
{
    if (specifier == 'c')
        return (print_char(va_arg(args, int)));
    else if (specifier == 's')
        return (print_string(va_arg(args, char *)));
    else if (specifier == 'd' || specifier == 'i')
        return (print_int(va_arg(args, int)));
    // ... more conversions
}
```

---

## 💡 Implementation Tips

### Character Output
```c
int ft_putchar(char c)
{
    return (write(1, &c, 1));
}
```

### String Output
```c
int ft_putstr(char *s)
{
    int i;

    if (!s)
        return (ft_putstr("(null)"));
    i = 0;
    while (s[i])
        ft_putchar(s[i++]);
    return (i);
}
```

### Number to Hex Conversion
```c
void ft_putnbr_hex(unsigned int n, char format)
{
    char *base;

    if (format == 'x')
        base = "0123456789abcdef";
    else
        base = "0123456789ABCDEF";
    
    if (n >= 16)
        ft_putnbr_hex(n / 16, format);
    ft_putchar(base[n % 16]);
}
```

### Pointer Handling
```c
int ft_print_ptr(void *ptr)
{
    int count;

    count = 0;
    if (!ptr)
        return (ft_putstr("(nil)"));
    count += ft_putstr("0x");
    count += ft_putnbr_hex((unsigned long)ptr, 'x');
    return (count);
}
```

---

## 🐛 Common Pitfalls

⚠️ **NULL String** - Handle `ft_printf("%s", NULL)` → should print `(null)`

⚠️ **Return Value** - Always return the correct number of characters printed

⚠️ **va_arg Type** - `char` is promoted to `int` in variadic functions

⚠️ **Pointer NULL** - Handle `ft_printf("%p", NULL)` correctly

⚠️ **Memory Management** - Don't leak memory (use valgrind)

⚠️ **Edge Cases** - Test with `INT_MIN`, `INT_MAX`, empty strings, etc.

---

## 📊 Evaluation Checklist

### Before Defense

- [ ] Code follows the Norm
- [ ] No forbidden functions used
- [ ] Makefile doesn't relink
- [ ] No memory leaks (test with valgrind)
- [ ] All mandatory conversions work
- [ ] Return value is correct
- [ ] Handles edge cases properly

### Norm Check

```bash
norminette *.c *.h
```

### Memory Check

```bash
valgrind --leak-check=full ./test_program
```

---

## 📚 Resources

### Understanding printf
- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic Functions in C](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html)
- [stdarg.h documentation](https://en.cppreference.com/w/c/variadic)

### Learning Materials
- [42 Docs - ft_printf](https://harm-smits.github.io/42docs/projects/ft_printf)
- [Understanding va_arg](https://www.cprogramming.com/tutorial/c/lesson17.html)

### Video Tutorials
- [Variadic Functions Explained](https://www.youtube.com/watch?v=S-ak715zIf4)
- [How printf Works](https://www.youtube.com/watch?v=cIIyiO3fgJg)

---

## 🎯 Bonus Ideas

If you've completed the mandatory part:

1. **Field Width** - `%10s`, `%5d`
2. **Precision** - `%.5s`, `%.3d`
3. **Flags** - `-`, `0`, `+`, ` `, `#`
4. **More Conversions** - `%o` (octal), `%b` (binary)
5. **Color Output** - ANSI color codes
6. **Buffer Optimization** - Reduce write() calls

---

## 🤝 Contributing

Found a bug or have a suggestion?

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/improvement`)
3. Commit your changes (`git commit -m 'Fix: handle edge case'`)
4. Push to the branch (`git push origin feature/improvement`)
5. Open a Pull Request

---

## 📜 License

This project is part of the 42 School curriculum.

---

## 👤 Author

**medob6**

- GitHub: [@medob6](https://github.com/medob6)
- 42 Intra: `medob6`

---

## 🙏 Acknowledgments

- **42 Network** for this challenging and educational project
- **Fellow cadets** for code reviews and debugging sessions
- **The C standard library** for being the gold standard

---

<div align="center">

**💪 May your printf never crash!**

*"Understanding printf is understanding variadic functions"*

⭐ Star this repo if it helped you with your own ft_printf!

</div>
