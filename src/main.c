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
#include <stdio.h>

int     main(int argc, char **argv)
{
    t_node  *stack_a;
    t_node  *stack_b;
    t_info  info;

    stack_a = NULL;
    stack_b = NULL;
    make_stack(argc, argv, &stack_a, &info);

    if (check_sorted(stack_a))
    {
        exit(0);
    }
    else
    {
        if (info.num_array_len < 6)
            six_less_sort(&stack_a, &stack_b, info.num_array_len);
        else
            sort(&stack_a, &stack_b, info.num_array_len);
    }


//    printf("inout type = %d\n", info.input_type);
//
//    char **test = info.num_array;
//    printf("info.num_array[1] = %s\n", test[1]);
//    printf("info.num_array_len = %ld\n", info.num_array_len);


//stackの中身表示

    int i = 1;
    t_node *tmp = stack_a;
    while( stack_a != NULL)
    {
        printf("i = %d, value = %d, index = %zu, sorted = %s\n", i, stack_a->value, stack_a->index, (stack_a->sorted ? "true" : "false" ));
        i++;
        stack_a = stack_a->next;
    }
    i = 1;
    printf("\n\nstack-b\n");
    while( stack_b != NULL)
    {
        printf("i = %d, value = %d, index = %zu, sorted = %s\n", i, stack_b->value, stack_b->index, (stack_b->sorted ? "true" : "false" ));
        i++;
        stack_b = stack_b->next;
    }


    //mainから辿れるメモリはメモリリークにならない(leaksコマンドなら)
//    flash_all_struct(tmp, NULL, &info);
//    system("leaks push_swap");
//    flash_all_struct(stack_a, NULL, &info);
//    system("leaks push_swap");
    //input_typeが1の時はnum_arrayをfreeする
}



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



