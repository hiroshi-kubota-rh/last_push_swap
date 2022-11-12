/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:44:51 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 02:46:34 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_node **a, t_node **b)
{
	t_node	*new;

	new = *b;
	if (new == NULL)
	{
		return ;
	}
	*b = new->next;
	new->next = *a;
	*a = new;
	write(1, "pa\n", 3);
	return ;
}

void	push_b(t_node **a, t_node **b)
{
	t_node	*new;

	new = *a;
	if (new == NULL)
	{
		return ;
	}
	*a = new->next;
	new->next = *b;
	*b = new;
	write(1, "pb\n", 3);
	return ;
}
