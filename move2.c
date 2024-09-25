/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:24:26 by anmedyns          #+#    #+#             */
/*   Updated: 2024/08/29 16:40:52 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *stacks)
{
	int	i;
	int	t;

	i = stacks->len_a - 1;
	t = stacks->a[stacks->len_a - 1];
	while (i > 0)
	{
		stacks->a[i] = stacks->a[i - 1];
		i--;
	}
	stacks->a[0] = t;
	write(1, "rra\n", 4);
	return ;
}

void	ft_rrb(t_stack *stacks)
{
	int	i;
	int	t;

	i = stacks->len_b - 1;
	t = stacks->b[stacks->len_b - 1];
	while (i > 0)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[0] = t;
	write(1, "rrb\n", 4);
	return ;
}

void	ft_rrr(t_stack *stacks)
{
	int	i;
	int	t;

	i = stacks->len_a;
	t = stacks->a[stacks->len_a - 1];
	while (i-- > 0)
		stacks->a[i] = stacks->a[i - 1];
	stacks->a[0] = t;
	i = stacks->len_b;
	t = stacks->b[stacks->len_b - 1];
	while (i > 0)
	{
		stacks->b[i] = stacks->b[i - 1];
		i--;
	}
	stacks->b[i] = t;
	write(1, "rrr\n", 4);
	return ;
}

void	ft_rr(t_stack *stacks)
{
	int	i;
	int	t;

	i = 0;
	t = stacks->a[0];
	while (i < stacks->len_a - 1)
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[i] = t;
	i = 0;
	t = stacks->b[0];
	while (i < stacks->len_b - 1)
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[i] = t;
	write(1, "rr\n", 3);
	return ;
}
