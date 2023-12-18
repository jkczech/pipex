/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 00:51:53 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/18 05:21:19 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//use get_next_line to read here_doc from command line
void	here_doc(t_pipex *pipex)
{
	char	*buf;

	while (1)
	{
		write(1, "pipex heredoc> ", 15);
		buf = get_next_line(0);
		if (!buf)
			exit(1);
		if (ft_strlen(pipex->argv[2]) == ft_strlen(buf) - 1 && \
			ft_strncmp(pipex->argv[2], buf, ft_strlen(pipex->argv[2])) == 0)
			break ;
		write(pipex->infile, buf, ft_strlen(buf) - 1);
		write(pipex->infile, "\n", 1);
		free(buf);
	}
	free(buf);
}

//opens infile and outfile like with << and >>
void	open_here_doc(t_pipex *pipex)
{
	pipex->infile = open(".here_doc", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (pipex->infile == -1)
		error_message(NULL);
	here_doc(pipex);
	close(pipex->infile);
	pipex->infile = open(".here_doc", O_RDONLY);
	if (pipex->infile == -1)
	{
		unlink(".here_doc");
		error_message(NULL);
	}
	pipex->outfile = open(pipex->argv[pipex->size + 3],
			O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (pipex->outfile == -1)
	{
		if (access(pipex->argv[pipex->size + 2], W_OK) != 0)
			error_message(pipex->argv[pipex->size + 2]);
		else
			ft_putstr_fd("Error: outfile undefined\n", 2);
	}
}
