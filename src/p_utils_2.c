/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:45:42 by avassor           #+#    #+#             */
/*   Updated: 2022/12/26 15:14:25 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex.h"

void	rror(t_core *board, t_error id)
{
	void	(*fptr[8])(t_core *);

	fptr[MIARG] = rr_miarg;
	fptr[PTHNM] = rr_pthnm;
	fptr[ACCSS] = rr_stror;
	fptr[MALLC] = rr_mallc;
	fptr[NOENV] = rr_noenv;
	fptr[CMDPT] = rr_cmdpt;
	if (!board)
		((*fptr[id])(NULL));
	((*fptr[id])(board));
}

void	rr_cmdpt(t_core *board)
{
	ft_printf("please do not specify command path\n");
	cleaner(board, 1);
}

t_cmd	*ft_lstlastc(t_cmd *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

size_t	line_chk(char *a, char *b)
{
	char	*p1;
	char	*p2;

	p1 = a;
	p2 = b;
	if (!*p1 || !*p2)
		return (0);
	while (*p1 && *p2)
	{
		if (*p1 == *p2)
		{
			p1++;
			p2++;
		}
		else
			return (0);
	}
	return (1);
}
