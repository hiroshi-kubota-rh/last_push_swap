/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:57:45 by khiroshi          #+#    #+#             */
/*   Updated: 2022/10/12 09:59:56 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    make_stack(int argc, char **argv, t_node **stack_a, t_info *info)
{
    check_argc(argc, &(info->input_type));      //argcの数によってflagを立てる
    set_num_array(argv, info);                  //num_arrayの形を揃える
    set_num_array_len(info, argc);              //num_arrayの長さをgetする
    if (check_num_array(info))                  //num_arrayの中身をcheckする
    {
        fill_stack_a(stack_a, info);
        coordinate_compression(*stack_a, info);
    } else
    {
        error(NULL, NULL, info);
    }
    return ;
}
