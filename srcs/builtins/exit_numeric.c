/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_numeric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:52:05 by user42            #+#    #+#             */
/*   Updated: 2020/10/17 14:53:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	str_is_num(char *str)
{
	if (str && (*str == '+' || *str == '-'))
		str++;
	while (str && *str)
	{
		if (ft_isdigit(*str) == 0)
			return (0);
		str++;
	}
	return (1);
}

int	is_above_long_max(char *str)
{
	char	*long_max;
	int		i;

	long_max = "9223372036854775807";
	i = 0;
	if (str[0] == '-')
		return (0);
	else if (str[0] == '+')
		str++;
	if (ft_strlen(long_max) > ft_strlen(str))
		return (1);
	while (*str == '0')
		str++;
	if (ft_strlen(long_max) < ft_strlen(str))
		return (0);
	while (long_max[i] && str[i])
	{
		if (long_max[i] == str[i])
			i++;
		else if (long_max[i] > str[i])
			return (1);
		else
			return (0);
	}
	return (1);
}

int	is_below_long_min(char *str)
{
	char	*long_min;
	int		i;

	long_min = "9223372036854775808";
	i = 0;
	if (str[0] == '+')
		return (0);
	else if (str[0] == '-')
		i++;
	if (ft_strlen(long_min) > ft_strlen(str))
		return (1);
	while (*str == '0')
		str++;
	if (ft_strlen(long_min) < ft_strlen(str))
		return (0);
	while (long_min[i] && str[i])
	{
		if (long_min[i] == str[i])
			i++;
		else if (long_min[i] > str[i])
			return (1);
		else
			return (0);
	}
	return (1);
}

int	check_numeric(char *str, t_data *data)
{
	int i;

	i = 1;
	if (str == NULL)
		return (1);
	if (str_is_num(str) == 0)
		i = 2;
	if (is_above_long_max(str) == 0
	&& is_below_long_min(str) == 0)
		i = 0;
	if (i == 0 || i == 2)
	{
		data->exit_code = 2;
		return (2);
	}
	return (1);
}
