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

int main(int argc, char **argv)
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


    //mainから辿れるメモリはメモリリークにならない(leaksコマンドなら)
//    flash_all_struct(tmp, NULL, &info);
//    system("leaks push_swap");
//    flash_all_struct(stack_a, NULL, &info);
//    system("leaks push_swap");
    //input_typeが1の時はnum_arrayをfreeする
}







