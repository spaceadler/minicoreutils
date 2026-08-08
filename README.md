
# minicoreutils

> Tiny from-scratch rewrites of `cat`, `echo`, and `grep` in C, built to get comfortable with the standard I/O and string libraries before moving on to bigger systems work.

![Language](https://img.shields.io/badge/Language-C-blue)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-green)
![Scope](https://img.shields.io/badge/Scope-Coreutils%20Subset-lightgrey)

## Overview

Three single-file utilities that mirror the basic behavior of their GNU coreutils namesake. No external dependencies beyond the C standard library. The goal is to learn development in an embedded environment as well as learning how memory management works and to get the core file I/O and string-handling patterns down by simply reading a file byte-by-byte, walking `argv`, and scanning line buffers.

## Utilities

| Program | Mirrors | What it does |
|---|---|---|
| `cat.c` | `cat` | Opens each file argument and streams its contents to stdout one character at a time via `fgetc`. |
| `echo.c` | `echo` | Prints its arguments space-separated. Supports `-n` to suppress the trailing newline. |
| `grep.c` | `grep` | Reads each file line-by-line into a fixed 2048-byte buffer and prints any line containing the search term via `strstr`. |

## Notes

- `cat` and `grep` both fail gracefully per-file. The program prints an error if one file in the argument list can't be opened and continues with the rest rather than just exiting.
- `grep` uses a fixed-size line buffer rather than dynamic allocation, so it's a simplified single-substring matcher, not a real regex engine.
- Flags for line numbers, recursion, and case-insensitivity were left out on purpose to keep the first pass focused on plain file I/O.

## Building and Running

Just a standard C compiler (GCC / Clang). Each utility compiles independently.

**Linux / macOS**
```bash
gcc cat.c -o cat
gcc echo.c -o echo
gcc grep.c -o grep
```

**Windows (MinGW / GCC)**
```bash
gcc cat.c -o cat.exe
gcc echo.c -o echo.exe
gcc grep.c -o grep.exe
```

**Usage**
```bash
./cat file.txt
./echo -n hello world
./grep search_term file.txt
```

---
*powered by logic, coffee, and many sleepless nights*
