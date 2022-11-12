/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:18:01 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 00:22:20 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_smallest_ele_place(t_node *stack)
{
	size_t	i;
	size_t	tmp;
	size_t	place;

	i = 1;
	place = 1;
	tmp = stack->index;
	while (stack->next != NULL)
	{
		i++;
		if (tmp > stack->next->index)
		{
			place = i;
			tmp = stack->next->index;
		}
		stack = stack->next;
	}
	return (place);
}

void	sub_input_4(t_node **a, t_node **b)
{
	size_t	min_place;
	size_t	i;

	min_place = get_smallest_ele_place(*a);
	i = 0;
	if (min_place == 3 || min_place == 4)
	{
		while (4 - min_place + 1 > i)
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
		push_b(a, b);
}

void	input_4(t_node **a, t_node **b)
{
	sub_input_4(a, b);
	input_3(a);
	push_a(a, b);
}
