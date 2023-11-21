/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 14:26:55 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/21 15:33:40 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 5)
		return (1);

	fd = open(argv[1], O_WRONLY | O_CREAT, 0644);
	if (!fd)
		return (NULL);
	fd = open(argv[4], O_WRONLY | O_CREAT, 0644);
	if (!fd)
		return (NULL);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	printf("This is printed in example.txt!\n");
	return (0);
}
