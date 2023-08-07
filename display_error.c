/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 18:40:50 by ohladkov          #+#    #+#             */
/*   Updated: 2023/07/21 19:27:01 by ohladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
    char    *str;

	str = s;
    while (*str)
        write(fd, str++, 1);
}

void	display_error(void)
{
	char	*str;

	str = "Error\n";
	ft_putstr_fd(str, 2);
	exit(0);
}

/*
void	ft_lstcheck(t_list *stack_a, int check)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->content == check)
			ft_display_exit();
		stack_a = stack_a->next;
	}
	return ;
}
*/