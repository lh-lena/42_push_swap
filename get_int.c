/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:40:13 by ohladkov          #+#    #+#             */
/*   Updated: 2023/08/17 20:59:58 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	atoi;

	i = 0;
	sign = 1;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	atoi = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		atoi = atoi * 10 + (int)str[i] - 48;
		i++;
	}
	return (atoi * sign);
}
