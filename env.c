/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 09:15:01 by jbester           #+#    #+#             */
/*   Updated: 2016/07/05 08:55:26 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**new_pwd_change(char **env)
{
	int		l;
	char	*pwd;
	char	buf[4096];

	l = 0;
	getcwd(buf, 4096);
	pwd = "PWD=";
	pwd = ft_strjoin(pwd, buf);
	while (env[l] != NULL)
	{
		if (ft_strncmp(env[l], "PWD=", 4) == 0)
		{
			ft_strcpy(env[l], pwd);
			l++;
		}
		l++;
	}
	return (env);
}

char	**old_pwd_change(char **env)
{
	int		count;
	char	*newpwd;
	char	ar[4096];

	count = 0;
	getcwd(ar, 4096);
	newpwd = "OLDPWD=";
	newpwd = ft_strjoin(newpwd, ar);
	while (env[count] != NULL)
	{
		if (ft_strncmp(env[count], "OLDPWD=", 7) == 0)
		{
			ft_strcpy(env[count], newpwd);
			count++;
		}
		count++;
	}
	return (env);
}
