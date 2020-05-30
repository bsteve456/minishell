/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:38:24 by user42            #+#    #+#             */
/*   Updated: 2020/05/30 17:00:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>

t_env_lst	*ft_envnew(char *name, char *value)
{
	t_env_lst *new;

	new = 0;
	if (!(new = ft_calloc(1, sizeof(t_env_lst))))
		return (NULL);
	new->name = name;
	new->value = value;
	new->next = 0;
	return (new);
}

void		add_env(char *str, t_data *data)
{
	char	*name;
	char	*value;
	int		i;

	i = 0;
	name = ft_calloc(ft_strlen(str), sizeof(char));
	value = ft_calloc(ft_strlen(str), sizeof(char));
	while (*str != '=' && *str)
	{
		name[i++] = *str;
		str++;
	}
	str++;
	i = 0;
	while (*str)
	{
		value[i++] = *str;
		str++;
	}
	ft_addenv(&(data->env_var), ft_envnew(name, value));
}

void		ft_addenv(t_env_lst **alst, t_env_lst *new)
{
	t_env_lst *lst;

	lst = *alst;
	if (!lst)
		*alst = new;
	else
	{
		if (env_exist(lst, new) == 1)
			return ;
		else
		{
			while (lst->next)
				lst = lst->next;
			lst->next = new;
		}
	}
}

void		ft_delenv(t_env_lst **alst, char *name)
{
	t_env_lst *lst;
	t_env_lst *mem;
	t_env_lst *prev_elem;
	t_env_lst *next_elem;

	lst = *alst;
	mem = lst;
	prev_elem = 0;
	if (name == NULL)
		return ;
	while (lst)
	{
		next_elem = lst->next;
		if (ft_memcmp(name, lst->name, ft_strlen(name) + 1) == 0)
			ft_delst(lst, prev_elem, next_elem, mem);
		prev_elem = lst;
		if (lst)
			lst = lst->next;
	}
	*alst = mem;
}

void		env_list(t_data *data, char *params)
{
	t_env_lst *lst;

	lst = data->env_var;
	if (*params == '\0')
	{
		while (lst)
		{
			display(lst->name);
			display("=");
			display(lst->value);
			display("\n");
			lst = lst->next;
		}
	}
	else
	{
		errno = 2;
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 2);
	}
}
