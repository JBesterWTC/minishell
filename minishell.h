/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbester <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:19:26 by jbester           #+#    #+#             */
/*   Updated: 2016/06/23 15:07:33 by jbester          ###   ########.fr       */
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

typedef struct	s_commands
{
	int		cd;
	int		pwd;
	int		ls;
	int		exit;
	int		setenv;
	int		unsetenv;
	char	*line;
}				t_commands;

int	ft_changedir(char *line);
int	ft_checkdir(char *dir, char flag);
int	ft_currentdir(void);

#endif
