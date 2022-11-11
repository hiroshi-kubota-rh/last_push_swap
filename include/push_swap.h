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


typedef struct  s_node
{
    int				value;
    size_t			index;
    bool 			sorted;//すでにsort済みかどうかの確認
    struct s_node	*next;
}               t_node;

typedef struct  s_info
{
    char	**num_array;  //argv[1]以降の要素を格納
    size_t  num_array_len;
    int		input_type; //input_typeをみている．
    bool    input_error; //input_errorを保管
}               t_info;

typedef struct  s_permu
{
    size_t  v_len;
    size_t  i_len;
    size_t  v_head_place;
    size_t  i_head_place;
}               t_permu;

typedef struct  s_p
{
    size_t  f;
    size_t  count;
    size_t  re;
    size_t  index;

}               t_p;

typedef struct  s_insert
{
    size_t  i;
    size_t  blen;
    size_t  tmp;
    size_t  ins_tmp;
    size_t  r_num_b;
    size_t  r_num;
    size_t  element; //存在が謎
    size_t  insertion_var; //存在が謎
}               t_insert;

typedef struct  s_sub_insert
{
    size_t  index;
    size_t  i_place;
    int  tmp;
    bool    flag;
    int  diff;
}               t_sub_insert;

typedef struct  s_exe
{
    size_t  a;
    size_t  b;
    size_t  alen;
}              t_exe;


/*------------------------- input folder -------------------------*/
void            check_argc(int argc, int *input_type);
void            set_num_array(char **argv, t_info *info);
void            set_num_array_len(t_info *info, int argc);
bool            check_num_array(t_info *info);
bool            ft_isSameNum(int *num, size_t len);
void            fill_stack_a(t_node **head_a, t_info *info);
void            make_stack(int argc, char **argv, t_node **head_a, t_info *info);
void            coordinate_compression(t_node *stack, t_info *info);
bool            check_sorted(t_node *stack);


/*------------------------- utils folder -------------------------*/
size_t          ft_strlen(char *str);
char		    **ft_split(char const *s, char c);
bool            ft_isInt(char *s);
int             ft_atoi(char *s);
void	        *ft_memcpy(void *dst, const void *src, size_t n);
/*--for lst functions--*/
t_node          *ft_node_new(int value);
void            ft_node_addback(t_node **node, t_node *new);
size_t          ft_node_len(t_node  *node);

/*------------------------- rule ----------------------------------*/
void            push_a(t_node **a, t_node **b);
void            push_b(t_node **a, t_node **b);
void            swap_a(t_node **a);
void            swap_b(t_node **b);
void            rotate_a(t_node **a);
void            rotate_b(t_node **b);
void            rotate_ab(t_node **a, t_node **b);
void            revrotate_a(t_node **a);
void            revrotate_b(t_node **b);
void            revrotate_ab(t_node **a, t_node **b);

/*-------------------- six_less_sort -----------------------------*/
void            six_less_sort(t_node **a, t_node **b, size_t len);
void            input_2(t_node **stack_a);
void            input_3(t_node **stack_a);
void            input_4(t_node **a, t_node **b);
void            sub_input_4(t_node **a, t_node **b);
void            input_5(t_node **a, t_node **b);
size_t          get_smallest_ele_place(t_node *stack);


/*------------------------ sort ----------------------------------*/
size_t          permulen_value(t_node **a, size_t  *h_p);
size_t          permulen_index(t_node **a, size_t  *h_p);
void            set_sorted_by_index(t_node **a, size_t h_p);
void            set_sorted_by_value(t_node **a, size_t h_p);
void            push_not_sorted_to_b(t_node **a, t_node **b, size_t len);
void            alignment_stack_a(t_node **a, size_t len);
void            execute_insert(t_node **a, t_node **b, t_insert ins);
size_t          biggest_element(t_node **a);
void            sort(t_node **a, t_node **b, size_t len);


/*------------------------ error ---------------------------------*/
void            error(t_node *stack_a, t_node *stack_b, t_info *info);
void            flash_stack(t_node  *stack);
void            flash_all_struct(t_node *stack_a, t_node *stack_b, t_info *info);


bool            check_sorted(t_node *stack);

#endif //PUSHSWAP_H
