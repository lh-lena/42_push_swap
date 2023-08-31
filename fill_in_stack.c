/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:39:39 by ohladkov          #+#    #+#             */
/*   Updated: 2023/08/21 15:14:27 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *stack, void	*last)
{
	// if ((void*)stack == NULL || !stack)
	// {
	// 	printf("Stack empty\n");
    //     return ;
	// }
	if (stack)
	{
		if (stack != last)
			free_stack(stack->next, last);
		free(stack);
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
	new->prev = NULL;
    return (new);
}

// to insert a new node at the end
void	ft_add_back(t_list **head, t_list *newNode)
{
	t_list	*last;

	if (head)
	{
		if (*head == NULL)
		{
			(*head) = newNode;
			(*head)->next = newNode;
			(*head)->prev = newNode;
			return ;
		}
		last = (*head);
		while (last->next != *head)
			last = last->next;
		if (newNode)
		{
			last->next = newNode;
			newNode->prev = last;
			(*head)->prev = newNode;
			newNode->next = (*head);
		}
	}
}

// add-front
void	ft_add_front(t_list **head, t_list *newNode)
{
	if (!*head)
	{
		(*head) = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
		return ;
	}
	newNode->prev = (*head)->prev;
	newNode->next = (*head);
	(*head)->prev->next = newNode;
	(*head)->prev = newNode;
	(*head) = newNode;
}

//removing the first node
void	deleteFirstNode(t_list **head)
{
	if ((*head)->next == *head && (*head)->prev == *head)
		(*head) = NULL;
	else
	{
		(*head)->prev->next = (*head)->next;
		(*head)->next->prev = (*head)->prev;
		(*head) = (*head)->next;
	}
}

t_list	*ft_lstlast(t_list *head)
{
	// printf("head->prev = %i\n", head->prev);
	return (head->prev);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*temp;
	void	*lastNode;
	int		i;

	if (!lst)
		return (0);
	lastNode = lst;
	i = 1;
	while (lst->next != lastNode)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	print_lst(t_list *lst)
{
	t_list	*temp;
	size_t	size;
	int		i;
	
	i = 0;
	temp = lst;
	size = ft_lstsize(lst);
	while (i < size)
	{
		printf("node = %d | ", temp->content);
		temp = temp->next;
		i++;
	}
	if (lst == NULL)
    	printf("lst = NULL\n");
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