/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:45:21 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 00:47:06 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_node_len(t_node *node)
{
	size_t	len;

	len = 0;
	while (node != NULL)
	{
		node = node->next;
		len++;
	}
	return (len);
}
