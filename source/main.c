/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:55 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/29 13:08:34 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (1);
	pipex.size = 2;
	if (!load_input(&pipex, argv, envp))
		return (free_pipex(&pipex));
	if (pipe(pipex.mypipe) == -1)
		return (1);
	print_pipex(pipex);
	free_pipex(&pipex);
	return (0);
}

//finds PATH in environment variables and saves it into pipex
bool	find_paths(t_pipex *pipex, char **envp)
{
	int	i;

	i = 0;
	while (strncmp(envp[i], "PATH", 4) != 0)
		i++;
	pipex->paths = ft_split(envp[i], ':');
	if (!pipex->paths)
		return (false);
	return (true);
}

//reads all the commands, infile, outfile, opens fd's for files
//return value: if any error false at first error, else true
bool	load_input(t_pipex *pipex, char **argv, char **envp)
{
	pipex->infile = open(argv[1], O_WRONLY | O_CREAT, 0777);
	if (!pipex->infile)
		return (false);
	pipex->outfile = open(argv[4], O_RDONLY | O_CREAT, 0777);
	if (!pipex->outfile)
		return (false);
	pipex->cmd = malloc(pipex->size * sizeof(t_cmd));
	if (!pipex->cmd)
		return (false);
	pipex->cmd[0].args = ft_split(argv[2], ' ');
	pipex->cmd[1].args = ft_split(argv[3], ' ');
	if (!pipex->cmd[0].args || !pipex->cmd[1].args)
		return (false);
	if (!find_paths(pipex, envp))
		return (false);
	if (!find_commands(pipex))
		return (false);
	return (true);
}

//iterates through commands in pipex.cmd, and searches for paths
//return value: true if all found, false if one or more not found
bool	find_commands(t_pipex *pipex)
{
	int		i;
	int		j;
	char	*command;
	bool	ret;

	ret = true;
	i = 0;
	while (i < pipex->size)
	{
		j = 0;
		pipex->cmd[i].path = NULL;
		while (pipex->paths[j])
		{
			command = ft_strjoin_three(pipex->paths[j], \
					"/", pipex->cmd[i].args[0]);
			if (is_command(pipex, command, i))
				break ;
			j++;
			if (!pipex->paths[j])
				ret = false;
		}
		i++;
	}
	return (ret);
}

//checks if command is valid, if so, saves it into pipex
bool	is_command(t_pipex *pipex, char *command, int i)
{
	if (!command)
		return (false);
	if (access(command, F_OK) == 0)
	{
		pipex->cmd[i].path = ft_strdup(command);
		free(command);
		return (true);
	}
	free(command);
	return (false);
}
