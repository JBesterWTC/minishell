/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:19:26 by jbester           #+#    #+#             */
/*   Updated: 2016/07/05 08:08:45 by jbester          ###   ########.fr       */
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
char	**old_pwd_change(char **env);
char	**new_pwd_change(char **env);

#endif
