#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_list
{
    int     content;
	int		index;
	struct s_list  *prev;
    struct s_list  *next;
}   t_list;

int		ft_atoi(const char *str);
int		ft_countw(char *str, char c);
char	*ft_allocwrd(char const *str, char c);
char	**ft_split(char *str, char c);
void	free_arr(int **ptr);
int		check_edge(char *s);
int		check_digit(char *s);
int		ft_isdigit(char c);
void	free_stack(t_list **head);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(char *str);
t_list	*ft_lstnew(int content);
void	push_back(t_list **head, int val);
void	push_front(t_list **head, int val);
int	    pop_first(t_list **head);
void	print_lst(t_list **lst);
void	display_error(void);
void	ft_putstr_fd(char *s, int fd);
bool	is_sorted_list(t_list *stack_a, int args_nb);
void	check_argv(int argc, char **argv, t_list **stack_a);
void	fill_lst(int argc, char **argv, t_list **stack_a);
void	lst_check(t_list **stack_a, int check);
void	check_argv(int argc, char **argv, t_list **stack_a);
void	check_d(int argc, char **argv);




// to add into stack b, i have to delete from stack a
// t_list stack_a
// t_list stack_b

#endif