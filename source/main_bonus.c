/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:34:37 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/16 13:40:31 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//the difference from main.c is the argc check
int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
	{
		ft_putstr_fd("Error: Not enough arguments\n", 2);
		return (EXIT_FAILURE);
	}
	pipex_init(&pipex, argc, argv, envp);
	if (!parse_input(&pipex))
		return (free_pipex(&pipex), EXIT_FAILURE);
	if (!create_pipes(&pipex))
		return (free_pipex(&pipex), error_message(NULL), EXIT_FAILURE);
	if (!execute(pipex))
		return (free_pipex(&pipex), error_message(NULL), EXIT_FAILURE);
	free_pipex(&pipex);
	return (EXIT_SUCCESS);
}
