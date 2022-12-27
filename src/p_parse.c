/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:40:03 by avassor           #+#    #+#             */
/*   Updated: 2022/12/26 15:13:35 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex.h"

void	get_env(t_core *board)
{
	char	**p;

	p = board->envp;
	while (*p && ft_strncmp(*p, "PATH=", 5))
		p++;
	if (!*p)
		rror(board, NOENV);
	board->env = ft_split(*p + 5, ':');
}

void	arg_chk(t_core *board)
{
	if (line_chk(board->argv[1], "here_doc"))
		board->hrdck = 1;
	board->pipes = board->argc - 3 - board->hrdck;
	empty_chk(board);
	board->fd = (int *)malloc(sizeof(int) * (board->pipes * 2));
	if (!board->fd)
		rror(board, MALLC);
	if (!board->hrdck)
	{
		board->file1 = board->argv[1];
		if (!access(board->file1, R_OK))
			board->fd1 = open(board->file1, O_RDONLY);
		else
			rror(board, ACCSS);
	}
	else
		board->lim = board->argv[2];
	board->file2 = board->argv[board->argc - 1];
	board->fd2 = open(board->file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (board->fd2 < 0)
		rror(board, ACCSS);
	get_env(board);
	parse_cmd(board);
}

void	frst_link(t_core *board, char *cmd)
{
	if (line_chk(cmd, "."))
		rror(board, CMDPT);
	if (line_chk(cmd, "/"))
		rror(board, CMDPT);
	board->cmd = (t_cmd *)malloc(sizeof(t_cmd));
	if (!board->cmd)
		rror(board, MALLC);
	board->hed = board->cmd;
	board->cmd->next = NULL;
	board->cmd->prg = NULL;
	board->cmd->path = NULL;
	board->cmd->prg = ft_split(cmd, ' ');
	board->cmd->path = pathfindr(board, board->cmd->prg[0]);
}

void	add_link(t_core *board, char *cmd)
{
	t_cmd	*last;
	t_cmd	*new;

	if (line_chk(cmd, "."))
		rror(board, CMDPT);
	if (line_chk(cmd, "/"))
		rror(board, CMDPT);
	last = ft_lstlastc(board->cmd);
	last->next = (t_cmd *)malloc(sizeof(t_cmd));
	if (!last->next)
		rror(board, MALLC);
	new = last->next;
	new->next = NULL;
	new->prg = NULL;
	new->path = NULL;
	new->prg = ft_split(cmd, ' ');
	new->path = pathfindr(board, new->prg[0]);
}
