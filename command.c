/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 09:51:32 by jbester           #+#    #+#             */
/*   Updated: 2016/07/07 13:58:44 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_changedir(char *line)
{
	char	**new;

	new = ft_strsplit(line, ' ');
	if (ft_checkdir(new[1]) == 0)
	{
		chdir(new[1]);
		return (0);
	}
	return (1);
}

int	ft_currentdir(void)
{
	char	buf[4096];

	getcwd(buf, 4096);
	ft_putstr(buf);
	ft_putchar('\n');
	return (1);
}

int	ft_env(char **env)
{
	int	count;

	count = 0;
	while (env[count] != NULL)
	{
		ft_putstr(env[count]);
		ft_putchar('\n');
		count++;
	}
	return (1);
}

int	ft_checkdir(char *dir)
{
	if (access(dir, X_OK) == 0)
		return (0);
	else
	{
		ft_putstr("Minishell: invalid directory or file: ");
		ft_putstr(dir);
		ft_putchar('\n');
		return (-1);
	}
	return (0);
}
