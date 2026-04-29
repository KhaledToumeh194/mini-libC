# Mini libc

A minimal C standard library implemented from scratch in C, built as part of the Operating Systems course at POLITEHNICA Bucharest.

## Overview

Re-implementation of core C standard library functions focusing on pointer arithmetic, memory safety, and low-level system call usage.

## Implemented Functions

- **String operations** — `strlen`, `strcpy`, `strcat`, `strcmp`, `strncpy`, `strncat`, `strncmp`, `strchr`, `strrchr`, `strstr`
- **Memory operations** — `memcpy`, `memmove`, `memset`, `memcmp`, `memchr`
- **I/O operations** — `puts`, `putchar`, `getchar`, `printf` (basic)
- **Memory allocation** — `malloc`, `free`, `calloc`, `realloc` using `mmap`/`brk` syscalls
- **Process control** — `exit`, `abort`
- **Environment** — `getenv`, `setenv`

## Key Concepts

- Direct **Linux system calls** via `syscall()` — no libc dependency
- Manual **pointer arithmetic** throughout
- Careful **memory safety** and bounds checking
- Compiled with `-nostdlib` — runs without any standard library

## Technologies

- C, x86-64 assembly (syscall interface), Linux system calls, POSIX
