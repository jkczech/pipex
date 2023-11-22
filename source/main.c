/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:55 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/22 21:56:34 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd;

	if (argc != 5)
		return (1);

	fd = open(argv[1], O_WRONLY);
	if (!fd)
		return (1);
	fd = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (!fd)
		return (1);
	//dup2(fd, STDOUT_FILENO);
	close(fd);
	int i = 0;
	while (envp[i])
	{
		printf("Envp %d: %s\n", i, envp[i]);
		i++;
	}
	printf("This is printed in example.txt!\n");
	return (0);
}
