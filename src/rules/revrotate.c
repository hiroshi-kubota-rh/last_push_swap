/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:57:45 by khiroshi          #+#    #+#             */
/*   Updated: 2022/10/12 09:59:56 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    revrotate(t_node **stack)
{
    t_node  *tmp;
    t_node  *tmp2;

    if ((*stack)->next == NULL)
    {
        return ;
    }
    tmp2 = *stack;
    while (tmp2->next->next != NULL)
    {
        tmp2 = tmp2->next;
    }
    tmp = tmp2->next;
    tmp->next = *stack;
    *stack = tmp;
    tmp2->next = NULL;
}

void     revrotate_a(t_node **a)
{
    revrotate(a);
    write(1, "rra\n", 4);
}

void     revrotate_b(t_node **b)
{
    revrotate(b);
    write(1, "rrb\n", 4);
}

void     revrotate_ab(t_node **a, t_node **b)
{
    revrotate(a);
    revrotate(b);
    write(1, "rrr\n", 4);
}