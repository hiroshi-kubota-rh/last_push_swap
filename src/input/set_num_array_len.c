/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_num_array_len.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:42:48 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 02:44:04 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_num_array_len(t_info *info, int argc)
{
	int	len;

	len = 0;
	if (info->input_type == 1)
	{
		while ((info->num_array)[len] != NULL)
			len++;
	}
	else if (info->input_type == 2)
	{
		len = argc - 1;
	}
	info->num_array_len = (size_t)len;
	return ;
}
