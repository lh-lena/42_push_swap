/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:11:36 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/24 14:32:40 by ohladkov         ###   ########.fr       */
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

typedef struct s_save
{
	int i;
	int k;
}	t_save;

typedef struct s_details {
	int	min;
	int	max;
	int	c_upward;
	int	c_downward;
}	t_details;

typedef struct s_list
{
	int				val;
	int				idx;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

char	**ft_split(char *str, char c);
int		ft_countw(char *str, char c);
char	*ft_allocwrd(char const *str, char c);
void	free_arr(char **ptr);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_isdigit(char c);
bool	check_edge(const char *s, int sign);
bool	is_valid(const char *s);

// void	check_args(int argc, char **argv);

void	display_error(void);
void	free_stack(t_list *stack, void *last);
t_list	*fill_in_stack(int argc, char **argv);
bool	check_duplicate(t_list **stack_a);
t_list	*parse_argv(char **argv);

int		is_cyclic(t_list **stack);
int		is_rev_sorted(t_list **stack);

t_list	*ft_lstnew(int val);
void	ft_add_back(t_list **head, t_list *new_node);
void	ft_add_front(t_list **head, t_list *new_node);
void	delete_first_node(t_list **head);
size_t	ft_lstsize(t_list *lst);
void	print_lst(t_list *lst);

bool	is_sorted(t_list **stack_a);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sort_small_stack(t_list **a, t_list **b);
void	sort_big_stack(t_list **a, t_list **b);
void	sort_3_stack(t_list **stack_a);
void	sort_5_stack(t_list **stack_a, t_list **stack_b);
int		get_max(t_list **stack);
int 	get_min(t_list **stack);
void	positive_sort(t_list **a, t_list **b, t_save *save, int args);
void	b_pos_sort(t_list **a, t_list **b, t_save *save);
void	negative_sort(t_list **a, t_list **b, t_save *save, int args);
void	b_neg_sort(t_list **a, t_list **b, t_save *save);

int 	partition(t_list *stack, int *arr, int low, int high);
t_list	*get_node_by_idx(t_list *stack, int idx);
void	quicksort(t_list *stack, int *arr, int start, int end);
int		stack_dup(t_list *stack);


void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
// void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void 	rrr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

#endif
