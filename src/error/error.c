/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:02:28 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 00:03:05 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_node *stack_a, t_node *stack_b, t_info *info)
{
	flash_all_struct(stack_a, stack_b, info);
	write(2, "error\n", 6);
	exit(1);
}
