/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:51:53 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/17 02:57:09 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//opens infile and outfile, shows errors respectively
void	open_here_doc(t_pipex *pipex)
{
	pipex->infile = open(pipex->argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		if (access(pipex->argv[1], F_OK) != 0)
			error_message(pipex->argv[1]);
		else if (access(pipex->argv[1], R_OK) != 0)
			error_message(pipex->argv[1]);
		else
			ft_putstr_fd("Error: infile undefined\n", 2);
	}
	pipex->outfile = open(pipex->argv[pipex->size + 2],
			O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (pipex->outfile == -1)
	{
		if (access(pipex->argv[pipex->size + 2], W_OK) != 0)
			error_message(pipex->argv[pipex->size + 2]);
		else
			ft_putstr_fd("Error: outfile undefined\n", 2);
	}
}
