/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:57:45 by khiroshi          #+#    #+#             */
/*   Updated: 2022/10/12 09:59:56 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node  *sub_func(t_node *front, t_node *back, size_t index)
{
    t_node  *tmp;

    while (back != NULL)
    {
        if (0 < front->index && front->index < index)
        {
            front = front->next;
            back = back->next;
            continue ;
        }
        if (0 < back->index && back->index < index)
        {
            back = back->next;
            continue ;
        }
        if (front->value < back->value)
            tmp = front;
        else
            tmp = back;
        front = tmp;
        back = back->next;
    }
    return tmp;
}

void    coordinate_compression(t_node *stack, t_info *info)
{
    size_t i;
    t_node  *tmp;

    i = 1;
    while (i < info->num_array_len)
    {
        tmp = sub_func(stack, stack->next, i);
        tmp->index = i;
        i++;
    }
    tmp = stack;
    while (tmp->next != NULL)
    {
        if (tmp->index == 0)
            break;
        tmp = tmp->next;
    }
    tmp->index = i;
    return ;
}