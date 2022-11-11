//
// Created by hiroshi_kubota on 2022/11/11.
//

#include "push_swap.h"

size_t  biggest_element(t_node **a)
{
    t_node  *tmp;
    t_node  *tmp_2;
    size_t  max;
    size_t  i;

    tmp = *a;
    tmp_2 = *a;
    max = 0;
    while (tmp != NULL)
    {
        if (max < tmp->index)
            max = tmp->index;
        tmp = tmp->next;
    }
    i = 1;
    while (tmp_2->index != max)
    {
        i++;
        tmp_2 = tmp_2->next;
    }
    return i;
}