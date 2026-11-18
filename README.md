# minicoreutils

> From-scratch `cat`, `echo` and `grep` in C, using nothing but the standard library.

![Language](https://img.shields.io/badge/Language-C-blue)
![Platform](https://img.shields.io/badge/Platform-Windows%20%7C%20Linux-green)
![Scope](https://img.shields.io/badge/Scope-Coreutils%20Subset-lightgrey)

## Overview

Three single-file utilities, one directory each. The point is to get file I/O, `argv` walking and line buffers down by hand before bigger systems work.

## How They Work

```mermaid
flowchart TB
    args["next file in argv"] --> open{"fopen ok?"}
    open -->|"no"| err["print error,<br/>skip the file"]
    open -->|"yes"| read["cat: fgetc → stdout<br/>grep: fgets 2048 bytes, strstr hit → print"]
    err --> args
    read --> args
```

`cat` and `grep` share this loop. `echo` opens no files: it prints its arguments, without the newline if the first one is `-n`.

| Program | Mirrors | Notes |
|---|---|---|
| `cat/cat.c` | `cat` | Streams each file a character at a time; a missing file is skipped, not fatal |
| `echo/echo.c` | `echo` | Space-separated args; `-n` drops the newline |
| `grep/grep.c` | `grep` | Plain substring match (`strstr`), no regex |

**Left out on purpose:** line numbers, recursion, case-insensitivity.
**Differences from GNU:** errors go to stdout, `cat` with no files doesn't read stdin, and `grep` splits lines longer than 2,047 characters.

## Build

```bash
gcc cat/cat.c -o cat && ./cat file.txt
gcc echo/echo.c -o echo && ./echo -n hello world
gcc grep/grep.c -o grep && ./grep search_term file.txt
```

**Codemap:** [CODEMAP.md](CODEMAP.md), the files, hub functions and call graph, generated from the code.

---
*powered by logic, coffee, and many sleepless nights*
