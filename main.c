/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 08:18:06 by jbester           #+#    #+#             */
/*   Updated: 2016/06/29 15:37:10 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check(char *line, char **env)
{
	if (ft_strcmp(line, "exit") == 0)
		exit(0);
	else if (ft_strncmp(line, "cd ", 3) == 0)
	{
		env = old_pwd_change(env);
		ft_putstr(env[7]);
		ft_changedir(line);
	}
	else if (ft_strcmp(line, "pwd") == 0)
		ft_currentdir();
	else if (ft_strcmp(line, "env") == 0)
		ft_env(env);
	else if (ft_strncmp(line, "", 1) == 0)
		return (1);
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv, char **env)
{
	char	*line;
	int		count;
	
	(void)argc;
	(void)argv;
	line = 0;
	count = 0;
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
