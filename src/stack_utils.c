/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:38:41 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/24 14:17:50 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

t_list	*ft_lstlast(t_list *head)
{
	// printf("head->prev = %i\n", head->prev);
	return (head->prev);
}

size_t	ft_lstsize(t_list *lst)
{
	void	*last_node;
	size_t		i;

	if (!lst)
		return (0);
	last_node = lst;
	i = 1;
	while (lst->next != last_node)
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
	size_t		i;
	
	i = 0;
	temp = lst;
	size = ft_lstsize(lst);
	while (i < size)
	{
		printf("node = %d   idx = %d|\n", temp->val, temp->idx);
		temp = temp->next;
		i++;
	}
	if (lst == NULL)
		printf("lst = NULL\n");
}

int	get_max(t_list **stack)
{
	int 	max;
	int		size;
	t_list	*cur;
	int		temp;

	size = ft_lstsize(*stack);
	cur = (*stack);
	max = cur->val;
	while (size)
	{
		temp = cur->val;
		cur = cur->next;
		if (max < temp)
			max = temp;
		size--;
	}
	printf("max = %d\n", max);
	return (max);
}

int	get_min(t_list **stack)
{
	int 	min;
	int		size;
	t_list	*cur;
	int		temp;

	size = ft_lstsize(*stack);
	cur = (*stack);
	min = cur->val;
	while (size)
	{
		temp = cur->val;
		cur = cur->next;
		if (min > temp)
			min = temp;
		size--;
	}
	printf("min = %d\n", min);
	return (min);
}