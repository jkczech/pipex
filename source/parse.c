/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:23:11 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/09 14:33:28 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//check if command is valid, if so, saves it into pipex
bool	is_command(t_pipex *pipex, char *command, int i)
{
	if (!command)
		return (false);
	if (access(command, F_OK) == 0)
	{
		pipex->cmds[i].path = ft_strdup(command);
		if (!pipex->cmds[i].path)
			return (false);
		free(command);
		return (true);
	}
	pipex->cmds[i].path = NULL;
	free(command);
	return (false);
}

//prints a zsh like error message
//skips first if not first found
void	cmd_not_found(t_pipex *pipex, int i)
{
	ft_putstr_fd("pipex: command not found: ", 1);
	ft_putstr_fd(pipex->cmds[i].args[0], 2);
	ft_putstr_fd("\n", 2);
	if (i == 0)
		pipex->skip_first = true;
}

//iterate through commands in pipex.cmd, and searches for paths
//return value: true if all found, false if one or more not found
bool	find_commands(t_pipex *pipex)
{
	int		i;
	int		j;
	char	*command;
	bool	ret;

	ret = true;
	i = -1;
	while (i++ < pipex->size - 1)
	{
		j = 0;
		if (pipex->cmds[i].args[0]
			&& is_command(pipex, ft_strdup(pipex->cmds[i].args[0]), i))
			break ;
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
	return (ret);
}

//find PATH in environment variables and saves it into pipex
bool	find_paths(t_pipex *pipex, char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	pipex->paths = ft_split(envp[i], ':');
	if (!pipex->paths)
		return (false);
	return (true);
}

//read all the commands, infile, outfile, opens fd's for files
//return value: if any error false at first error, else true
bool	parse_input(t_pipex *pipex, char **argv, char **envp)
{
	int	i;

	i = 0;
	pipex->cmds = malloc(pipex->size * sizeof(t_cmd));
	if (!pipex->cmds)
		return (false);
	while (i < pipex->size)
	{
		pipex->cmds[i].args = ft_split(argv[i + 2], ' ');
		if (!pipex->cmds[i].args)
			return (false);
		i++;
	}
	if (!find_paths(pipex, envp) || !find_commands(pipex))
		return (false);
	pipex->envp = envp;
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
		pipex->skip_first = true;
	pipex->outfile = open(argv[pipex->size + 2],
			O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (pipex->outfile == -1)
		return (false);
	return (true);
}
