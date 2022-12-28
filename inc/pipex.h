/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avassor <avassor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:11:33 by avassor           #+#    #+#             */
/*   Updated: 2022/12/26 15:07:27 by avassor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./../libft/inc/libft.h"
# include "./../libft/inc/ft_printf.h"

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>

typedef struct s_cmd
{
	char			**prg;
	char			*path;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_core
{
	char	**argv;
	char	**envp;
	char	*file1;
	char	*file2;
	char	**env;
	char	*lim;
	char	*aror;
	int		argc;
	int		fd1;
	int		fd2;
	int		*fd;
	size_t	hrdck;
	size_t	pipes;
	size_t	ppplc;
	t_cmd	*cmd;
	t_cmd	*hed;
}	t_core;

typedef enum e_rror
{
	PTHNM,
	ACCSS,
	MIARG,
	MALLC,
	CMDPT,
	EMPTY,
	NULLL,
	NOENV
}	t_error;

void	readr(t_core *board);
void	pipex(t_core *board);
void	unleash(t_cmd *head);
void	unleash2(char **head);
void	arg_chk(t_core *board);
void	get_env(t_core *board);
void	exe_cmd(t_core *board);
void	rr_noenv(t_core *board);
void	rr_pthnm(t_core *board);
void	rr_stror(t_core *board);
void	rr_mallc(t_core *board);
void	rr_miarg(t_core *board);
void	rr_cmdpt(t_core *board);
void	empty_chk(t_core *board);
void	parse_cmd(t_core *board);
void	board_init(t_core *board);
void	pied_piper(t_core *board);
void	get_fd(t_core *board, int *fd);
void	rror(t_core *board, t_error id);
void	cleaner(t_core *board, int id);
void	rr_nulll(t_core *board, size_t in);
void	add_link(t_core *board, char *cmd);
void	frst_link(t_core *board, char *cmd);

size_t	line_chk(char *a, char *b);

char	*pathfindr(t_core *board, char *cmd);

t_cmd	*ft_lstlastc(t_cmd *lst);

#endif
