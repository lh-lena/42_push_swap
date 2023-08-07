#include "push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*temp;

	if (*stack == NULL)
	{
		printf("Stack empty\n");
        return ;
	}
	temp = *stack;
	while (temp)
	{
		temp = *stack;
		*stack = temp->next;
		free(temp);
	}
}

t_list	*ft_lstnew(int content)
{
    t_list  *new;

    new = (t_list *)malloc(sizeof(t_list));
    if (!new)
        return (NULL);
    new->content = content;
    new->next = NULL;
    return (new);
}

// to insert a new node at the end
void	push_back(t_list **head, int val)
{
	t_list	*last;
	t_list	*new;

	new = ft_lstnew(val);
	if (!new)
	{
		printf("new node wasn't created\n");
		free_stack(head);
	}
	last = NULL;
	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return ;
	}
	last = *head;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	new->prev = last;
	return ;
}

// add-front
void	push_front(t_list **head, int val)
{
	t_list	*new_node;
	new_node = (t_list *)malloc(sizeof(t_list));
	new_node->content = val;
	new_node->next = (*head);
	(*head) = new_node;
}

//removing the first item
int		pop_first(t_list **head)
{
	int	retval;
	t_list	*cur;

	cur = NULL;
	if (*head == NULL)
		return (-1);
	cur = (*head)->next;
	retval = (*head)->content;
	free(head);
	*head = cur;
	return (retval);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	int		i;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

void	print_lst(t_list **lst)
{
	t_list	*cur;

	cur = *lst;
	while (cur)
	{
		printf("node = %d ", cur->content);
		cur = cur->next;
	}
}

// int    fill_stack(char *s)
// {
//     t_list  *stack_a;
// 	int		elem;

// 	stack_a = NULL;
// 	elem = atoi(s);
// 	// printf("check_digit(s) = %i\n", check_digit(s));
// 	// printf("check_dobl(&stack_a) = %i\n", check_dobl(&stack_a));
// 	if (check_digit(s) == 1)
// 		push_back(&stack_a, elem);
// 	else
// 	{
// 		free_stack(&stack_a);
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	if (check_dobl(&stack_a, elem) == 1)
// 	{
// 		free_stack(&stack_a);
// 		write(2, "Error\n", 6);
// 		return (0);
// 	}
// 	print_lst(&stack_a);
// 	return (1);
// }