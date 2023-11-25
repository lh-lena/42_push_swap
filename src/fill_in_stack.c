/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:39:39 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/24 14:17:50 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int val)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->val = val;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

// to insert a new node at the end
void	ft_add_back(t_list **head, t_list *new_node)
{
	t_list	*last;

	if (head)
	{
		if (*head == NULL)
		{
			(*head) = new_node;
			(*head)->next = new_node;
			(*head)->prev = new_node;
			return ;
		}
		last = (*head);
		while (last->next != *head)
			last = last->next;
		if (new_node)
		{
			last->next = new_node;
			new_node->prev = last;
			(*head)->prev = new_node;
			new_node->next = (*head);
		}
	}
}

// add-front
void	ft_add_front(t_list **head, t_list *new_node)
{
	if (!*head)
	{
		(*head) = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		return ;
	}
	new_node->prev = (*head)->prev;
	new_node->next = (*head);
	(*head)->prev->next = new_node;
	(*head)->prev = new_node;
	(*head) = new_node;
}

//removing the first node
void	delete_first_node(t_list **head)
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

// int    fill_stack(char *s)
// {
//     t_list  *stack_a;
// 	int		elem;

// 	stack_a = NULL;
// 	elem = atoi(s);
// 	// printf("is_valid(s) = %i\n", is_valid(s));
// 	// printf("check_dobl(&stack_a) = %i\n", check_dobl(&stack_a));
// 	if (is_valid(s) == 1)
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