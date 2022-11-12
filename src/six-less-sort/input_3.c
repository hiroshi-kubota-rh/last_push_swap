/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:15:18 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 00:17:38 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_3(t_node **stack_a)
{
	size_t	front;
	size_t	middle;
	size_t	back;

	front = (*stack_a)->index;
	middle = (*stack_a)->next->index;
	back = (*stack_a)->next->next->index;
	if (front > middle && middle > back)
	{
		swap_a(stack_a);
		revrotate_a(stack_a);
	}
	else if (front > middle && back < front)
		rotate_a(stack_a);
	else if (front > middle && middle < back)
		swap_a(stack_a);
	else if (front < middle && back < front)
		revrotate_a(stack_a);
	else if (front < middle && back > front && middle > back)
	{
		revrotate_a(stack_a);
		swap_a(stack_a);
	}
	else
		return ;
}
