/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:46:06 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/16 18:19:22 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//printing error in the zsh format (also lower capitalized)
void	error_message(char *file)
{
	char	*message;

	ft_putstr_fd("pipex: ", 2);
	message = ft_strdup(strerror(errno));
	message = ft_strlwr(message);
	if (message)
		ft_putstr_fd(message, 2);
	else
		ft_putstr_fd("error allocating error_message", 2);
	if (file)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(file, 2);
	}
	ft_putstr_fd("\n", 2);
	if (message)
		free(message);
}

//prints a zsh like error message, sets cmd to not found
void	cmd_not_found(t_pipex *pipex, int i)
{
	ft_putstr_fd("pipex: command not found: ", 2);
	ft_putstr_fd(pipex->cmds[i].args[0], 2);
	ft_putstr_fd("\n", 2);
	pipex->cmds[i].found = false;
}
