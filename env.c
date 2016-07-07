/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 09:15:01 by jbester           #+#    #+#             */
/*   Updated: 2016/07/07 14:39:48 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_env_size(char **env)
{
	int	l;

	l = 0;
	while (env[l])
		l++;
	return (l);
}

char	**ft_cpy_env(char **env, int extra)
{
	int		count;
	char	**nenv;
	int		size;
	int		i;

	count = 0;
	i = 0;
	size = ft_env_size(env);
	nenv = (char **)malloc(sizeof(char *) * size + 1 + extra);
	while (env[count])
	{
		nenv[i] = ft_strdup(env[count]);
		count++;
		i++;	
	}
	return (nenv);
}

/*char	**new_pwd_change(char **env)
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
			return (env);
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
			return (env);
		}
		count++;
	}
	return (env);
}*/

char	**ft_setenv(char *line, char **env)
{
	int		count;
	int		i;
	char	**name;
	char	*temp;

	count = 0;
	name = ft_strsplit(line, ' ');
	i = ft_strlen(name[1]);
	while (env[count] != NULL)
	{
		if (ft_strncmp(env[count], name[1], i) == 0)
		{
			temp = ft_update_env(name);
			free(env[count]);
			env[count] = temp;
			return (env);
		}
		else
		{
			if (env[count + 1] == NULL)
				env = ft_set_new_env(env, name[1], name[2]);
		}
		count++;
	}
	return (env);
}
