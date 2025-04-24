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

### Compilation
Use the following command to compile:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o simple_shell

$ ./simple_shell
$ ls -l
$ /bin/ls
$ env
$ exit

## Project Structure
| File        | Description                         |
|-------------|-------------------------------------|
| `shell.c`   | Main loop for the shell             |
| `exec.c`    | Handles command execution with `execve` |
| `fork.c`    | Forks the process                   |
| `prompt.c`  | Displays the prompt                 |
| `stat.c`    | Handles command validation          |
| `wait.c`    | Handles process waiting             |
| `env-main.c`, `printenv.c` | Prints environment   |

