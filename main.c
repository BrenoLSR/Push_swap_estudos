/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brendos- <brendos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:49:14 by brendos-          #+#    #+#             */
/*   Updated: 2025/11/23 17:36:40 by brendos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*static void	print_stack(t_dlist *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	printf("Stack: ");
	while (tmp)
	{
		printf("%d ", *(int *)tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}*/

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = dlist_init();
	if (!stack_a)
		return (1);
	if (parse_input(stack_a, argc, argv))
	{
		dlist_destroy(&stack_a, free);
		write(2, "Error\n", 6);
		exit(1);
	}
	stack_b = dlist_init();
	if (!stack_b)
	{
		dlist_destroy(&stack_a, free);
		return (1);
	}
	sort_stack(stack_a, stack_b);
	dlist_destroy(&stack_a, free);
	dlist_destroy(&stack_b, free);
	return (0);
}
