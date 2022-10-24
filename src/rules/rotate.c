/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:57:45 by khiroshi          #+#    #+#             */
/*   Updated: 2022/10/12 09:59:56 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    rotate(t_node **stack)
{
    t_node  *tmp;
    t_node  *tmp2;

    if ((*stack)->next == NULL)
    {
        return ;
    }
    tmp = *stack;
    (*stack) = (*stack)->next;
    tmp2 = *stack;
    while (tmp2->next != NULL)
    {
        tmp2 = tmp2->next;
    }
    tmp2->next = tmp;
    tmp->next = NULL;
}

void    rotate_a(t_node **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void    rotate_b(t_node **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void    rotate_ab(t_node **a, t_node **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}