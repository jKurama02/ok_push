/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:24:26 by anmedyns          #+#    #+#             */
/*   Updated: 2024/09/06 16:53:34 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack *stacks)
{
	int	len;

	len = stacks->len_a;
	while (len > 0)
	{
		stacks->a[len] = stacks->a[len - 1];
		len--;
	}
	stacks->len_a++;
	stacks->a[0] = stacks->b[0];
	len = 1;
	while (len < stacks->len_b)
	{
		stacks->b[len - 1] = stacks->b[len];
		len++;
	}
	stacks->len_b--;
	write(1, "pa\n", 3);
	return ;
}

void	ft_pb(t_stack *stacks)
{
	int	len;

	if (stacks->len_a == 0)
		return ;
	len = stacks->len_b;
	while (len > 0)
	{
		stacks->b[len] = stacks->b[len - 1];
		len--;
	}
	stacks->len_b++;
	stacks->b[0] = stacks->a[0];
	len = 1;
	while (len < stacks->len_a)
	{
		stacks->a[len - 1] = stacks->a[len];
		len++;
	}
	stacks->len_a--;
	write(1, "pb\n", 3);
	return ;
}
