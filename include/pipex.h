/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:27:19 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/27 14:01:06 by jkoupy           ###   ########.fr       */
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
# include <unistd.h>	//access, dup, dup2, execve, exit
						//fork, pipe, unlink, wait, waitpid
# include <stdbool.h>	//true, false

typedef struct s_cmd
{
	char	*path;
	char	**args;
}	t_cmd;

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		mypipe[2];
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	char	*path;
	int		size;
}	t_pipex;

//main.c
char	*find_path(char **envp);
bool	free_pipex(t_pipex *pipex);
bool	load_input(t_pipex *pipex, char **argv);
bool	find_paths(t_pipex *pipex);

//print.c
void	print_pipex(t_pipex pipex);

#endif