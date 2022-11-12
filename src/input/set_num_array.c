/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_num_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:35:52 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 02:36:54 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_num_array(char **argv, t_info *info)
{
	if (info->input_type == 1)
	{
		info->num_array = ft_split(argv[1], ' ');
		if (info->num_array == NULL)
			exit(0);
	}
	else if (info->input_type == 2)
	{
		info->num_array = &argv[1];
	}
	return ;
}
