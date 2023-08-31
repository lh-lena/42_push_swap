/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:40:20 by ohladkov          #+#    #+#             */
/*   Updated: 2023/08/21 13:35:01 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_list
{
    int				content;
	int				index;
	struct s_list  *prev;
    struct s_list  *next;
}   t_list;

int		ft_atoi(const char *str);
int		ft_countw(char *str, char c);
char	*ft_allocwrd(char const *str, char c);
char	**ft_split(char *str, char c);
void	free_arr(char **ptr);
int		ft_isdigit(char c);
// void    check_args(int argc, char **argv);
bool	check_edge(const char *s, int sign);
bool	check_digit(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(char *str);
void	display_error(void);
bool	check_sorted(t_list **stack_a);
t_list	*fill_in_stack(int argc, char **argv);
void	sort_stack(t_list **stack_a, t_list **stack_b);
bool	check_duplicate(t_list **stack_a);
t_list	*parse_argv(char **argv);


void	free_stack(t_list *stack, void *last);
t_list	*ft_lstnew(int content);
void	ft_add_back(t_list **head, t_list *newNode);
void	ft_add_front(t_list **head, t_list *newNode);
void	deleteFirstNode(t_list **head);
int		ft_lstsize(t_list *lst);
void	print_lst(t_list *lst);


void	sort_stack(t_list **stack_a, t_list **stack_b);
void    sort_3_stack(t_list **stack_a);
void    sort_5_stack(t_list **stack_a, t_list **stack_b);
// void    sort_big_stack(t_list **stack_a);

void    swap(t_list **stack);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void    ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
// void    rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

// to add into stack b, i have to delete from stack a
// t_list stack_a
// t_list stack_b

#endif