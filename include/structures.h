/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 02:34:44 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/17 02:34:47 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_cmd
{
	bool	found;
	char	*path;
	char	**args;
}	t_cmd;

typedef struct s_pipex
{
	int		size;
	int		infile;
	int		outfile;
	t_cmd	*cmds;
	int		**pipes;
	char	**paths;
	char	**argv;
	char	**envp;
	int		*child_pids;
}	t_pipex;