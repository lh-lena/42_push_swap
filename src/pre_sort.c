/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:09:29 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/30 17:42:12 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../push_swap.h"

// t_list	*get_node_by_idx(t_list *stack, int idx)
// {
// 	t_list	*cur;

// 	if (stack == NULL)
// 		return (NULL);
// 	cur = stack;
// 	printf("cur->idx = %d\n", cur->idx);
// 	while (cur->next != stack)
// 	{
// 		if (cur->idx == idx)
// 			return (cur);
// 		cur = cur->next;
// 	}
// 	return (NULL);
// }

// static void	swap_idx(t_list **stack, int i, int j)
// {
// 	t_list	*node_i;
// 	t_list	*node_j;
// 	int		temp;

// 	node_i = get_node_by_idx(*stack, i);
// 	node_j = get_node_by_idx(*stack, j);
// 	if (node_i != NULL && node_j != NULL)
// 	{
// 		temp = node_i->idx;
// 		printf("node_i = %d\n", node_i->idx);
// 		node_i->idx = node_j->idx;
// 		printf("node_j = %d\n", node_j->idx);
// 		node_j->idx = temp;
// 	}
// }

// static void	swap(int *arr, int i, int j)
// {
// 	int	tmp;

// 	tmp = arr[i];
// 	arr[i] = arr[j];
// 	arr[j] = tmp;
// }

// int	partition(t_list *stack, int *arr, int low, int high)
// {
// 	int	pivot;
// 	int	i;
// 	int	j;

// 	pivot = arr[high];
// 	i = low - 1;
// 	j = low;
// 	while (j <= high - 1) 
// 	{
// 		if (arr[j] <= pivot)
// 		{
// 			i++;
// 			swap(arr, i, j);
// 			swap_idx(&stack, i, j);
// 		}
// 		j++;
// 	}
// 	swap(arr, i + 1, high);
// 	swap_idx(&stack, i + 1, high);
// 	return (i + 1);
// }

// void	quicksort(t_list *stack, int *arr, int start, int end)
// {
// 	int	pivot_idx;

// 	if (start < end)
// 	{
// 		pivot_idx = partition(stack, arr, start, end);
// 		quicksort(stack, arr, start, pivot_idx - 1);
// 		quicksort(stack, arr, pivot_idx + 1, end);
// 	}
// }

// int	*stack_duplicate(int *arr, t_list *stack)
// {
// 	int		i;
// 	t_list	*node;

// 	if (stack == NULL)
// 		return (NULL);
// 	i = 0;
// 	node = stack;
// 	arr = malloc(sizeof(int) * ft_lstsize(stack));
// 	if (!arr)
// 		return (0);
// 	while (node->next != stack)
// 	{
// 		arr[i] = node->val;
// 		node = node->next;
// 		i++;
// 	}
// 	arr[i] = node->val;
// 	return (arr);
// }

// void	idx_init(t_list *stack)
// {
// 	int		i;
// 	int		*arr;
// 	t_list	*node;
// 	int	j = 0;

// 	node = stack;
// 	arr = NULL;
// 	arr = stack_duplicate(arr, stack);
// 	if (!arr)
// 		return ;
// 	i = 0;
// 	while (node->next != stack)
// 	{
// 		node->idx = i;
// 		printf("node->idx = %d\n", node->idx);
// 		node = node->next;
// 		i++;
// 	}
// 	node->idx = i;
// 	printf("node->idx = %d\n", node->idx);
// 	quicksort(stack, arr, 0, (ft_lstsize(stack) - 1));
// 	printf("last node->idx = %d\n", node->idx);
// 	node = stack;
// 	//to print arr
// 	while (j <= i)
// 	{
// 		write(1, "arr - ", 4);
// 		printf("%d\n", arr[j]);
// 		j++;
// 	}
// 	free (arr);
// }
// // doesn't work
// // https://www.programiz.com/dsa/radix-sort