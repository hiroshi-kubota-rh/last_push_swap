/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:51:17 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 02:53:37 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_node **a)
{
	t_node	*tmp;
	t_node	*tmp2;

	if ((*a) == NULL || (*a)->next == NULL)
	{
		return ;
	}
	tmp = *a;
	tmp2 = (*a)->next->next;
	*a = (*a)->next;
	(*a)->next = tmp;
	(*a)->next->next = tmp2;
	write(1, "sa\n", 3);
}

void	swap_b(t_node **b)
{
	t_node	*tmp;
	t_node	*tmp2;

	if ((*b) == NULL || (*b)->next == NULL)
	{
		return ;
	}
	tmp = *b;
	tmp2 = (*b)->next->next;
	*b = (*b)->next;
	(*b)->next = tmp;
	(*b)->next->next = tmp2;
	write(1, "sa\n", 3);
}
