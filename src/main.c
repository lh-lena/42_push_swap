/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:40:26 by ohladkov          #+#    #+#             */
/*   Updated: 2023/12/14 14:41:38 by ohladkov         ###   ########.fr       */
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

t_list	*parse_argv(char **argv)
{
	t_list	*stack_a;
	char	**arr;
	int		i;
	t_list	*new_node;
	int		val;

	arr = ft_split(argv[1], 32);
	stack_a = NULL;
	i = 0;
	val = 0;
	new_node = NULL;
	while (arr[i])
	{
		if (is_valid(arr[i]) == false)
			return (NULL);
		val = ft_atoi(arr[i]);
		new_node = ft_lstnew(val);
		if (!new_node)
			return (NULL);
		ft_add_back(&stack_a, new_node);
		i++;
	}
	free_arr(arr);
	return (stack_a);
}

t_list	*fill_in_stack(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*new_node;
	int		i;

	stack_a = NULL;
	i = 1;
	new_node = NULL;
	if (argc == 2)
		stack_a = parse_argv(argv);
	else
	{
		while (i < argc)
		{
			if (is_valid(argv[i]) == false)
				return (NULL);
			new_node = ft_lstnew(ft_atoi(argv[i]));
			if (!new_node)
				return (NULL);
			ft_add_back(&stack_a, new_node);
			i++;
		}
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	stack_a = fill_in_stack(argc, argv);
	stack_b = NULL;
	if (!stack_a || check_duplicate(stack_a))
	{
		if (stack_a)
			free_stack(stack_a, stack_a->prev);
		display_error();
	}
	if (!is_sorted(stack_a))
		sort_stack(&stack_a, &stack_b);
	if (stack_a)
		free_stack(stack_a, stack_a->prev);
	if (stack_b)
		free_stack(stack_b, stack_b->prev);
	return (0);
}
