/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:46:06 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/12 11:58:09 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//printing "Error: " + strerror(errno)
bool	error_message(void)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(strerror(errno), 2);
	ft_putstr_fd("\n", 2);
	return (true);
}

//prints a zsh like error message
//skips first if not first found
void	cmd_not_found(t_pipex *pipex, int i)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(pipex->cmds[i].args[0], 2);
	ft_putstr_fd("\n", 2);
	pipex->cmds[i].found = false;
	if (i == 0)
		pipex->skip_first = true;
}

//prints a zsh like error message
//skips first if not first found
void	permission_denied(char *file)
{
	ft_putstr_fd("pipex: permission denied: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
}

//prints a zsh like error message
//skips first if not first found
void	no_such_file(char *file)
{
	ft_putstr_fd("pipex: no such file or directory: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("\n", 2);
}
