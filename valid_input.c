#include "push_swap.h"

// is 0-9
int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// check edge cases
int	check_edge(char *s)
{
	int		len;
	char	*str;
	char	*min;
	char	*max;

	if (!ft_isdigit(*s) || *s != '-' || *s != '+')
		return (-1);
	len = ft_strlen(s);
	str = s;
	min = "-2147483648";
	max = "2147483647";
	// printf("ft_strncmp(str, min, len) = %i\n ft_strncmp(str, max, len) = %i\n", ft_strncmp(str, min, len), ft_strncmp(str, max, len));
	if (*str == '-')
	{
		if (ft_strncmp(str, min, len) > 0)
			display_error(); //return (-1);
	}
	else
	{
		//printf("ft_strncmp(str, max, len) = %i\n", ft_strncmp(str, max, len));
		if (ft_strncmp(str, max, len) > 0)
			return (-1);
	}
	return (1);
}

// check -[0-9] +[0-9]
int check_digit(char *s)
{
    size_t	i;
	char	*str;
	size_t	len;

	str = s;
	len = ft_strlen(s);
	i = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
			return (-1);
        i++;
    }
	if (len > 11)
		return (-3);
	if (len > 9 && len < 12)
	{
		if (!check_edge(s))
			return (-4);
	}
    return (1);
}

// check duplicates
void	lst_check(t_list **stack_a, int check)
{
	t_list	*temp;

	if (*stack_a == NULL)
		return ;
	temp = *stack_a;
	while (temp->next != NULL)
	{
		if (temp->content == check)
		{
			write(1, "duplicate\n", 10);
			display_error();
		}
		temp = temp->next;
	}
	return ;
}

void	check_d(int argc, char **argv)
{
	int		i;

	i = 0;
	while (i < argc)
	{
		if (!check_digit(argv[i]))
			
		i++;
	}
}
