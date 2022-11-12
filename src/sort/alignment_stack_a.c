/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alignment_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:54:29 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 02:55:53 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alignment_stack_a(t_node **a, size_t len)
{
	size_t	smallest_p;

	smallest_p = get_smallest_ele_place(*a);
	if (smallest_p < len / 2)
	{
		while ((*a)->index != 1)
			rotate_a(a);
	}
	else
	{
		while ((*a)->index != 1)
			revrotate_a(a);
	}
}
