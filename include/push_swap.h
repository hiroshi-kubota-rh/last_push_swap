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


#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>


typedef struct s_node
{
    int				value;
    size_t			index;
    bool 			test;
    struct s_node	*next;
}			t_node;

typedef struct s_info
{
    char	**num_array;  //argv[1]以降の要素を格納
    size_t  num_array_len;
    int		input_type; //input_typeをみている．
    bool    input_error; //input_errorを保管
}			t_info;

typedef struct s_ans
{
    char            *rule;
    struct s_ans    *next;
}           t_ans;


/*------------------------- input folder -------------------------*/
void        check_argc(int argc, int *input_type);
void        set_num_array(char **argv, t_info *info);
void        set_num_array_len(t_info *info, int argc);
bool        check_num_array(t_info *info);
bool        ft_isSameNum(int *num, size_t len);
void        fill_stack_a(t_node **head_a, t_info *info);
void        make_stack(int argc, char **argv, t_node **head_a, t_info *info);
void        coordinate_compression(t_node *stack, t_info *info);


/*------------------------- utils folder -------------------------*/
size_t      ft_strlen(char *str);
char		**ft_split(char const *s, char c);
bool        ft_isInt(char *s);
int         ft_atoi(char *s);
void	    *ft_memcpy(void *dst, const void *src, size_t n);
/*--for lst functions--*/
t_node      *ft_node_new(int value);
void        ft_node_addback(t_node **node, t_node *new);

/*------------------------- rule ----------------------------------*/
void        push_a(t_node **a, t_node **b);
void        push_b(t_node **a, t_node **b);
void        swap_a(t_node **a);
void        swap_b(t_node **b);
void        rotate_a(t_node **a);
void        rotate_b(t_node **b);
void        rotate_ab(t_node **a, t_node **b);
void        revrotate_a(t_node **a);
void        revrotate_b(t_node **b);
void        revrotate_ab(t_node **a, t_node **b);


/*-------------------- six_less_sort -----------------------------*/
void        six_less_sort(t_node **a, t_node **b, size_t len);
void        input_2(t_node **stack_a);
void        input_3(t_node **stack_a);
void        input_4(t_node **a, t_node **b);
size_t      get_smallest_ele_place(t_node *stack);


void    sub_input_4(t_node **a, t_node **b);

/*------------------------ error ---------------------------------*/
void        error(t_node *stack_a, t_node *stack_b, t_info *info);
void        flash_stack(t_node  *stack);
void        flash_all_struct(t_node *stack_a, t_node *stack_b, t_info *info);


bool    check_sorted(t_node *stack);

#endif //PUSHSWAP_H
