/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nieyraud <nieyraud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:36:30 by user42            #+#    #+#             */
/*   Updated: 2020/10/14 17:24:28 by stbaleba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		length(char **params)
{
	int count;

	count = 0;
	while (params && params[count])
		count++;
	return (count);
}

void	pwd(void)
{
	char *res;

	errno = 0;
	res = ft_calloc(1000, sizeof(char));
	res = getcwd(res, 1000);
	ft_putstr_fd(res, 1);
	write(1, "\n", 2);
	free(res);
}

char	*home_dir(t_env_lst *lst)
{
	while (lst)
	{
		if (ft_memplus("HOME", lst->name) == 0)
			return (lst->value);
		lst = lst->next;
	}
	return (NULL);
}

void	cd(char **params_cl, t_data *data)
{
	int n;

	n = length(params_cl);
	if (n == 0 || ft_memcmp(params_cl[0], "~", 2) == 0)
		chdir(home_dir(data->env_var));
	else if (n == 1)
	{
		chdir(params_cl[0]);
		if (errno != 0 && g_fg_process != 0)
		{
			errno = 1;
			write(2, "Minishell: cd: ", 16);
			ft_putstr_fd(params_cl[0], 2);
			write(2, ": ", 2);
			ft_putstr_fd(strerror(2), 2);
			write(2, "\n", 2);
		}
	}
	else
	{
		errno = 1;
		ft_putstr_fd(strerror(7), 2);
		write(2, "\n", 2);
	}
}
