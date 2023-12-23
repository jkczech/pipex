/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:23:11 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/23 19:13:29 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//check if command is valid, if so, saves it into pipex
bool	is_command(t_pipex *pipex, char *command, int i)
{
	if (!command)
		return (false);
	if (access(command, F_OK) == 0 && ft_strncmp(command, "/", 1) == 0)
	{
		pipex->cmds[i].path = ft_strdup(command);
		if (!pipex->cmds[i].path)
			return (false);
		free(command);
		pipex->cmds[i].found = true;
		return (true);
	}
	free(command);
	return (false);
}

//search for command in pipex.cmd[i], and search for path
void	find_command(t_pipex *pipex, int i)
{
	char	*command;
	int		j;

	if (pipex->cmds[i].args[0]
		&& is_command(pipex, ft_strdup(pipex->cmds[i].args[0]), i))
		return ;
	j = 0;
	if (!pipex->paths)
		return (cmd_not_found(pipex, i));
	while (pipex->paths[j])
	{
		command = ft_strjoin3(pipex->paths[j],
				"/", pipex->cmds[i].args[0]);
		if (is_command(pipex, command, i))
			break ;
		j++;
		if (!pipex->paths[j])
			cmd_not_found(pipex, i);
	}
}

//find PATH in environment variables and saves it into pipex
void	find_paths(t_pipex *pipex)
{
	int	i;

	i = 0;
	if (!pipex->envp)
		return ;
	while (pipex->envp[i] && ft_strncmp(pipex->envp[i], "PATH", 4) != 0)
		i++;
	if (pipex->envp[i] && ft_strncmp(pipex->envp[i], "PATH", 4) == 0)
		pipex->paths = ft_split(pipex->envp[i] + 5, ':');
}

//open infile and outfile, show errors respectively
void	open_files(t_pipex *pipex)
{
	pipex->infile = open(pipex->argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		if (access(pipex->argv[1], F_OK) != 0)
			error_message(pipex->argv[1]);
		else if (access(pipex->argv[1], R_OK) != 0)
			error_message(pipex->argv[1]);
		else
			ft_putstr_fd(ERR_IN, 2);
	}
	pipex->outfile = open(pipex->argv[pipex->size + 2],
			O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->outfile == -1)
	{
		if (access(pipex->argv[pipex->size + 2], W_OK) != 0)
			error_message(pipex->argv[pipex->size + 2]);
		else
			ft_putstr_fd(ERR_OUT, 2);
	}
}

//read all the commands, infile, outfile, opens fd's for files
//return value: if any error false at first error, else true
bool	parse_input(t_pipex *pipex)
{
	int	i;

	find_paths(pipex);
	if (pipex->heredoc)
		open_here_doc(pipex);
	else
		open_files(pipex);
	i = 0;
	while (i < pipex->size)
	{
		pipex->cmds[i].found = false;
		pipex->cmds[i].args = \
			ft_split(pipex->argv[i + 2 + pipex->heredoc], ' ');
		if (!pipex->cmds[i].args)
			return (false);
		if (!(i == 0 && pipex->infile == -1)
			&& !(i == pipex->size - 1 && pipex->outfile == -1))
			find_command(pipex, i);
		i++;
	}
	return (true);
}
