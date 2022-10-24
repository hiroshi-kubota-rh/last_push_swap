/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:57:45 by khiroshi          #+#    #+#             */
/*   Updated: 2022/10/12 09:59:56 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//check "./pushswap "1 2 3 4"" or "./pushswap 1 2 3 4"
void    check_argc(int argc, int *input_type)
{
    if (argc == 1)
    {
        exit(0);
    }
    else if (argc == 2)
    {
        *input_type = 1;
    }
    else
    {
        *input_type = 2;
    }
    return ;
}
