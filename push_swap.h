/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:11:36 by ohladkov          #+#    #+#             */
/*   Updated: 2023/12/03 18:25:50 by ohladkov         ###   ########.fr       */
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

typedef struct s_details
{
	int				upward;
	int				downward;
	struct s_list	*min;
	struct s_list	*max;
}				t_details;

typedef struct s_list
{
	int				val;
	int				idx;
	int				pos;
	int				above_median;
	struct s_list	*prev;
	struct s_list	*next;
}				t_list;

size_t	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
void	free_arr(char **ptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		is_valid(const char *s);
int		ft_atoi(const char *str);
int		ft_isdigit(char c);
int		check_edge(const char *s, int sign);
int		check_duplicate(t_list *stack_a);
int		is_sorted(t_list *stack_a);
int		is_cyclic(t_list *stack);
int		is_rev_sorted(t_list *stack);

t_list	*parse_argv(char **argv);
t_list	*fill_in_stack(int argc, char **argv);
size_t	ft_lstsize(t_list *lst);
t_list	*ft_lstnew(int val);
t_list	*ft_lstlast(t_list *head);
t_list	*get_max(t_list *stack);
t_list	*get_min(t_list *stack);
t_list	*get_next_min(t_list *stack, int min);

void	display_error(void);
void	free_stack(t_list *stack, void *last);
void	ft_add_back(t_list **head, t_list *new_node);
void	ft_add_front(t_list **head, t_list *new_node);
void	delete_first_node(t_list **head);

void	set_cur_pos(t_list *stack);
void	fill_indexes(t_list *stack);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sort_small_stack(t_list **a, t_list **b);
void	sort_big_stack(t_list **a, t_list **b);
void	sort_three_stack(t_list **stack_a);
void	sort_five_stack(t_list **stack_a, t_list **stack_b);
void	rev_sort(t_list **a, t_list **b);
void	cyclic_sort(t_list	**a);

void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

#endif