/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:17:07 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 03:32:43 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	count_tmp_rb(t_node *a, t_node *b)
{
	t_node			*tmp_a;
	t_sub_insert	sub;

	sub.index = 0;
	sub.i_place = 0;
	sub.flag = false;
	sub.tmp = INT_MAX;
	tmp_a = a;
	while (tmp_a != NULL)
	{
		sub.diff = (int)(tmp_a->index - b->index);
		if (sub.diff < sub.tmp && sub.diff > 0)
		{
			sub.tmp = sub.diff;
			sub.i_place = sub.index;
			sub.flag = true;
		}
		tmp_a = tmp_a->next;
		sub.index++;
	}
	if (sub.flag == false)
		sub.i_place = biggest_element(&a);
	return (sub.i_place);
}

//bの中をどう動かせば，aの正確な場所にinsertできるのかを調べている
size_t	count_rb(t_node **a, t_node *tmp_b, size_t *r_num)
{
	t_node	*tmp_a;
	size_t	alen;
	size_t	count;

	tmp_a = *a;
	alen = ft_node_len(tmp_a);
	count = count_tmp_rb(tmp_a, tmp_b);
	if (count > alen / 2)
		(*r_num) = alen - count;
	else
		(*r_num) = count;
	return (count);
}

void	get_info_for_insert(t_node **a, t_node *tmp_b, t_insert *ins)
{
	t_node	*tmp_a;

	while (tmp_b != NULL)
	{
		ins->r_num = 0;
		tmp_a = *a;
		ins->ins_tmp = count_rb(&tmp_a, tmp_b, &ins->r_num);
		if (ins->i > ins->blen / 2)
			ins->r_num_b = ins->blen - ins->i;
		else
			ins->r_num_b = ins->i;
		ins->r_num = ins->r_num + ins->r_num_b;
		if (ins->tmp > ins->r_num)
		{
			ins->tmp = ins->r_num;
			ins->element = ins->i;
			ins->insertion_var = ins->ins_tmp;
		}
		tmp_b = tmp_b->next;
		ins->i++;
	}
}

void	insert_to_a(t_node **a, t_node **b)
{
	t_node		*tmp_b;
	t_insert	ins;

	ins.i = 0;
	tmp_b = *b;
	ins.blen = ft_node_len(tmp_b);
	ins.tmp = UINT_MAX;
	get_info_for_insert(a, tmp_b, &ins);
	execute_insert(a, b, ins);
}

void	sort(t_node **a, t_node **b, size_t len)
{
	t_permu	p;

	permulen_index(a, &p.i_head_place);
	set_sorted_by_index(a, p.i_head_place);
	push_not_sorted_to_b(a, b, len);
	while ((*b) != NULL)
		insert_to_a(a, b);
	alignment_stack_a(a, len);
}
