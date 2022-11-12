/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_element.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:02:51 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 03:04:55 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	biggest_element(t_node **a)
{
	t_node	*tmp;
	t_node	*tmp_2;
	size_t	max;
	size_t	i;

	tmp = *a;
	tmp_2 = *a;
	max = 0;
	while (tmp != NULL)
	{
		if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	i = 1;
	while (tmp_2->index != max)
	{
		i++;
		tmp_2 = tmp_2->next;
	}
	return (i);
}
