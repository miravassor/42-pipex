/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:11:01 by avassor           #+#    #+#             */
/*   Updated: 2022/12/26 14:33:44 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../inc/pipex.h"

void	empty_chk(t_core *board)
{
	size_t	in;
	size_t	out;
	char	*p;

	in = 1 + board->hrdck;
	out = board->argc -1;
	while (in <= out)
	{
		p = board->argv[in];
		if (!*p)
			rr_nulll(board, in);
		in++;
	}
}

void	get_fd(t_core *board, int *fd)
{
	if (!board->ppplc)
	{
		fd[0] = board->fd1;
		fd[1] = board->fd[1];
	}
	else if (board->pipes == 1)
	{
		fd[0] = board->fd[2 * board->ppplc - 2];
		fd[1] = board->fd2;
	}
	else
	{
		fd[0] = board->fd[2 * board->ppplc - 2];
		fd[1] = board->fd[2 * board->ppplc + 1];
	}
}

void	exe_cmd(t_core *board)
{
	pid_t	pid;
	int		fd[2];

	get_fd(board, fd);
	pid = fork();
	if (pid < 0)
		rror(board, ACCSS);
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		if (execve(board->cmd->path, board->cmd->prg, board->envp))
			rror(board, ACCSS);
	}
	else
	{
		close(fd[0]);
		waitpid(pid, 0, 0);
		close(fd[1]);
		board->ppplc++;
		board->pipes--;
		board->cmd = board->cmd->next;
	}
}

void	pipex(t_core *board)
{
	pied_piper(board);
	if (board->hrdck)
		readr(board);
	while (board->pipes > 0)
		exe_cmd(board);
	cleaner(board, -666);
}

int	main(int argc, char **argv, char **envp)
{
	t_core	*board;

	if (argc < 5)
		rror(NULL, MIARG);
	board = (t_core *)malloc(sizeof(t_core));
	if (!board)
		rror(NULL, MALLC);
	board->argc = argc;
	board->argv = argv;
	board->envp = envp;
	board_init(board);
	arg_chk(board);
	pipex(board);
	return (0);
}
