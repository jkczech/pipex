
# Pipex

A project from 42 Vienna focusing on process, pipe and file management.

This project is about handling pipes.
## Requirements
|||
|----------|----------|
|Program name | pipex, pipex_bonus|
| Turn in files | Makefile, *.h, *.c |
|Makefile | NAME, all, clean, fclean, re |
|Arguments | file1 cmd1 cmd2 file2 |
|External functs | open, close, read, write, malloc, free, perror, <br>strerror, access, dup, dup2, execve, exit, fork,<br>pipe, unlink, wait, waitpid, ft_printf |
|Libft authorized | Yes



The program is executed as follows:
`./pipex file1 cmd1 cmd2 file2`

It takes 4 arguments:
- `file1` and `file2` are file names
- `cmd1` and `cmd2` are shell commands with their parameters

It behaves the same as the shell command below:

- `$> < file1 cmd1 \| cmd2 > file2`
