/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:57:45 by khiroshi          #+#    #+#             */
/*   Updated: 2022/10/12 09:59:56 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//stack aを整列させる
void    alignment_stack_a(t_node **a, size_t len)
{
    size_t  smallest_p;

    smallest_p = get_smallest_ele_place(*a);
    if (smallest_p < len / 2)
    {
        while((*a)->index != 1)
            rotate_a(a);
    }
    else
    {
        while((*a)->index != 1)
            revrotate_a(a);
    }
}

//aの中で一番
size_t  biggest_element(t_node **a)
{
    t_node  *tmp;
    size_t  max;
    size_t  i;

    tmp = *a;
    max = 0;
    while (tmp != NULL)
    {
        if (max < tmp->index)
            max = tmp->index;
        tmp = tmp->next;
    }
    i = 1;
    tmp = *a;
    while (tmp->index != max)
    {
        i++;
        tmp = tmp->next;
    }
    return i;
}

size_t  count_tmp_rb(t_node *a, t_node *b)
{
    t_node          *tmp_a;
    t_sub_insert    sub;

    sub.index = 0;
    sub.i_place = 0;
    sub.flag = false;
    sub.tmp = UINT_MAX;
    tmp_a = a;
    while (a != NULL)
    {
        sub.diff = tmp_a->index - b->index;
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
        sub.i_place = biggest_element(&tmp_a);
    return (sub.i_place);
}

//bの中をどう動かせば，aの正確な場所にinsertできるのかを調べている
size_t  count_rb(t_node **a, t_node *tmp_b, size_t *r_num)
{
    t_node  *tmp_a;
    size_t  a_len;
    size_t  count;

    tmp_a = *a;
    a_len = ft_node_len(tmp_a);
    count = count_tmp_rb(tmp_a, tmp_b);
    if (count > a_len / 2)
        (*r_num) = a_len - count;
    else
        (*r_num) = count;
    return count;
}

void    get_info_for_insert(t_node **a, t_node *tmp_b, t_insert *ins)
{
    t_node  *tmp_a;

    while (tmp_b != NULL)
    {
        ins->r_num = 0;
        tmp_a = *a;
        ins->ins_tmp = count_rb(&tmp_a, tmp_b, &ins->r_num);
        tmp_b->place = ins->ins_tmp;
        if (ins->i > ins->blen/2)
            ins->r_num_b = ins->blen - ins->i;
        else
            ins->r_num_b = ins->i;
        ins->r_num = ins->r_num + ins->r_num_b;
        tmp_b->r_num = ins->r_num;
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

void    rotate_wapper(t_node **a, t_node **b, t_insert ins, t_exe *exe)
{
    while ((exe->a < ins.insertion_var) && (exe->b < ins.element))
    {
        rotate_ab(a, b);
        exe->a++;
        exe->b++;
    }
}

void    rotate_node_a(t_node **a, t_insert ins, t_exe exe)
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

void    rotate_node_b(t_node **b, t_insert ins, t_exe exe)
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

void    execute_insert(t_node **a, t_node **b, t_insert ins)
{
    t_exe   exe;

    exe.a = 0;
    exe.b = 0;
    exe.alen = ft_node_len(*a);
    if ((ins.insertion_var > exe.alen /2) && (ins.element > ins.blen / 2))
    {
        while ((exe.a < exe.alen - ins.insertion_var) && (exe.b < ins.blen - ins.element))
        {
            revrotate_ab(a, b);
            exe.a++;
            exe.b++;
        }
    }
    else if ((ins.insertion_var < exe.alen / 2) && (ins.element <ins.blen / 2))
        rotate_wapper(a, b, ins, &exe);
    rotate_node_a(a, ins, exe);
    rotate_node_b(b, ins, exe);
    push_a(a, b);
}

void    insert_to_a(t_node **a, t_node **b)
{
    t_node      *tmp_b;
    t_insert    ins;

    ins.i = 0;
    tmp_b = *b;
    ins.blen = ft_node_len(tmp_b);
    ins.tmp = UINT_MAX;
    get_info_for_insert(a, tmp_b, &ins);
    execute_insert(a, b, ins);
}

void    sort(t_node **a, t_node **b, size_t len)
{
    t_permu p;

    p.v_len = permulen_value(a, &p.v_head_place);
    p.i_len = permulen_index(a, &p.i_head_place);
    if (p.v_len > p.i_len)
        set_sorted_by_value(a, p.v_head_place);
    else
        set_sorted_by_index(a, p.i_head_place);
    push_not_sorted_to_b(a, b, len);
    while ((*b) != NULL)
        insert_to_a(a, b);
//    alignment_stack_a(a, len);
}

