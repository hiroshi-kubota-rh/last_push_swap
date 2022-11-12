/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:32:26 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 00:34:05 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//this atoi is have to use after ft_is_int
int	ft_atoi(char *s)
{
	long	result;
	long	minus;

	result = 0;
	minus = 1;
	if (ft_strlen(s) > 11)
		return (false);
	if (*s == '+' || *s == '-')
	{
		if (*s++ == '-')
			minus = -1;
	}
	while ('0' <= *s && *s <= '9')
		result = ((*s++) - '0') + result * 10;
	result = result * minus;
	return ((int)result);
}
