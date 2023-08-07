#include "push_swap.h"

void	fill_lst(int argc, char **argv, t_list **stack_a)
{
	int	i;
	int	val;

	i = 0;
	val = 0;
	while (i < argc)
	{
		val = ft_atoi(argv[i]);
		printf("ft_atoi(argv[i]) = %i\n", ft_atoi(argv[i]));
		lst_check(stack_a, val);
		push_back(stack_a, val);
	}
	print_lst(stack_a);
}

void	check_argv(int argc, char **argv, t_list **stack_a)
{
	int	i;
	int	countw;

	i = 1;
	countw = 0;
	printf("argc = %i\n", argc);
	while (i < argc)
	{
		countw = ft_countw(argv[i], ' ');
		printf("countw = %i\n", ft_countw(argv[i], ' '));
		check_d(countw, ft_split(argv[i], ' '));
		fill_lst(countw, ft_split(argv[i], ' '), stack_a);
		i++;
	}
}
// fill_lst(stack_a, argc, argv);

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = NULL;
	if (argc < 2)
		return (-1);
	else
		check_argv(argc, argv, &stack_a);
	free_stack(&stack_a);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	//get_int(av[1]);
// 	int	i;

//     if (ac <= 1)
//         return (-1);
// 	i = 1;
// 	while (i < ac)
// 	{
// 		get_int(av[i]);
// 		i++;
// 	}
// 	return (0);
// }