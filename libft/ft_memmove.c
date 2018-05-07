/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkwon <rkwon@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 06:20:31 by rkwon             #+#    #+#             */
/*   Updated: 2018/03/08 18:35:05 by rkwon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*cpy;

	if (src == NULL || dst == NULL)
		return (NULL);
	if (!(cpy = (char*)malloc(sizeof(char*) * len)))
		return (NULL);
	cpy = ft_strncpy(cpy, src, len);
	dst = (void*)ft_strncpy(dst, cpy, len);
	free(cpy);
	return (dst);
}