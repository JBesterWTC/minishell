/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 08:49:26 by jbester           #+#    #+#             */
/*   Updated: 2016/06/29 15:35:40 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**old_pwd_change(char **env)
{
	int		count;
	char	*newpwd;
	char	ar[4096];

	count = 0;
	getcwd(ar, 4096);
	newpwd = "OLDPWD=";
	newpwd = ft_strjoin(newpwd, ar);
	while (env[count] != '\0')
	{
		if (ft_strncmp(env[count], "OLDPWD=", 5))
		{
			ft_strcpy(env[count],  newpwd);
			return (env);
		}
		count++;
	}
	return (0);
}
