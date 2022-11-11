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