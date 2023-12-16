/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:27:19 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/16 12:36:03 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	bool	found;
	char	*path;
	char	**args;
}	t_cmd;

typedef struct s_pipex
{
	int		size;
	int		infile;
	int		outfile;
	t_cmd	*cmds;
	int		**pipes;
	char	**paths;
	char	**argv;
	char	**envp;
	int		*child_pids;
}	t_pipex;

//main.c or main_bonus.c

int		main(int argc, char **argv, char **envp);

//pipex.c

bool	create_pipes(t_pipex *pipex);
bool	wait_pids(t_pipex pipex);
bool	execute(t_pipex pipex);
bool	allocate_pids(t_pipex *pipex);
bool	pipex_init(t_pipex *pipex, int argc, char **argv, char **envp);

//parse.c

bool	is_command(t_pipex *pipex, char *command, int i);
bool	find_commands(t_pipex *pipex);
bool	find_paths(t_pipex *pipex);
void	open_files(t_pipex *pipex);
bool	parse_input(t_pipex *pipex);

//free.c

bool	free_pipex(t_pipex *pipex);
bool	free_array(char **array);
bool	close_pipes(t_pipex *pipex);

//child.c

void	redirect(t_pipex pipex, int input, int output);
void	children(t_pipex pipex, int i);
void	child(t_pipex pipex, int i, int input, int output);

//error.c

void	error_message(char *file);
void	cmd_not_found(t_pipex *pipex, int i);
void	permission_denied(char *file);
void	no_such_file(char *file);

#endif
