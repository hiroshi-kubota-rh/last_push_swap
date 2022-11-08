/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_not_sorted_to_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:57:45 by khiroshi          #+#    #+#             */
/*   Updated: 2022/10/12 09:59:56 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_not_sorted_to_b(t_node **a, t_node **b, size_t len)
{
    size_t  i;

    i = 0;
    while (i < len)
    {
        if ((*a)->sorted == 1)
            rotate_a(a);
        else
            push_b(a, b);
        i++;
    }
}
