/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:10:21 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 00:14:42 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_2(t_node **stack_a)
{
	size_t	front;
	size_t	back;

	front = (*stack_a)->index;
	back = (*stack_a)->next->index;
	if (front > back)
	{
		swap_a(stack_a);
	}
	return ;
}
