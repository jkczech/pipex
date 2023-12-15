/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:23:11 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/15 13:35:43 by jkoupy           ###   ########.fr       */
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
	pipex->cmds[i].path = NULL;
	free(command);
	return (false);
}

//iterate through commands in pipex.cmd, and searches for paths
bool	find_commands(t_pipex *pipex)
{
	char	*command;
	int		i;
	int		j;

	i = -1;
	while (i++ < pipex->size - 1)
	{
		if (pipex->cmds[i].args[0]
			&& is_command(pipex, ft_strdup(pipex->cmds[i].args[0]), i))
			break ;
		j = 0;
		while (pipex->paths[j])
		{
			command = ft_strjoin3(pipex->paths[j],
					"/", pipex->cmds[i].args[0]);
			if (!command)
				continue ;
			if (is_command(pipex, command, i))
				break ;
			j++;
			if (!pipex->paths[j])
				cmd_not_found(pipex, i);
		}
	}
	return (true);
}

//find PATH in environment variables and saves it into pipex
bool	find_paths(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->envp && pipex->envp[i]
		&& ft_strncmp(pipex->envp[i], "PATH", 4) != 0)
		i++;
	pipex->paths = ft_split(pipex->envp[i] + 5, ':');
	if (!pipex->paths)
		return (false);
	return (true);
}

bool	open_files(t_pipex *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		if (access(argv[1], F_OK) != 0)
			no_such_file(argv[1]);
		else if (access(argv[1], R_OK) != 0)
			permission_denied(argv[1]);
		else
			ft_putstr_fd("Error: infile undefined\n", 2);
	}
	pipex->outfile = open(argv[pipex->size + 2],
			O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->outfile == -1)
	{
		if (access(argv[pipex->size + 2], R_OK) != 0)
			permission_denied(argv[pipex->size + 2]);
		else
			ft_putstr_fd("Error: outfile undefined\n", 2);
		return (true);
	}
	return (true);
}

//read all the commands, infile, outfile, opens fd's for files
//return value: if any error false at first error, else true
bool	parse_input(t_pipex *pipex, char **argv)
{
	int	i;

	pipex->cmds = malloc(pipex->size * sizeof(t_cmd));
	if (!pipex->cmds)
		return (false);
	i = 0;
	while (i < pipex->size)
	{
		pipex->cmds[i].found = false;
		pipex->cmds[i].args = ft_split(argv[i + 2], ' ');
		if (!pipex->cmds[i].args)
			return (false);
		i++;
	}
	if (!find_paths(pipex))
		return (false);
	if (!open_files(pipex, argv))
		return (false);
	if (!find_commands(pipex))
		return (false);
	return (true);
}
