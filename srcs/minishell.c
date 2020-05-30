/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 08:55:18 by nieyraud          #+#    #+#             */
/*   Updated: 2020/05/26 10:26:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main_loop(t_data *data, char **env)
{
	char	*line;
	int		ret;

	data->status = 1;
	data->last_return = 0;
	init_env(data, env);
	signal(SIGINT, sigquit_handler);
	signal(SIGQUIT, sigquit_handler);
	ret = 1;
	while(data->status && ret > 0)
	{
		fg_process = -1;
		write(1, "Minishell> ", 11);
		ret = get_next_line(0, &line);
		data->status = ft_command_parser(line, data);
		free(line);
	}
	free(line);
	return (0);
}

int main(int ac, char **av, char **env)
{
	t_data	*data;

	(void)ac;
	(void)av;
	(void)env;
	fg_process = -1;
	write(1, "\n\n\n\n****************", 20);
	write(1, "********************", 20);
	write(1, "\n\n\n\t****MINISHELL****",21);
	write(1, "\n\n\n\n****************", 20);
	write(1, "********************\n\n\n\n", 24);
	if (!(data = ft_calloc(sizeof(t_data), 1)))
		return (1);
	main_loop(data, env);
	return (0);
}
