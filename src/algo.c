

#include "../push_swap.h"

void	b_pos_sort(t_list **a, t_list **b, t_save *save)
{
	int	j;

	j = 0;
	while (j < save->k)
	{
		pa(b, a);
		write(1, "pa ", 3);
		ra(a);
		write(1, "ra ", 3);
		j++;
	}
}

void	positive_sort(t_list **a, t_list **b, t_save *save, int args)
{
	int j;

	j = 0;
	while (j < args)
	{
		if (((*a)->val >> save->i) & 1)
		{
			pb(a, b);
			rb(b);
			write(1, "pb rb ", 6);
			save->k++;
		}
		else
		{
			ra(a);
			write(1, "ra ", 3);
		}
		if (b != NULL)
			b_pos_sort(a, b, save);
		j++;
	}
}

void	b_neg_sort(t_list **a, t_list **b, t_save *save)
{
	int	j;

	j = 0;
	while (j < save->k)
	{
		pa(b, a);
		write(1, "pa ", 3);
		j++;
	}
}

void	negative_sort(t_list **a, t_list **b, t_save *save, int args)
{
	int j;

	j = 0;
	while (j < args)
	{
		if (((*a)->val >> 31) & 1)
		{
			pb(a, b);
			write(1, "pb ", 3);
			save->k++;
		}
		else
		{
			ra(a);
			write(1, "ra ", 3);
		}
		if (b != NULL)
			b_neg_sort(a, b, save);
		j++;
	}
    
}
