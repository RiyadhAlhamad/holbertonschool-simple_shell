# Simple Shell

## Description

This project is a simple UNIX command-line interpreter built as part of the Holberton School curriculum.  
The shell mimics basic behavior of standard shells like `sh` or `bash`, with incremental improvements in each task.

## Features

This shell includes the following capabilities:

- **Prompt Display**: Shows a custom prompt and waits for user input.
- **Command Execution**:
  - Executes commands with or without arguments.
  - Uses `fork`, `execve`, `wait`, and related system calls.
- **Error Handling**:
  - Prints errors if the command is not found.
  - Handles end-of-file (EOF) with `Ctrl+D`.
- **Built-in Commands**:
  - `exit`: Terminates the shell.
  - `env`: Prints the current environment variables.
- **PATH Resolution**: Finds commands using the system PATH.

## Getting Started

## Project Structure

| File                 | Description                                      |
|----------------------|--------------------------------------------------|
| `main.c`             | Entry point of the shell, contains main loop     |
| `builtins.c`         | Implements built-in commands like `exit`, `env`  |
| `execute.c`          | Handles command execution using `fork` and `execve` |
| `parse_input.c`      | Tokenizes and parses user input                  |
| `path.c`             | Resolves the full path of commands               |
| `shell.h`            | Header file with function prototypes and macros  |
| `man_1_simple_shell` | Manual page for the shell (man page)             |
| `README.md`          | Project documentation                            |
| `AUTHORS`            | List of project contributors                     |



### Compilation
Use the following command to compile:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell

$ ./simple_shell
$ ls -l
$ /bin/ls
$ env
$ exit

