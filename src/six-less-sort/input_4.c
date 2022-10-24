/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:57:45 by khiroshi          #+#    #+#             */
/*   Updated: 2022/10/12 09:59:56 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t    get_smallest_ele_place(t_node *stack)
{
    size_t  place;

    place = 1;
    while (stack != NULL)
    {
        if (stack->index == 1)
        {
            return (place);
        }
        place++;
        stack = stack->next;
    }
    return (0);
}

void    sub_input_4(t_node **a, t_node **b)
{
    size_t  min_place;
    size_t  i;

    min_place = get_smallest_ele_place(*a);
    i = 0;
    if (min_place == 3 || min_place == 4)
    {
        while(4 - min_place + 1 > i)
        {
            revrotate_a(a);
            i++;
        }
        push_b(a, b);
    }
    if (min_place == 2)
    {
        rotate_a(a);
        push_b(a, b);
    }
    if (min_place == 1)
        push_a(a, b);
}


void    input_4(t_node **a, t_node **b)
{
    sub_input_4(a, b);
    input_3(a);
    push_a(a, b);
}