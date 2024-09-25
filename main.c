/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 15:58:23 by anmedyns          #+#    #+#             */
/*   Updated: 2024/09/25 19:07:14 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_put_num(char **numeri, char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (argv[i])
	{
		k = 0;
		numeri[i - 1] = (char *)malloc(ft_strlen (argv[i]));
		while (argv[i][k])
		{
			numeri[i - 1][k] = argv[i][k];
			k++;
		}
		numeri[i - 1][k] = '\0';
		i++;
	}
	numeri[i - 1] = '\0';
	return (numeri);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

int	check_dup(int *arr, int len)
{
	int	i;
	int	k;
	int	num;

	i = 0;
	while (i < len - 1)
	{
		k = i + 1;
		while (k < len)
		{
			if (arr[i] == arr[k])
				return (1);
			k++;
		}
		i++;
	}
	i = -1;
	while (i++ < len)
	{
		if ((arr[i] < -214748364) || (arr[i] > 214748364))
			return (1);
	}
	return (0);
}

void	init_stacks(int argc, char **argv, t_stack *stacks)
{
	char	**numeri;
	int		i;

	if (argc == 2)
		numeri = split(argv[1], ' ');
	else
	{
		numeri = (char **)malloc (sizeof(char *) * (argc));
		numeri = ft_put_num(numeri, argv);
	}
	stacks->len_a = ft_len(numeri);
	stacks->len_b = 0;
	stacks->a = (int *)malloc (sizeof(int) * stacks->len_a);
	stacks->b = (int *)malloc (sizeof(int) * stacks->len_a);
	i = 0;
	while (i < stacks->len_a)
	{
		stacks->a[i] = ft_atoi(numeri[i]);
		i++;
	}
	free_mat(numeri);
}

int	main(int argc, char **argv)
{
	char	**numeri;
	t_stack	stacks;
	int		i;

	if (argc == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	init_stacks(argc, argv, &stacks);
	if (check_alpha(argc, argv))
	{
		ft_exit(stacks);
		return (0);
	}
	if (check_dup (stacks.a, stacks.len_a))
	{
		ft_exit(stacks);
		return (0);
	}
	stacks.maxnum = max_num(stacks.a, stacks.len_a);
	algoritm (&stacks);
	free(stacks.a);
	free(stacks.b);
	return (0);
}
