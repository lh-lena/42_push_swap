/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:39:39 by ohladkov          #+#    #+#             */
/*   Updated: 2024/08/01 11:30:26 by ohladkov         ###   ########.fr       */
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

/* to insert a new node at the end */
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

/* removing the first node */
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
