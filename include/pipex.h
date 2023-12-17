/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:27:19 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/17 18:08:51 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../library/libft/include/libft.h"
# include "../library/get_next_line/include/get_next_line.h"

# include <fcntl.h>		//open, close, read, write
# include <stdlib.h>	//malloc, free
# include <stdio.h>		//perror
# include <string.h>	//strerror
# include <unistd.h>	//access, dup, dup2, execve, exit, fork, pipe, unlink
# include <sys/wait.h>	//wait, waitpid
# include <stdbool.h>	//true, false
# include <errno.h>		//errno
# include <error.h>

# include "structures.h"

//child.c

void	redirect(t_pipex pipex, int input, int output);
void	children(t_pipex pipex, int i);
void	child(t_pipex pipex, int i, int input, int output);

//error.c

void	error_message(char *file);
void	cmd_not_found(t_pipex *pipex, int i);

//free.c

bool	close_pipes(t_pipex *pipex);
bool	free_pipex(t_pipex *pipex);
bool	free_array(char **array);

//here_doc_bonus.c

void	open_here_doc(t_pipex *pipex);
void	here_doc(t_pipex *pipex);

//main.c or main_bonus.c

bool	parse_input(t_pipex *pipex);
int		main(int argc, char **argv, char **envp);

//parse.c

bool	is_command(t_pipex *pipex, char *command, int i);
void	find_command(t_pipex *pipex, int i);
bool	find_paths(t_pipex *pipex);
void	open_files(t_pipex *pipex);

//pipex.c

bool	create_pipes(t_pipex *pipex);
bool	wait_pids(t_pipex *pipex);
bool	allocate_pids(t_pipex *pipex);
bool	execute(t_pipex *pipex);
bool	pipex_init(t_pipex *pipex, int argc, char **argv, char **envp);

#endif
