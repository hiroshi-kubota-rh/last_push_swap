/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ans_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:57:45 by khiroshi          #+#    #+#             */
/*   Updated: 2022/10/12 09:59:56 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_ans_addback(t_ans **ans, t_ans *new)
{
    t_ans  *last;

    if (*ans == NULL)
    {
        *ans = new;
        return ;
    }
    last = *ans;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new;
    return ;
}