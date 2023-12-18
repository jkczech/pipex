
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


## Mandatory part

Create program by `make` in the `build` folder.
The program is executed as follows:

`$> ./pipex file1 cmd1 cmd2 file2`

It takes 4 arguments:
- `file1` and `file2` are file names
- `cmd1` and `cmd2` are shell commands with their parameters

It behaves the same as the shell command below:

- `$> < file1 cmd1 | cmd2 > file2`


## Bonus part

Create program by `make bonus` in the `build` folder.
### Handle multiple pipes
The program is executed as follows:

`$> ./pipex_bonus file1 cmd1 cmd2 cmd3 ... cmdn file2`

Behaves like this:

`$> < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`

It takes at least 4 arguments:
- `file1` and `file2` input and output file names
- `cmd1` to `cmdn` are shell commands with their parameters


### Support « and » when the first parameter is "here_doc"
The program is executed as follows:

`$> ./pipex_bonus here_doc LIMITER cmd cmd1 file`

Behaves like this:

`$> cmd << LIMITER | cmd1 >> file`


It takes at least 4 arguments:
- `here_doc` this specific string will open stdin for user given input
- `LIMITER` string that will close the input
- `cmd`, `cmd1` are shell commands with their parameters
- `file` output file
