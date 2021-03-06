/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 08:49:10 by nieyraud          #+#    #+#             */
/*   Updated: 2020/10/16 08:27:47 by nieyraud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_lst(t_env_lst **alst)
{
	t_env_lst *lst;
	t_env_lst *mem;

	lst = *alst;
	while (lst)
	{
		free(lst->name);
		free(lst->value);
		mem = lst;
		lst = lst->next;
		free(mem);
	}
}

void	free_builtin(char **params_cl)
{
	int i;

	i = 0;
	while (params_cl && params_cl[i] != NULL)
	{
		free(params_cl[i]);
		i++;
	}
	free(params_cl);
}

void	free_exec(char **env, char **argv)
{
	free(env);
	free(argv[0]);
	free(argv);
}

void	error_exit(void)
{
	ft_putstr_fd("Too many arguments\n", 2);
	errno = 7;
	g_last_return = 1;
}

void	ft_free(t_data *data, char **params, char *dest, t_cmd *lst)
{
	int		i;
	char	*str;

	i = 0;
	errno = 0;
	while (params && params[i])
		i++;
	str = dest;
	if (!dest)
		data->exit_code = g_last_return;
	else
		data->exit_code = (unsigned char)ft_atoi(dest);
	ft_putstr_fd("exit\n", 1);
	if (check_numeric(str, data) == 0 || check_numeric(str, data) == 2)
	{
		ft_putstr_fd("numeric argument required\n", 2);
		exit(free_datas(&lst, data, NULL));
	}
	if (i <= 1)
		exit(free_datas(&lst, data, NULL));
	error_exit();
}
