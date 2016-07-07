/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:19:26 by jbester           #+#    #+#             */
/*   Updated: 2016/07/07 14:34:10 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINI_H__
# define __MINI_H__
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include "libft.h"

int		ft_changedir(char *line);
int		ft_checkdir(char *dir);
int		ft_currentdir(void);
int		ft_env(char **env);
//char	**old_pwd_change(char **env);
//char	**new_pwd_change(char **env);
char	**ft_setenv(char *line, char **env);
char	*ft_update_env(char **name);
char	**ft_set_new_env(char **env, char *name, char *value);
void	free_old_env(char **orig);
char	**ft_cpy_env(char **env, int extra);
int		ft_env_size(char **env);


#endif
