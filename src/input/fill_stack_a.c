/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:57:45 by khiroshi          #+#    #+#             */
/*   Updated: 2022/10/12 09:59:56 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    fill_stack_a(t_node **stack_a, t_info *info)
{
    size_t i;
    t_node  *new;

    i = 0;
    while (i < info->num_array_len)
    {
        new = ft_node_new(ft_atoi((info->num_array)[i]));
        if (new == NULL)
        {
            error(*stack_a, NULL, info);
        }
        ft_node_addback(stack_a, new);
        i++;
    }
    return ;
}