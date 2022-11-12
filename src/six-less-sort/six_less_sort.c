/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   six_less_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:28:57 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 00:29:41 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	six_less_sort(t_node **a, t_node **b, size_t len)
{
	if (len == 2)
		input_2(a);
	if (len == 3)
		input_3(a);
	if (len == 4)
		input_4(a, b);
	if (len == 5)
		input_5(a, b);
}
