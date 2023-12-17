/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:41:26 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/17 14:20:23 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//redirect input to stdin and output to stdout
//close input and output fds of all other unused pipes in current process
void	redirect(t_pipex pipex, int input, int output)
{
	if (dup2(input, STDIN_FILENO) == -1)
	{
		close_pipes(&pipex);
		free_pipex(&pipex);
		exit(1);
	}
	close(input);
	if (dup2(output, STDOUT_FILENO) == -1)
	{
		close_pipes(&pipex);
		free_pipex(&pipex);
		exit(1);
	}
	close(output);
}

//handling different kinds of child processes, first, middle, last
void	children(t_pipex pipex, int i)
{
	if (!pipex.cmds[i].found)
	{
		close_pipes(&pipex);
		free_pipex(&pipex);
		exit(1);
	}
	ft_putstr_fd(pipex.cmds[i].args[0], 2);
	if (i == 0)
		child(pipex, i, pipex.infile, pipex.pipes[i][1]);
	else if (i != pipex.size - 1 - pipex.heredoc)
		child(pipex, i, pipex.pipes[i - 1][0], pipex.pipes[i][1]);
	else
		child(pipex, i, pipex.pipes[i - 1][0], pipex.outfile);
}

//handle child processes, execute commands, else error message
void	child(t_pipex pipex, int i, int input, int output)
{
	redirect(pipex, input, output);
	close_pipes(&pipex);
	if (execve(pipex.cmds[i].path, pipex.cmds[i].args, pipex.envp) == -1)
	{
		free_pipex(&pipex);
		error_message(NULL);
	}
	exit(1);
}
