/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permu.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:56:20 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 03:00:31 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	sub_permulen_index(t_node **tmp_head)
{
	t_node	*m;
	size_t	count;
	size_t	tmp;

	m = *tmp_head;
	count = 1;
	tmp = m->value;
	while (m->next != NULL)
	{
		m = m->next;
		if (m->index == tmp + 1)
		{
			count++;
			tmp = m->index;
		}
	}
	return (count);
}

size_t	permulen_index(t_node **a, size_t *h_p)
{
	t_node	*m;
	t_p		pv;

	pv.f = 0;
	pv.index = 0;
	pv.count = 0;
	m = *a;
	pv.re = sub_permulen_index(&m);
	while (m->next != NULL)
	{
		m = m->next;
		pv.index++;
		pv.count = sub_permulen_index(&m);
		if (pv.count > pv.re)
		{
			*h_p = pv.index;
			pv.re = pv.count;
			pv.f = 1;
		}
	}
	if (pv.f == 0)
		*h_p = 0;
	return (pv.re);
}
