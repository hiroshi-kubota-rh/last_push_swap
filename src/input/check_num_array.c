/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:24:30 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 02:29:46 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_num_array(t_info *info)
{
	size_t	i;
	int		*nums;
	bool	isSame;

	i = 0;
	while (i < info->num_array_len)
	{
		if (!ft_isInt((info->num_array)[i]))
			return (false);
		i++;
	}
	nums = (int *)malloc(sizeof(int) * (info->num_array_len));
	if (nums == NULL)
		return (false);
	i = 0;
	while (i < info->num_array_len)
	{
		nums[i] = ft_atoi((info->num_array)[i]);
		i++;
	}
	isSame = ft_isSameNum(nums, info->num_array_len);
	free (nums);
	if (isSame)
		return (false);
	return (true);
}

bool	ft_isSameNum(int *num, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (num[i] == num[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}
