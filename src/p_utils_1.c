/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:45:30 by avassor           #+#    #+#             */
/*   Updated: 2022/12/26 15:09:51 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex.h"

void	pied_piper(t_core *board)
{
	size_t	c;

	c = 0;
	while (c < (board->pipes - 1))
	{
		if (pipe(board->fd + (2 * c)) < 0)
			rror(board, ACCSS);
		c++;
	}
}

void	board_init(t_core *board)
{
	board->fd1 = -666;
	board->fd2 = -666;
	board->hrdck = 0;
	board->pipes = 0;
	board->ppplc = 0;
	board->fd = NULL;
	board->hed = NULL;
	board->lim = NULL;
	board->cmd = NULL;
	board->file1 = NULL;
	board->file2 = NULL;
	board->env = NULL;
	board->aror = NULL;
}

void	parse_cmd(t_core *board)
{
	size_t	cnt;
	size_t	i;

	cnt = 1;
	i = 2 + board->hrdck;
	if (board->lim)
		if (!*board->lim)
			board->lim = "\n";
	frst_link(board, board->argv[i++]);
	while (cnt++ != board->pipes)
		add_link(board, board->argv[i++]);
}

void	readr(t_core *board)
{
	char	*in;
	int		tmp;

	tmp = open(".ppxtmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (tmp < 0)
		rror(board, ACCSS);
	while (1)
	{
		in = get_next_line(0, board->lim);
		if (!in)
			break ;
		write(tmp, in, ft_strlen(in));
		free(in);
	}
	free(in);
	close(tmp);
	board->fd1 = open(".ppxtmp", O_RDONLY);
	if (board->fd1 < 0)
		rror(board, ACCSS);
}

char	*pathfindr(t_core *board, char *cmd)
{
	char	**p;
	char	*tmp1;
	char	*tmp2;

	p = board->env;
	while (*p)
	{
		tmp1 = ft_strjoin(*p, "/");
		tmp2 = ft_strjoin(tmp1, cmd);
		free(tmp1);
		if (!access(tmp2, F_OK))
			return (tmp2);
		free(tmp2);
		p++;
	}
	board->aror = cmd;
	rror(board, PTHNM);
	return (NULL);
}
