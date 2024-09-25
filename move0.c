/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:24:26 by anmedyns          #+#    #+#             */
/*   Updated: 2024/09/02 17:41:48 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *stacks)
{
	int	i;

	i = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = i;
	write(1, "sa\n", 3);
	return ;
}

void	ft_sb(t_stack *stacks)
{
	int	i;

	i = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = i;
	write(1, "sb\n", 3);
	return ;
}

void	ft_ss(t_stack *stacks)
{
	int	t;

	t = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = t;
	t = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = t;
	write(1, "ss\n", 3);
	return ;
}

void	ft_ra(t_stack *stacks)
{
	int	tmp;
	int	i;

	tmp = stacks->a[0];
	i = 0;
	while (i < (stacks->len_a -1))
	{
		stacks->a[i] = stacks->a[i + 1];
		i++;
	}
	stacks->a[i] = tmp;
	write(1, "ra\n", 3);
	return ;
}

void	ft_rb(t_stack *stacks)
{
	int	tmp;
	int	i;

	tmp = stacks->b[0];
	i = 0;
	while (i < (stacks->len_b -1))
	{
		stacks->b[i] = stacks->b[i + 1];
		i++;
	}
	stacks->b[i] = tmp;
	write(1, "rb\n", 3);
	return ;
}
