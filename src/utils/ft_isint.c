/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isInt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:57:45 by khiroshi          #+#    #+#             */
/*   Updated: 2022/10/12 09:59:56 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check the string is only made form number and in the Interger
bool    ft_isInt(char *s)
{
    long    result;
    long    minus;

    result = 0;
    minus = 1;
    if (ft_strlen(s) > 11)
        return (false);
    if (*s == '+' || *s == '-')
    {
        if (*s++ == '-')
            minus = -1;
    }
    while( '0' <= *s && *s <= '9')
        result = ((*s++) - '0') + result * 10;
    result = result * minus;
    if ((*s < '0' || '9' < *s) && *s != '\0')
        return (false);
    if (result < INT_MIN || INT_MAX < result)
        return (false);
    return (true);
}