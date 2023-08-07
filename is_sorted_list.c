#include "push_swap.h"

bool	is_sorted_list(t_list *stack_a, int args_nb)
{
	int	i;

	i = 1;
	while (i < args_nb)
	{
		if (stack_a->content > stack_a->next->content)
			return (false);
		stack_a = stack_a->next;
	}
	return (true);
}