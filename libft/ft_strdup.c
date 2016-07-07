/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmack <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 16:00:33 by tmack             #+#    #+#             */
/*   Updated: 2016/07/07 13:53:24 by jbester          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strdup(const char *source)
{
	char	*new;

	new = (char *)malloc(ft_strlen(source));
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, source);
	return (new);
}
