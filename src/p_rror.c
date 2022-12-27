/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_rror.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:50:21 by avassor           #+#    #+#             */
/*   Updated: 2022/12/26 15:10:00 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex.h"

void	rr_miarg(t_core *board)
{
	ft_printf("wrong arguments form. use :\ninfile cmd1 cmd2... outfile\n");
	ft_printf("as : < infile cmd1 | cmd2 > outfile \nuse here_doc");
	ft_printf(" to read from stdin (here_doc key cmd1 cmd2... outfile)\n");
	ft_printf("where key is a string limiter to stop reading\n");
	cleaner(board, 1);
}

void	rr_pthnm(t_core *board)
{
	if (board->aror)
	{
		ft_printf("%s", board->aror);
		ft_printf(": ");
	}
	write(2, "command not found\n", 18);
	if (board->pipes == 2 && board->hed)
		cleaner(board, 127);
	else
		cleaner(board, 0);
}

void	rr_stror(t_core *board)
{
	int	c;

	c = errno;
	ft_printf("%s\n", strerror(c));
	if (c == 2 && !board->hed)
		c = 0;
	else if (c == 2)
		c = 1;
	cleaner(board, c);
}

void	rr_mallc(t_core *board)
{
	ft_printf("memory allocation error, please verify memory state\n");
	cleaner(board, 1);
}

void	rr_noenv(t_core *board)
{
	ft_printf("error in accessing the $PATH environment variable.\n");
	cleaner(board, 1);
}
