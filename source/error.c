/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:46:06 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/15 14:58:24 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//printing "Error: " + strerror(errno)
void	error_message(char *file)
{
	ft_putstr_fd("Pipex: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	if (file)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(file, 2);
	}
	ft_putstr_fd("\n", 2);
}

//prints a zsh like error message, sets cmd to not found
void	cmd_not_found(t_pipex *pipex, int i)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(pipex->cmds[i].args[0], 2);
	ft_putstr_fd("\n", 2);
	pipex->cmds[i].found = false;
}
