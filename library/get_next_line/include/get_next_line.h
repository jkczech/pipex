/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:41:30 by jkoupy            #+#    #+#             */
/*   Updated: 2023/12/17 03:49:04 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

//read
# include <unistd.h>
//malloc, free
# include <stdlib.h>

# include "t_list.h"

//get_next_line.c
void	free_line(t_list **llist);
char	*read_line(t_list *llist);
int		line_ends(char *line);
void	save_line(t_list **llist, int fd);
char	*get_next_line(int fd);

//get_next_line_utils.c
void	free_list(t_list **llist, char *new_content);
int		line_length(t_list *llist);
void	ft_lstadd_new(t_list **lst, char *new_content);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);

//extra testing functions
// void	print_list(t_list *ll);
// void	print_nl(char *str);

#endif
