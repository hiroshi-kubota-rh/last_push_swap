/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node_addback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khiroshi </var/mail/khiroshi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:34:33 by khiroshi          #+#    #+#             */
/*   Updated: 2022/11/12 00:35:30 by khiroshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_node_addback(t_node **node, t_node *new)
{
	t_node	*last;

	if (*node == NULL)
	{
		*node = new;
		return ;
	}
	last = *node;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = new;
	return ;
}

//
//gcc -I../../include ft_atoi.c ft_node_addback.c ft_node_new.c ft_strlen.c
//
//int main(int argc, char **argv)
//{
//    int i = 1;
//    t_node *stack_a = NULL;
//    t_node *new = NULL;
//
//    while ( i < argc ){
//        new = ft_new_node(ft_atoi(argv[i]));
//        ft_node_addback(&stack_a, new);
//        i++;
//    }
//    i = 1;
//    while( stack_a != NULL)
//    {
//        printf("i = %d value = %d\n", i, stack_a->value);
//        i++;
//        stack_a = stack_a->next;
//    }
//    return (0);
//}
