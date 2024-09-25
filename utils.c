/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:58:23 by anmedyns          #+#    #+#             */
/*   Updated: 2024/09/20 22:46:54 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mat(char **mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		free(mtx[i]);
		i++;
	}
	free(mtx);
}

int	max_num(int *arr, int len)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < len)
	{
		if (arr[i] > arr[k])
		{
			k = i;
		}
		i++;
	}
	return (arr[k]);
}

int	ft_len(char **mat)
{
	int	i;

	i = 0;
	while (mat[i])
		i++;
	return (i);
}

int	check_alpha(int argc, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (argc > i)
	{
		k = 0;
		while (argv[i][k] != '\0')
		{
			if (!((argv[i][k] >= '0' && argv[i][k] <= '9')
				|| argv[i][k] == ' '
				|| argv[i][k] == '-' || argv[i][k] == '+'))
				return (1);
			k++;
		}
		i++;
	}
	return (0);
}

void	ft_exit(t_stack stacks)
{
	write(2, "Error\n", 6);
	free(stacks.a);
	free(stacks.b);
}
