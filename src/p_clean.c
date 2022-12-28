/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_clean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 15:09:52 by avassor           #+#    #+#             */
/*   Updated: 2022/12/26 15:13:29 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex.h"

void	rr_nulll(t_core *board, size_t in)
{
	if (board->hrdck && !*board->argv[2])
		return ;
	if (in == (1 + board->hrdck) || in == (size_t)(board->argc -1))
	{
		ft_printf("%s\n", strerror(2));
		if (in == (size_t)(board->argc -1))
			cleaner(board, 1);
		cleaner(board, 0);
	}
	else
	{
		write(2, " : command not found\n", 21);
		if (board->pipes == 2 && in == (3 + board->hrdck))
			cleaner(board, 127);
		cleaner(board, 0);
	}
}

void	cleaner(t_core *board, int id)
{
	if (!board)
		;
	else
	{
		if (board->fd1 >= 0)
			close(board->fd1);
		if (board->fd2 >= 0)
			close(board->fd2);
		if (board->hed)
			unleash(board->hed);
		if (board->env)
			unleash2(board->env);
		if (board->fd)
			free(board->fd);
		free(board);
	}
	if (id != -666)
		exit(id);
}

void	unleash(t_cmd *head)
{
	t_cmd	*hold;
	t_cmd	*next;
	size_t	i;

	hold = head;
	while (hold)
	{
		i = 0;
		next = hold->next;
		while (hold->prg[i])
			free(hold->prg[i++]);
		free(hold->prg);
		if (hold->path)
			free(hold->path);
		free(hold);
		hold = next;
	}
	free(hold);
}

void	unleash2(char **head)
{
	char	**hold;
	int		i;

	hold = head;
	i = 0;
	while (hold[i])
		free(hold[i++]);
	free(hold);
}
