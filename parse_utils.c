/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brendos- <brendos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:07:26 by brendos-          #+#    #+#             */
/*   Updated: 2025/11/22 13:45:13 by brendos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_a_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(const char *str)
{
	int		i;
	int		signal;
	long	result;

	i = 0;
	signal = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (signal * result);
}

bool	ft_is_duplicate(t_dlist *stack_a, int nbr)
{
	t_node	*temp;

	temp = stack_a->head;
	if (!stack_a || !stack_a->head)
		return (false);
	while (temp)
	{
		if (*(int *)temp->data == nbr)
			return (true);
		temp = temp->next;
	}
	return (false);
}

bool	ft_fill_stack(t_dlist *stack_a, int nbr)
{
	t_node	*new_node;
	int		*num;

	num = malloc(sizeof(int));
	if (!num)
		return (false);
	*num = nbr;
	new_node = ft_new_node(num);
	if (!new_node)
	{
		free(num);
		return (false);
	}
	ft_push_node_back(stack_a, new_node);
	return (true);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
