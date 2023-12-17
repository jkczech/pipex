/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:55 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/17 03:45:38 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//read all the commands, infile, outfile, opens fd's for files
//return value: if any error false at first error, else true
bool	parse_input(t_pipex *pipex)
{
	int	i;

	if (!find_paths(pipex))
		return (false);
	open_files(pipex);
	i = 0;
	while (i < pipex->size)
	{
		pipex->cmds[i].found = false;
		pipex->cmds[i].args = ft_split(pipex->argv[i + 2], ' ');
		if (!pipex->cmds[i].args)
			return (false);
		if (!(i == 0 && pipex->infile == -1)
			&& !(i == pipex->size - 1 && pipex->outfile == -1))
			find_command(pipex, i);
		i++;
	}
	return (true);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
		return (EXIT_FAILURE);
	}
	if (!pipex_init(&pipex, argc, argv, envp))
		return (free_pipex(&pipex), error_message(NULL), EXIT_FAILURE);
	if (!parse_input(&pipex))
		return (free_pipex(&pipex), EXIT_FAILURE);
	if (!create_pipes(&pipex))
		return (free_pipex(&pipex), error_message(NULL), EXIT_FAILURE);
	if (!execute(pipex))
		return (free_pipex(&pipex), error_message(NULL), EXIT_FAILURE);
	free_pipex(&pipex);
	return (EXIT_SUCCESS);
}
