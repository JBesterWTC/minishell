/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_update_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/07 09:08:26 by jbester           #+#    #+#             */
/*   Updated: 2016/07/07 14:33:30 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_update_env(char **name)
{
	char	*str;

	str = ft_strjoin(name[1], "=");
	str = ft_strjoin(str, name[2]);
	return (str);
}

char	**ft_set_new_env(char **env, char *name, char *value)
{
	char	**newenv;
	int		c;
	char	*line;

	c = 0;
	line = ft_strjoin(name, "=");
	line = ft_strjoin(line, value);
	newenv = ft_cpy_env(env, 1);
	free_old_env(env);
	while (newenv[c + 1] != NULL)
		c++;
	if (newenv[c + 1] == NULL)
		newenv[c] = ft_strdup(line);
	return (newenv);
}

void	free_old_env(char **orig)
{
	int	count;

	count = 0;
	while (orig[count])
	{
		free(orig[count]);
		count++;
	}
}
