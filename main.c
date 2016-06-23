/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 08:18:06 by jbester           #+#    #+#             */
/*   Updated: 2016/06/23 15:07:03 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check(char *line, char **env)
{
	env = 0;
	if (ft_strcmp(line, "exit") == 0)
	{
		exit(0);
	}
	if (ft_strncmp(line, "cd", 2) == 0)
		ft_changedir(line);
	if (ft_strcmp(line, "pwd") == 0)
		ft_currentdir();
	//if (ft_strcmp(line, "env"))
	//	ft_env(line, env);
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	char	*line;
	
	(void)argc;
	(void)argv;
	line = 0;
	ft_putstr("Shell> ");
	while ((ft_get_next_line(0, &line)) > 0)
	{
		if (ft_check(line, env) == 0)
		{
			ft_putstr("Minishell does not recognise the command: ");
			ft_putstr(line);
			ft_putchar('\n');
		}
		ft_putstr("Shell> ");
	}
	return (0);
}
