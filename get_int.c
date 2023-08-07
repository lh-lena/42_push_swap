#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	atoi;
	i = 0;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	atoi = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		atoi = atoi * 10 + str[i] - '0';
		i++;
	}
	return (atoi * sign);
}