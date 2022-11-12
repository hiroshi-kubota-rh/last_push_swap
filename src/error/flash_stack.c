/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flash_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:05:29 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 00:05:57 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flash_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	return ;
}
