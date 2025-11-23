/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brendos- <brendos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:07:02 by brendos-          #+#    #+#             */
/*   Updated: 2025/11/22 15:19:53 by brendos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	process_and_test_args(t_dlist *stack_a, char **splited)
{
	int		i;
	int		flag;
	long	nbr;

	i = 0;
	flag = 0;
	while (splited[i])
	{
		if (!ft_is_a_valid_number(splited[i]))
			flag = 1;
		nbr = ft_atol(splited[i]);
		if (nbr < MIN_INT || nbr > MAX_INT)
			flag = 1;
		if (ft_is_duplicate(stack_a, (int)nbr))
			flag = 1;
		if (!ft_fill_stack(stack_a, (int)nbr))
			flag = 1;
		if (flag)
		{
			free_split(splited);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	parse_input(t_dlist *stack_a, int argc, char **argv)
{
	char	**splited;
	int		j;

	if (!stack_a || argc < 2 || !argv)
		return (false);
	j = 0;
	while (++j < argc)
	{
		splited = ft_split(argv[j], ' ');
		if (!splited)
			return (false);
		if (argv[j][0] == '\0' || !splited[0])
		{
			free_split(splited);
			return (false);
		}
		if (!process_and_test_args(stack_a, splited))
			return (false);
		free_split(splited);
	}
	return (true);
}
