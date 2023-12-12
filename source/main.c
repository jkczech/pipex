/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:55 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/12 15:01:03 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
	{
		ft_putstr_fd("Error: Not enough arguments\n", 2);
		return (EXIT_FAILURE);
	}
	pipex_init(&pipex, argc);
	if (!parse_input(&pipex, argv, envp))
		return (free_pipex(&pipex), EXIT_FAILURE);
	pipex.child_pids = NULL;
	if (!create_pipes(&pipex))
		return (free_pipex(&pipex), error_message(), EXIT_FAILURE);
	if (!execute(pipex))
		return (free_pipex(&pipex), error_message(), EXIT_FAILURE);
	free_pipex(&pipex);
	return (EXIT_SUCCESS);
}

//find PATH in environment variables and saves it into pipex
bool	find_paths(t_pipex *pipex, char **envp)
{
	int	i;

	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	pipex->paths = ft_split(envp[i], ':');
	if (!pipex->paths)
		return (false);
	return (true);
}
