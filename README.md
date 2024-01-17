
# Pipex

A project from 42 Vienna focused on processes, pipe and file management.

This project is about **pipes**.

Following information and the code in this repository is made for inspiration and help for students working on this project. 

*If you copy any part of the code, you only cheat yourself because you will learn nothing. Get just inspired instead.*
![Pipe](https://external-content.duckduckgo.com/iu/?u=http%3A%2F%2Fclipart-library.com%2Fimage_gallery%2F266597.png&f=1&nofb=1&ipt=4aa21f4b81e90ebae456d605913ea37b1f998f2294fd89f4c2b3447b89116176&ipo=images)

## Requirements
|||
|----------|----------|
|Program name | pipex, pipex_bonus|
| Turn in files | Makefile, *.h, *.c |
|Makefile | NAME, all, clean, fclean, re |
|Arguments | file1 cmd1 cmd2 file2 |
|External allowed<br>functions | open, close, read, write, malloc, free, perror, <br>strerror, access, dup, dup2, execve, exit, fork,<br>pipe, unlink, wait, waitpid, ft_printf *(prev. project)* |
|Libft authorized | Yes *(also prev. project - set of useful functions)*

The project must comply with the following rules:
- You must turn in a Makefile that will compile your source files. It must not relink.
- You have to handle errors thoroughly. In any way, your program shouldn't quit unexpectedly (segmentation fault, bus error, double free, and so forth).
- Your program can't have memory leaks.
- If you have any doubt, handle the errors like the shell command: `$> < file1 cmd1 | cmd2 > file2`

## Mandatory part

Create a program by `make` in the `build` folder.
The program execution is as follows:

`$> ./pipex file1 cmd1 cmd2 file2`

It takes four arguments:
- `file1` and `file2` are file names
- `cmd1` and `cmd2` are shell commands with their parameters

It behaves the same as the shell command below:

- `$> < file1 cmd1 | cmd2 > file2`


## Bonus part

Create a program by `make bonus` in the `build` folder.
### Handle multiple pipes
The program execution is as follows:

`$> ./pipex_bonus file1 cmd1 cmd2 cmd3 ... cmdn file2`

Behaves like this:

`$> < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2`

It takes at least four arguments:
- `file1` and `file2` input and output file names
- `cmd1` to `cmdn` are shell commands with their parameters


### Support « and » when the first parameter is "here_doc"
The program execution is as follows:

`$> ./pipex_bonus here_doc LIMITER cmd cmd1 file`

Behaves like this:

`$> cmd << LIMITER | cmd1 >> file`


It takes at least four arguments:
- `here_doc` this specific string will open stdin for the user-given input
- `LIMITER` string that will close the input
- `cmd` and `cmd1` are shell commands with their parameters
- `file` output file

## Testing, evaluating
I submitted the project four times and failed in some of these things
#### Mandatory
- **empty path** - `unset PATH` - code can't segfault after unsetting path
- **NULL parameters** - `./pipex in cat "" out` - should be handled correctly
- **error messages** - correct error messages - no file, no permissions, cmd not found
- **nonsense input** - `./pipex a a a a` or `./pipex a b c d` - especially for handling the error messages correctly
- **Makefile** - all makefile targets should work on their own without failing

#### Bonus
- **heredoc limiter** - if you end your heredoc file with `LIMITERLIMITER` it shouldn't end
- **CTRL + D** - EOF ending the heredoc instead of the `LIMITER`
- **middle command, no permissions** - `./pipex infile cat "rm -f file" cat outfile` the `rm` should be executed even if `infile` and `outfile` don't have the correct permissions
- **exitcode** - differs outfile has no permissions (1), last command doesn't exist (127), correct last process and outfile (0), the way to acces exitcode is `echo $?` after execution of the program (not sure if exitcode handling is necessary here but some evaluators check that and it will be required in minishell)

#### Things you should also test
- **protection** - functions like `fork`, `pipe`, `ft_split`, `ft_strdup`, `execve`, and `dup2` should be protected, and after some of them, you need to exit the program properly
- **random file** - `./pipex /dev/random cat "head -1" outfile`
- **norminette**
- **valgrind** - make sure to use flags too especially `--track-fds=all --trace-children=yes`, at the end of the execution, only three std fds are allowed to be open (be aware that in VS Code, there are by default some extra fds open therefore it's better to test this in a shell outside of VS Code)
- **scan-build-12 make re**
- possibly **funcheck**
- **pipex-tester**


## © Copyright
All of the code belongs to me (@jkczech).

The project idea and the requirements belong to 42 Vienna / 42 Network.

If sharing this repository is against the rules of the 42 Network, please let me know, and I will take it down.
