/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 11:45:47 by avassor           #+#    #+#             */
/*   Updated: 2022/12/20 12:05:22 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	line_chk2(char *a, char *b)
{
	char	*p1;
	char	*p2;

	p1 = a;
	p2 = b;
	while (*p1 && *p1 != '\n')
	{
		if (*p2 && *p1 == *p2)
		{
			p1++;
			p2++;
		}
		else
			return (0);
	}
	return (1);
}

char	*limited(t_stash **stash, char *line, int fd)
{
	if (stash)
		ft_unleash(stash[fd]);
	stash[fd] = NULL;
	free(line);
	return (NULL);
}
