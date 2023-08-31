/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:40:26 by ohladkov          #+#    #+#             */
/*   Updated: 2023/08/27 13:23:47 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*parse_argv(char **argv)
{
	t_list	*stack_a;
	char	**arr;
	int		i;
	t_list	*newNode;
	int		val;

	arr = ft_split(argv[1], 32);
	stack_a = NULL;
	i = 0;
	val = 0;
	newNode = NULL;
	while (arr[i])
	{
		// printf(" 0.1 check_digit(arr[i]) = %i\n", check_digit(arr[i]));
		// printf("arr[i] = %s", arr[i]);
		if (check_digit(arr[i]) == false)
		{
			printf(" 1 check_digit(argv[i]) = %i\n", check_digit(arr[i]));
			// display_error();
			return (NULL);
		}
		val = ft_atoi(arr[i]);
		newNode = ft_lstnew(val);
		if (!newNode)
			return (NULL);
		ft_add_back(&stack_a, newNode);
		i++;
	}
	free_arr(arr);
	return (stack_a);
}

t_list	*fill_in_stack(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*newNode;
	int		i;
	int		j;

	stack_a = NULL;
	i = 1;
	newNode = NULL;
	// printf("argc = %i\n", argc);
	if (argc == 2)
		stack_a = parse_argv(argv);
	else
	{
		while (i < argc)
		{
			// printf(" 0.2 check_digit(arr[i]) = %i\n", check_digit(argv[i]));
			if (check_digit(argv[i]) == false)
			{
				// printf(" 2 check_digit(argv[i]) = %i\n", check_digit(argv[i]));
				// display_error();
				return (NULL);
			}
			newNode = ft_lstnew(ft_atoi(argv[i]));
			if (!newNode)
				return (NULL);
			ft_add_back(&stack_a, newNode);
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
	// check_args(argc, argv);
	// if	(check_args(argc, argv))
	// 	write(1, "ko args", 7); // better to rewrite crecker if input is valid (doesn't work edge cases)
	stack_a = fill_in_stack(argc, argv);
	stack_b = NULL;
	if (!stack_a || check_duplicate(&stack_a))
	{
		if (stack_a)
			free_stack(stack_a, stack_a->prev);
		display_error();
	}
	// if (check_sorted(&stack_a))
	// 	printf("List is sorted\n");
	if (!check_sorted(&stack_a))
	{
		sort_stack(&stack_a, &stack_b);
		// printf("\nList should be sorted\n");
	}
	print_lst(stack_a);
	if (stack_a)
		free_stack(stack_a, stack_a->prev);
	if (stack_b)
		free_stack(stack_b, stack_b->prev);
	return (0);
}
