/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:57:45 by khiroshi          #+#    #+#             */
/*   Updated: 2022/10/12 09:59:56 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t  sub_permulen_value(t_node   **tmp_head)
{
    t_node  *m;
    size_t  count;
    int     tmp;

    m = *tmp_head;
    count = 1;
    tmp = m->value;
    while (m->next != NULL)
    {
        m = m->next;
        if (m->value > tmp)
        {
            count++;
            tmp = m->value;
        }
    }
    return count;
}

size_t  permulen_value(t_node **a, size_t  *h_p)
{
    t_node  *m;
    t_p     pv;

    pv.f = 0;
    pv.index = 0;
    pv.count = 0;
    m = *a;
    pv.re = sub_permulen_value(&m);
    while (m->next != NULL)
    {
        m = m->next;
        pv.index++;
        pv.count = sub_permulen_value(&m);
        if (pv.count > pv.re)
        {
            *h_p = pv.index;
            pv.re = pv.count;
            pv.f = 1;
        }
    }
    if (pv.f == 0)
        *h_p = 0;
    return (pv.re);
}

static size_t  sub_permulen_index(t_node   **tmp_head)
{
    t_node  *m;
    size_t  count;
    size_t     tmp;

    m = *tmp_head;
    count = 1;
    tmp = m->index;
    while (m->next != NULL)
    {
        m = m->next;
        if (m->index == tmp + 1)
        {
            count++;
            tmp = m->index;
        }
    }
    return count;
}

size_t  permulen_index(t_node **a, size_t  *h_p)
{
    t_node  *m;
    t_p     pv;

    pv.f = 0;
    pv.index = 0;
    pv.count = 0;
    m = *a;
    pv.re = sub_permulen_index(&m);
    while (m->next != NULL)
    {
        m = m->next;
        pv.index++;
        pv.count = sub_permulen_index(&m);
        if (pv.count > pv.re)
        {
            *h_p = pv.index;
            pv.re = pv.count;
            pv.f = 1;
        }
    }
    if (pv.f == 0)
        *h_p = 0;
    return (pv.re);
}