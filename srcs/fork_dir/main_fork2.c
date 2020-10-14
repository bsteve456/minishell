#include "minishell.h"

int		check_fd(int *fdpipe, t_info *p, t_cmd *cmd)
{
	int fd;
	int pcount;

	fd = 0;
	pcount = p->pcount;
	if (pcount != 0 && (pcount - 1) * 2 < p->pnum)
		fd = fdpipe[(pcount - 1) * 2];
	if (left_redir(cmd->next) == 1)
		fd = ft_redirect(cmd->next, p);
	return (fd);
}

int		check_fd2(int *fdpipe, t_info p, t_cmd *cmd)
{
	int fd;
	int pcount;
	int i;

	fd = 1;
	pcount = p.pcount;
	i = 0;
	while(i < p.end_pass)
	{
		cmd = cmd->next;
		i++;
	}
	if ((pcount) * 2 + 1 < p.pnum)
		fd = fdpipe[(pcount) * 2 + 1];
	if (right_redir(cmd->next) == 1)
		fd = ft_redirect2(cmd->next);
	return (fd);
}

void	do_builtin(t_info p, int *fdpipe, t_cmd *lst, t_data *data)
{
	int fd[2];
	int i;

	i = 0;
	if(check_pipe(lst) == 1)
		lst = lst->next;
	fd[0] = check_fd(fdpipe, &p, lst);
	fd[1] = check_fd2(fdpipe, p, lst);
	dup2(fd[0], 0);
	dup2(fd[1], 1);

	while(i < p.pnum)
		close(fdpipe[i++]);
	builtins(lst->command, lst->params, data);
	exit(0);
}