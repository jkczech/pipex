/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:55 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/29 13:23:30 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
		return (1);
	pipex.size = 2;
	if (!parse_input(&pipex, argv, envp))
		return (free_pipex(&pipex));
	if (pipe(pipex.mypipe) == -1)
		return (1);
	print_pipex(pipex);
	free_pipex(&pipex);
	return (0);
}
