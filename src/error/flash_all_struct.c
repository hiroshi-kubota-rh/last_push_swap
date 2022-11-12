/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flash_all_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:06:41 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 00:08:10 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	flash_all_struct(t_node *stack_a, t_node *stack_b, t_info *info)
{
	int	i;

	i = 0;
	if (info->input_type == 1)
	{
		while ((info->num_array)[i] != NULL)
		{
			free((info->num_array)[i]);
			i++;
		}
		free (info->num_array);
	}
	if (stack_a != NULL)
		flash_stack(stack_a);
	if (stack_b != NULL)
		flash_stack(stack_a);
	return ;
}
