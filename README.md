
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

## Testing, evaluating
I submitted the project 3 times and failed in these things
#### Mandatory
- **empty path** - `unset PATH` - code can't segfault after unsetting path
- **NULL parameters** - `./pipex in cat "" out` - should be handled correctly
- **error messages** - correct error messages - no file, no permissions, cmd not found
- **nonsense input** - `./pipex a a a a` or `./pipex a b c d` - especially for handling the error messages correctly
- **Makefile** - all makefile targets should work on their own without failing
#### Bonus
- **heredoc limiter** - if you end your heredoc file with `LIMITERLIMITER` it shouldn't end
- **middle command, no permissions** - `./pipex infile cat "rm -f file" cat outfile` - the `rm` should be executed even if `infile` and `outfile` don't have the correct permissions
#### Things you should also test
- **protection** - functions like `ft_split`, `ft_strdup`, `execve`, `dup2` should be protected, and after some of them you need to exit the program properly
- **random file** - `./pipex /dev/random cat "head -1" outfile`
- **norminette**
- **valgrind**
- **scan-build-12 make re**
- possibly **funcheck**
