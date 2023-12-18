/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:34:37 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/18 08:10:41 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

//the difference from main.c is the argc check
int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc < 5)
		return (ft_putstr_fd(ERR_ARG_2, 2), EXIT_FAILURE);
	if (!pipex_init(&pipex, argc, argv, envp))
		return (free_pipex(&pipex), error_message(NULL), EXIT_FAILURE);
	if (argc < 5 + pipex.heredoc)
		return (ft_putstr_fd(ERR_ARG_2, 2), free_pipex(&pipex), EXIT_FAILURE);
	if (!parse_input(&pipex))
		return (free_pipex(&pipex), EXIT_FAILURE);
	if (!create_pipes(&pipex))
		return (free_pipex(&pipex), error_message(NULL), EXIT_FAILURE);
	if (!execute(&pipex))
		return (free_pipex(&pipex), error_message(NULL), pipex.exitcode);
	free_pipex(&pipex);
	return (pipex.exitcode);
}

//initialize pipex structure
bool	pipex_init(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->paths = NULL;
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->cmds = NULL;
	pipex->pipes = NULL;
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->child_pids = NULL;
	pipex->exitcode = EXIT_SUCCESS;
	pipex->heredoc = false;
	if (ft_strncmp(pipex->argv[1], "here_doc", 9) == 0
		&& ft_strncmp(pipex->argv[0], "./pipex_bonus", 14) == 0)
		pipex->heredoc = true;
	pipex->size = argc - 3 - pipex->heredoc;
	if (!init_cmds(pipex))
		return (false);
	return (true);
}

//help pipex init
//allocate memory for commands
bool	init_cmds(t_pipex *pipex)
{
	int	i;

	pipex->cmds = malloc(pipex->size * sizeof(t_cmd));
	if (!pipex->cmds)
		return (false);
	i = 0;
	while (i < pipex->size)
	{
		pipex->cmds[i].args = NULL;
		pipex->cmds[i].found = false;
		pipex->cmds[i].path = NULL;
		i++;
	}
	return (true);
}
