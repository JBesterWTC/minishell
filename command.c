/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 09:51:32 by jbester           #+#    #+#             */
/*   Updated: 2016/06/23 15:06:15 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_changedir(char *line)
{
	char	**new;
	char	flag;
	int		count;

	flag = 0;
	count = 1;
	new = ft_strsplit(line, ' ');
	if (new[1] == "-L")
	{
		flag = 'L';
		count++;
	}
	else if (new[1] == "-P")
	{
		flag = 'P';
		count++;
	}
	if (ft_checkdir(new[count], flag) == 0)
	{
			chdir(new[1]);
			return (1);
	}
	else
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putstr(new[1]);
		ft_putchar('\n');
	}
	return (0);
}

int	ft_currentdir(void)
{
	char	buf[4096];

	getcwd(buf, 4096);
	ft_putstr(buf);
	ft_putchar('\n');
	return (1);
}

int	ft_env(char *line, char **env)
{
	
}

int	ft_checkdir(char *dir, char flag)
{
	DIR	*di;

	if (flag == 0 || flag == 'L')
	{
		if (access(dir, X_OK) == 0)
		return (0);
	}
	else if (flag == 'P')
	{
		if (di = opendir(dir) == 0)
			return (0);
	}
	else
		return (-1);
}
