/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 16:15:24 by anmedyns          #+#    #+#             */
/*   Updated: 2024/09/25 19:07:44 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_min_swap_first_element(t_stack *stacks)
{
	int	min;
	int	i;

	min = ft_min(stacks);
	if (min > stacks->len_a / 2)
	{
		i = stacks->len_a - min;
		while (i-- > 0)
			ft_rra(stacks);
	}
	else
	{
		while (min-- > 0)
			ft_ra(stacks);
	}
}

int	ft_min(t_stack *stacks)
{
	int	i;
	int	min;

	min = 0;
	i = 1;
	while (i <= stacks->len_a - 1)
	{
		if (stacks->a[i] < stacks->a[min])
		{
			min = i;
		}
		i++;
	}
	return (min);
}

void	ft_five_sorting(t_stack *stacks)
{
	ft_min_swap_first_element(stacks);
	ft_pb(stacks);
	ft_min_swap_first_element(stacks);
	ft_pb(stacks);
	ft_three_sorting(stacks);
	ft_pa(stacks);
	ft_pa(stacks);
}

void	tmp_sort(int *tmp_stk, int dim)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < dim)
	{
		j = i + 1;
		while (j < dim)
		{
			if (tmp_stk[i] > tmp_stk[j])
			{
				tmp = tmp_stk[i];
				tmp_stk[i] = tmp_stk[j];
				tmp_stk[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	reorder(t_stack *stack, int dim, int f)
{
	if (f == 1)
		ft_pb(stack);
	else if (f == 0)
		ft_pa(stack);
	dim--;
	return (dim);
}
