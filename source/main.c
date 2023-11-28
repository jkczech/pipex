/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:55 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/28 15:09:50 by jkoupy           ###   ########.fr       */
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

bool	load_input(t_pipex *pipex, char **argv, char **envp)
{
	// if (ft_strlen(argv[0]) == 0 || ft_strlen(argv[1]) == 0 || ft_strlen(argv[2]) == 0 || ft_strlen(argv[3]) == 0)
	// 	exit (1);
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
	if (!pipex->cmd[0].args[0] || !pipex->cmd[1].args[0])
		return (free(pipex->cmd[0].args), free(pipex->cmd[1].args), false);
	if (!find_paths(pipex, envp))
		return (false);
	if (!find_commands(pipex))
		return (false);
	return (true);
}

bool	find_commands(t_pipex *pipex)
{
	int		i;
	int		j;
	char	*command;

	i = 0;
	while (i < pipex->size)
	{
		j = 0;
		while (pipex->paths[j])
		{
			command = ft_strjoin_three(pipex->paths[j], "/", pipex->cmd[i].args[0]);
			if (access(command, F_OK) == 0)
			{
				pipex->cmd[i].path = ft_strdup(command);
				free(command);
				break ;
			}
			j++;
			free(command);
			if (!pipex->paths[j])
				return (false);
		}
		i++;
	}
	return (true);
}
