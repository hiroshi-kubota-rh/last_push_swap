/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:22:46 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 00:28:22 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sub_input_5_2(t_node **a, t_node **b, size_t j, size_t min_place)
{
	while (min_place + 4 - 5 > j)
	{
		rotate_a(a);
		j++;
	}
	push_b(a, b);
}

static void	sub_input_5_1(t_node **a, t_node **b)
{
	size_t	min_place;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 2)
	{
		min_place = get_smallest_ele_place(*a);
		j = 0;
		if (min_place == 4 || min_place == 5)
		{
			while (5 - min_place + 1 - i > j)
			{
				revrotate_a(a);
				j++;
			}
			push_b(a, b);
		}
		if (min_place == 1 || min_place == 2 || min_place == 3)
			sub_input_5_2(a, b, j, min_place);
		i++;
	}
}

void static	check_stack_b(t_node **b)
{
	if ((*b)->index < (*b)->next->index)
		swap_b(b);
	else
		return ;
}

void	input_5(t_node **a, t_node **b)
{
	sub_input_5_1(a, b);
	input_3(a);
	check_stack_b(b);
	push_a(a, b);
	push_a(a, b);
}
