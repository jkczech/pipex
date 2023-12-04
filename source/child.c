/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:41:26 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/04 14:51:57 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	redirect(int left, int right)
{
	dup2(left, 0);
	close(left);
	dup2(right, 1);
	close(right);
}

//handles first child process, connects to infile
bool	first_child(t_pipex pipex, int i)
{
	redirect(pipex.infile, pipex.pipes[i][1]);
	execve(pipex.cmds[i].path, pipex.cmds[i].args, pipex.envp);
	close_pipes(&pipex);
	return (true);
}

//handles middle child processes connecting the previous pipe
bool	middle_child(t_pipex pipex, int i)
{
	redirect(pipex.pipes[i][0], pipex.pipes[i + 1][1]);
	execve(pipex.cmds[i].path, pipex.cmds[i].args, pipex.envp);
	close_pipes(&pipex);
	return (true);
}

//handles last child process, connects to outfile
bool	last_child(t_pipex pipex, int i)
{
	redirect(pipex.pipes[i][0], pipex.outfile);
	execve(pipex.cmds[i].path, pipex.cmds[i].args, pipex.envp);
	close_pipes(&pipex);
	return (true);
}
