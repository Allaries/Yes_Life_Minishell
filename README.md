*This project has been created as part
of the 42 curriculum by \<rerichar\> and \<smedenec\>.*

# Minishell

*This project has been created as part of the 42 curriculum by <rerichar> and <smedenec>.*

## Description

**Minishell** is a project that aims to recreate a simplified version of a Unix shell.

The goal is to understand how a shell works internally by implementing core features such as:
- Command parsing and execution
- Environment variable handling
- Input/output redirections
- Pipes
- Built-in commands

This project provides a hands-on introduction to process management, file descriptors, and system calls in C.

---

## Instructions

### Compilation

In the project directory, run:

```bash
make
```

This will generate the executable `minishell`.

To remove object files:

```bash
make clean
```

To remove everything (including the executable):

```bash
make fclean
```

To recompile from scratch:

```bash
make re
```

---

### Execution

Run the program with:

```bash
./minishell
```

A prompt will appear, allowing you to enter commands like in a standard shell.

---

## Usage

### Basic Commands

```bash
ls
pwd
echo hello
```

### Commands with Arguments

```bash
ls -la
echo hello world
```

### Environment Variables

```bash
echo $HOME
echo $PATH
```

### Exit Status

```bash
echo $?
```

---

## Pipes

Chain multiple commands together:

```bash
ls | grep .c | wc -l
```

---

## Redirections

### Output Redirection

```bash
echo hello > file.txt
```

### Append Output

```bash
echo hello >> file.txt
```

### Input Redirection

```bash
cat < file.txt
```

### Heredoc

```bash
cat << EOF
text
EOF
```

---

## Quotes

### Single Quotes

Prevent interpretation:

```bash
echo '$HOME'
```

### Double Quotes

Allow variable expansion:

```bash
echo "$HOME"
```

### No Quotes

Allow variable expansion:

```bash
echo $HOME
```

---

## Builtins

### echo

```bash
echo hello
```

### cd

```bash
cd /path/to/directory
```

### pwd

```bash
pwd
```

### export

```bash
export VAR=value
```

### unset

```bash
unset VAR
```

### env

```bash
env
```

### exit

```bash
exit
```

---

## Signals

- `Ctrl+C`: Interrupts the current command
- `Ctrl+D`: Exits the shell
- `Ctrl+\`: Ignored

---

## Example

```bash
./minishell
minishell$ echo hello | grep h > out.txt
minishell$ cat out.txt
hello
```

---

## Resources

### Documentation

- Unix manual pages (`man bash`, `man execve`, `man fork`, `man pipe`)
- The Open Group Base Specifications (POSIX)
- GNU Bash documentation

### Tutorials

- Shell implementation guides
- Process and file descriptor management in C
- Parsing techniques in C

### AI Usage

Artificial Intelligence tools were used in this project for:
- Understanding complex concepts such as parsing and process management
- Debugging specific issues
- Improving code structure and readability

All core logic, implementation, and validation were developed by the authors.

---

## Notes

- The behavior is inspired by Bash but remains simplified
- Advanced features are not supported
- In case of error, a message is displayed and the shell continues running
