/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:02:13 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 01:03:35 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*s1;
	unsigned const char	*s2;

	s1 = (unsigned char *)dst;
	s2 = (unsigned const char *)src;
	if (dst || src)
	{
		while (n-- > 0)
			*s1++ = *s2++;
		return (dst);
	}
	return (NULL);
}
