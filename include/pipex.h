/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:27:19 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/05 09:28:41 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../library/printf/include/ft_printf.h"
# include "../library/libft/include/libft.h"

# include <fcntl.h>		//open, close, read, write
# include <stdlib.h>	//malloc, free
# include <stdio.h>		//perror
# include <string.h>	//strerror
# include <unistd.h>	//access, dup, dup2, execve, exit, fork, pipe, unlink
# include <sys/wait.h>	//wait, waitpid
# include <stdbool.h>	//true, false
# include <errno.h>		//errno
# include <error.h>

typedef struct s_cmd
{
	char	*path;
	char	**args;
}	t_cmd;

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		size;
	t_cmd	*cmds;
	int		**pipes;
	char	**paths;
	char	**envp;
	int		*child_pids;
	bool	skip_first;
}	t_pipex;

//main.c

bool	create_pipes(t_pipex *pipex);
bool	wait_pids(t_pipex pipex);
bool	execute(t_pipex pipex);
int		main(int argc, char **argv, char **envp);

//parse.c

bool	find_paths(t_pipex *pipex, char **envp);
bool	parse_input(t_pipex *pipex, char **argv, char **envp);
bool	find_commands(t_pipex *pipex);
bool	is_command(t_pipex *pipex, char *command, int i);

//print.c

void	print_pipex(t_pipex pipex);
void	print_array(char *name, char **array);

//free.c

bool	free_pipex(t_pipex *pipex);
bool	free_array(char **array);
bool	close_pipes(t_pipex *pipex);

//child.c

bool	child(t_pipex pipex, int i);
bool	first_child(t_pipex pipex, int i);
bool	middle_child(t_pipex pipex, int i);
bool	last_child(t_pipex pipex, int i);

//error.c

bool	error_message(void);

#endif
