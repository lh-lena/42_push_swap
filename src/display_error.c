/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:40:50 by ohladkov          #+#    #+#             */
/*   Updated: 2023/11/30 17:43:28 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	display_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_list *stack, void	*last)
{
	if (stack)
	{
		if (stack != last)
			free_stack(stack->next, last);
		free(stack);
	}
}
void	print_lst(t_list *lst)
{
	t_list	*temp;
	size_t	size;
	size_t	i;

	i = 0;
	temp = lst;
	size = ft_lstsize(lst);
	while (i < size)
	{
		printf(" node = %d | idx = %d | pos = %d\n", temp->val, temp->idx, temp->pos);
		temp = temp->next;
		i++;
	}
	if (lst == NULL)
		printf("lst = NULL\n");
}
