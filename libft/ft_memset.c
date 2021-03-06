/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrummuka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:07:20 by jrummuka          #+#    #+#             */
/*   Updated: 2021/11/03 13:08:16 by jrummuka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int ch, size_t n)
{
	char	*str;

	str = (char *) s;
	while (n--)
	{
		*str++ = ch;
	}
	return (s);
}
