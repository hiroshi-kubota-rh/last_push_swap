/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:30:59 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 02:33:06 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack(int argc, char **argv, t_node **stack_a, t_info *info)
{
	check_argc(argc, &(info->input_type));
	set_num_array(argv, info);
	set_num_array_len(info, argc);
	if (check_num_array(info))
	{
		fill_stack_a(stack_a, info);
		coordinate_compression(*stack_a, info);
	}
	else
	{
		error(NULL, NULL, info);
	}
	return ;
}
