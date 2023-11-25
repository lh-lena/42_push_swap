/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:09:29 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/24 14:17:50 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap_idx(t_list **stack, int i, int j)
{
	t_list	*node_i;
	t_list	*node_j;
	
	node_i = get_node_by_idx(*stack, i);
	node_j = get_node_by_idx(*stack, j);
	if (node_i != NULL && node_j != NULL) {
		int temp = node_i->idx;
		node_i->idx = node_j->idx;
		node_j->idx = temp;
	}
}
static void	swap(int *arr, int i, int j)
{
	int tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j]= tmp;
}
// Partition function for quicksort
int partition(t_list *stack, int *arr, int low, int high)
{
	int pivot;
	int i;
	int j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1) 
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(arr, i, j);
			swap_idx(&stack, i, j);
		}
		j++;
	}
	swap(arr, i + 1, j);
	swap_idx(&stack, i + 1, high);
	return (i + 1);
}
t_list	*get_node_by_idx(t_list *stack, int idx)
{
	t_list	*cur;

	cur = stack;
	while (cur != stack)
	{
		if (cur->idx == idx)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}
void	quicksort(t_list *stack, int *arr, int start, int end)
{
	int	pivot_idx;

	if (start < end)
	{
		pivot_idx = partition(stack, arr, start, end);
		quicksort(stack, arr, start, pivot_idx - 1);
		quicksort(stack, arr, pivot_idx + 1, end);
	}
}
int	stack_dup(t_list *stack)
{
	int		i;
	t_list	*node;
	int		*arr;

	if (stack == NULL)
		return (0);
	i = 0;
	node = stack;
	arr = malloc(sizeof(int) * ft_lstsize(stack));
	if (!arr)
		return (0);
	while (node->next != stack)
	{
		arr[i] = node->val;
		node->idx = i;
		node = node->next;
		i++;
	}
	arr[i] = node->val;
	node->idx = i;
	quicksort(stack, arr, 0, (ft_lstsize(stack) - 1));
	node = stack;
	free (arr);
	return (1);
}
