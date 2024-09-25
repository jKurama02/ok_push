/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:37:20 by anmedyns          #+#    #+#             */
/*   Updated: 2024/09/23 16:32:22 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sorter_a(t_stack *stack, int dim, int count_r)
{
	int	pivot;
	int	numbers;

	if (check_asc(stack) == 1)
		return (1);
	numbers = dim;
	if (dim <= 3)
	{
		sorter_a_b_3(stack, dim);
		return (1);
	}
	if (!count_r && !half(&pivot, stack->a, dim))
		return (0);
	while (dim != numbers / 2 + numbers % 2)
	{
		if (stack->a[0] < pivot && (dim--))
			ft_pb(stack);
		else if (++count_r)
			ft_ra(stack);
	}
	while (count_r--)
		ft_rra(stack);
	return (ft_sorter_a(stack, numbers / 2 + numbers % 2, 0)
		&& ft_sorter_b(stack, numbers / 2, 0));
	return (1);
}

int	ft_sorter_b(t_stack *stack, int dim, int count_r)
{
	int	pivot;
	int	numbers;

	if (!count_r && check_dec(stack) == 1)
		while (dim--)
			ft_pa(stack);
	if (dim <= 3)
	{
		sort_3_b(stack, dim);
		return (1);
	}
	numbers = dim;
	if (!half(&pivot, stack->b, dim))
		return (0);
	while (dim != numbers / 2)
	{
		if (stack->b[0] >= pivot && dim--)
			ft_pa(stack);
		else if (++count_r)
			ft_rb(stack);
	}
	while (numbers / 2 != stack->len_a && count_r--)
		ft_rrb(stack);
	return (ft_sorter_a(stack, numbers / 2 + numbers % 2, 0)
		&& ft_sorter_b(stack, numbers / 2, 0));
}

int	half(int *pivot, int *stack, int dim)
{
	int	*tmp;
	int	i;
	int	j;

	tmp = (int *)malloc(sizeof(int) * dim);
	if (!tmp)
		return (0);
	i = 0;
	j = 0;
	while (i < dim)
		tmp[j++] = stack[i++];
	tmp_sort(tmp, dim);
	*pivot = tmp[dim / 2];
	free(tmp);
	return (1);
}

int	sort_3_b(t_stack *stack, int dim)
{
	if (dim == 1)
		ft_pa(stack);
	else if (dim == 2)
	{
		if (stack->b[0] < stack->b[1])
			ft_sb(stack);
		while (dim--)
			ft_pa(stack);
	}
	else if (dim == 3)
	{
		while (dim || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (dim == 1 && stack->a[0] > stack->a[1])
				ft_sa(stack);
			else if (dim == 1
				|| (dim >= 2 && stack->b[0] > stack->b[1])
				|| (dim == 3 && stack->b[0] > stack->b[2]))
				dim = reorder(stack, dim, 0);
			else
				ft_sb(stack);
		}
	}
	return (0);
}

void	sorter_a_b_3(t_stack *stack, int dim)
{
	if (dim == 3 && stack->len_a == 3)
		ft_three_sorting(stack);
	else if (dim == 2)
	{
		if (stack->a[0] > stack->a[1])
			ft_sa(stack);
	}
	else if (dim == 3)
	{
		while (dim != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (dim == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				ft_sa(stack);
			else if (dim == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				dim = reorder(stack, dim, 1);
			else if (stack->a[0] > stack->a[1])
				ft_sa(stack);
			else if (dim++)
				ft_pa(stack);
		}
	}
}
