/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:41:26 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/30 16:07:39 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//handles first child process, connects to infile
bool	first_child(t_pipex pipex, int i)
{
	dup2(pipex.pipes[i][0], pipex.infile);
	close(pipex.infile);
	dup2(pipex.pipes[i + 1][0], pipex.pipes[i][1]);
	close(pipex.pipes[i][1]);
	execve(pipex.cmds[i].path, pipex.cmds[i].args, pipex.envp);
	return (true);
}

//handles middle child processes connecting the previous pipe
bool	middle_child(t_pipex pipex, int i)
{
	dup2(pipex.pipes[i - 1][0], pipex.pipes[i][0]);
	close(pipex.pipes[i][0]);
	dup2(pipex.pipes[i + 1][0], pipex.pipes[i][1]);
	close(pipex.pipes[i][1]);
	execve(pipex.cmds[i].path, pipex.cmds[i].args, pipex.envp);
	return (true);
}

//handles last child process, connects to outfile
bool	last_child(t_pipex pipex, int i)
{
	dup2(pipex.pipes[i - 1][0], pipex.pipes[i][0]);
	close(pipex.pipes[i][0]);
	dup2(pipex.outfile, pipex.pipes[i][1]);
	close(pipex.pipes[i][1]);
	execve(pipex.cmds[i].path, pipex.cmds[i].args, pipex.envp);
	return (true);
}
