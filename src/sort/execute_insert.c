/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_insert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:09:42 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 03:14:58 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_wapper(t_node **a, t_node **b, t_insert ins, t_exe *exe)
{
	while ((exe->a < ins.insertion_var) && (exe->b < ins.element))
	{
		rotate_ab(a, b);
		exe->a++;
		exe->b++;
	}
}

static void	rotate_node_a(t_node **a, t_insert ins, t_exe exe)
{
	if (ins.insertion_var > exe.alen / 2)
	{
		ins.insertion_var = exe.alen - ins.insertion_var;
		while (exe.a < ins.insertion_var)
		{
			revrotate_a(a);
			exe.a++;
		}
	}
	else
	{
		while (exe.a < ins.insertion_var)
		{
			rotate_a(a);
			exe.a++;
		}
	}
}

static void	rotate_node_b(t_node **b, t_insert ins, t_exe exe)
{
	if (ins.element > ins.blen / 2)
	{
		ins.element = ins.blen - ins.element;
		while (exe.b < ins.element)
		{
			revrotate_b(b);
			exe.b++;
		}
	}
	else
	{
		while (exe.b < ins.element)
		{
			rotate_b(b);
			exe.b++;
		}
	}
}

void	execute_insert(t_node **a, t_node **b, t_insert ins)
{
	t_exe	exe;

	exe.a = 0;
	exe.b = 0;
	exe.alen = ft_node_len(*a);
	if ((ins.insertion_var > exe.alen / 2) && (ins.element > ins.blen / 2))
	{
		while ((exe.a < exe.alen - ins.insertion_var) && \
				(exe.b < ins.blen - ins.element))
		{
			revrotate_ab(a, b);
			exe.a++;
			exe.b++;
		}
	}
	else if ((ins.insertion_var < exe.alen / 2) && (ins.element < ins.blen / 2))
		rotate_wapper(a, b, ins, &exe);
	rotate_node_a(a, ins, exe);
	rotate_node_b(b, ins, exe);
	push_a(a, b);
}
