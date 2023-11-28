/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoupy <jkoupy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:50:47 by jkoupy            #+#    #+#             */
/*   Updated: 2023/11/28 13:54:32 by jkoupy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3)
{
	char	*joined1;
	char	*joined2;

	joined1 = ft_strjoin(s1, s2);
	joined2 = ft_strjoin(joined1, s3);
	free(joined1);
	return (joined2);
}
