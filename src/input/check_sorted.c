//
// Created by hiroshi_kubota on 2022/11/11.
//
#include "push_swap.h"

bool    check_sorted(t_node *stack)
{
    while(stack->next != NULL)
    {
        if (stack->value > stack->next->value)
            return (false);
        stack = stack->next;
    }
    return (true);
}