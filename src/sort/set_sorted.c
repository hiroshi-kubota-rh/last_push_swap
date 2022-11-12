/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sorted.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:05:58 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 03:15:32 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_sorted_by_value(t_node **a, size_t h_p)
{
	t_node	*m;
	size_t	i;
	int		tmp;

	m = *a;
	i = 0;
	while (i < h_p)
	{
		m = m->next;
		i++;
	}
	tmp = m->value;
	m->sorted = true;
	while (m->next != NULL)
	{
		m = m->next;
		if (m->value > tmp)
		{
			m->sorted = true;
			tmp = m->value;
		}
		else
			m->sorted = false;
	}
}

void	set_sorted_by_index(t_node **a, size_t h_p)
{
	t_node	*m;
	size_t	i;
	size_t	tmp;

	m = *a;
	i = 0;
	while (i < h_p)
	{
		m = m->next;
		i++;
	}
	tmp = m->index;
	m->sorted = true;
	while (m->next != NULL)
	{
		m = m->next;
		if (m->index > tmp)
		{
			m->sorted = true;
			tmp = m->index;
		}
		else
			m->sorted = false;
	}
}
