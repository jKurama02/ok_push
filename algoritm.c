/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algoritm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:14:45 by anmedyns          #+#    #+#             */
/*   Updated: 2024/09/23 16:21:08 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_asc(t_stack *stacks)
{
	int	i;

	i = 0;
	while (i < stacks->len_a - 1)
	{
		if (stacks->a[i] > stacks->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_dec(t_stack *stacks)
{
	int	i;

	i = 1;
	while (i < stacks->len_b)
	{
		if (stacks->b[i - 1] < stacks->b[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_three_sorting(t_stack *stacks)
{
	if ((stacks->a[0] < stacks->a[1]) && (stacks->a[0] < stacks->a[2])
		&& (stacks->a[1] > stacks->a[2]))
	{
		ft_sa(stacks);
		ft_ra(stacks);
	}
	else if ((stacks->a[0] > stacks->a[1]) && (stacks->a[0] > stacks->a[2])
		&& (stacks->a[1] > stacks->a[2]))
	{
		ft_sa(stacks);
		ft_rra(stacks);
	}
	else if ((stacks->a[0] < stacks->a[1]) && (stacks->a[0] > stacks->a[2])
		&& (stacks->a[1] > stacks->a[2]))
		ft_rra(stacks);
	else if ((stacks->a[0] > stacks->a[1]) && (stacks->a[0] > stacks->a[2])
		&& (stacks->a[1] < stacks->a[2]))
		ft_ra(stacks);
	else if ((stacks->a[0] > stacks->a[1]) && (stacks->a[0] < stacks->a[2])
		&& (stacks->a[1] < stacks->a[2]))
		ft_sa(stacks);
}

void	algoritm(t_stack *stacks)
{
	if (check_asc(stacks))
		return ;
	else if (stacks->len_a == 2)
	{
		ft_sa(stacks);
		return ;
	}
	else if (stacks->len_a == 3)
	{
		ft_three_sorting(stacks);
		return ;
	}
	else if (stacks->len_a == 5)
	{
		ft_five_sorting(stacks);
		return ;
	}
	else
	{
		ft_sorter_a(stacks, stacks->len_a, 0);
		return ;
	}
}
