/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:41:33 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/17 01:56:17 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

void	free_line(t_list **llist)
{
	t_list	*last;
	char	*leftover;
	int		i;
	int		j;

	if (!*llist)
		return ;
	last = ft_lstlast(*llist);
	i = line_length(last);
	if (!last->content[i])
		return (free_list(llist, NULL));
	j = 0;
	leftover = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!leftover)
		return ;
	while (last->content[i])
		leftover[j++] = last->content[i++];
	leftover[j] = '\0';
	free_list(llist, leftover);
}

//takes the list and returns the full string until newline
char	*read_line(t_list *llist)
{
	char	*line;
	int		i;
	int		j;

	if (!llist || !llist->content)
		return (NULL);
	line = malloc((line_length(llist) + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (llist)
	{
		j = 0;
		while (llist->content[j] && llist->content[j] != '\n')
			line[i++] = llist->content[j++];
		if (llist->content[j] == '\n')
		{
			line[i++] = llist->content[j++];
			break ;
		}
		llist = llist->next;
	}
	line[i] = '\0';
	return (line);
}

// returns 1 if finds a newline
// else 0
int	line_ends(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (1);
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

// creates a linked list and reads BUFFER_SIZE bytes each time
// until it finds a buffer smaller than B_S or a \n in it
void	save_line(t_list **llist, int fd)
{
	int		readlen;
	char	*buf;

	if (*llist && line_ends((*llist)->content))
		return ;
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return ;
	readlen = read(fd, buf, BUFFER_SIZE);
	if (readlen == 0)
		return (free(buf));
	if (readlen == -1)
		return (free(buf), free_list(llist, NULL));
	buf[readlen] = '\0';
	ft_lstadd_new(llist, buf);
	if (line_ends(buf) || readlen < BUFFER_SIZE)
		return ;
	return (save_line(llist, fd));
}

char	*get_next_line(int fd)
{
	static t_list	*llist;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free_list(&llist, NULL);
		return (NULL);
	}
	save_line(&llist, fd);
	next_line = read_line(llist);
	free_line(&llist);
	return (next_line);
}

// 	printf("\tlist before:\n");
// 	print_list(llist);
// 	printf("\tlist mid:\n");
// 	print_list(llist);
// 	printf("\tlist after:\n");
// 	print_list(llist);

// 	#include <fcntl.h>
// #include <stdio.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;
// 	int		j;
// 	char	*files[] = {"test.txt"};
// //lorem_ipsum.txt, "empty.txt", "one_nl.txt",
// "multiple_nl.txt", "one_char_lines.txt", "no_nl.txt"
// 	i = 0;
// 	while (i < 1)
// 	{
// 		printf("------------------------------\n");
// 		printf("file: %s\n", files[i]);
// 		printf("------------------------------\n");
// 		fd = open(files[i], O_RDONLY);
// 		line = get_next_line(fd);
// 		j = 1;
// 		while (line)
// 		{
// 			printf("Line %d: ", j);
// 			//print_nl(line);
// 			printf("\n");
// 			free(line);
// 			line = get_next_line(fd);
// 			j++;
// 		}
// 		printf("Line %d: ", j);
// 		//print_nl(line);
// 		free(line);
// 		i++;
// 	}
// 	return (0);
// }
