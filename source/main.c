/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:55 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/29 14:37:33 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		return (EXIT_FAILURE);
	pipex.size = argc - 3;
	if (!parse_input(&pipex, argv, envp))
		return (free_pipex(&pipex));
	if (pipe(pipex.mypipe) == -1)
		return (EXIT_FAILURE);
	print_pipex(pipex);
	free_pipex(&pipex);
	return (EXIT_SUCCESS);
}
