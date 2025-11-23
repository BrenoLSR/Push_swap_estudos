/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brendos- <brendos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:06:18 by brendos-          #+#    #+#             */
/*   Updated: 2025/11/23 17:43:33 by brendos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	one_node_delete(t_node *to_delete, void (*del)(void*))
{
	if (!to_delete)
		return ;
	if (del)
		del(to_delete->data);
	free(to_delete);
}

static void	all_nodes_delete_and_clear(t_dlist *lst, void (*del)(void*))
{
	t_node	*current;
	t_node	*temp_next;

	if (!lst)
		return ;
	current = lst->head;
	while (current)
	{
		temp_next = current->next;
		one_node_delete(current, del);
		current = temp_next;
	}
	lst->head = NULL;
	lst->tail = NULL;
	lst->size = 0;
}

void	dlist_destroy(t_dlist **lst, void (*del)(void*))
{
	if (!*lst || !lst)
		return ;
	all_nodes_delete_and_clear(*lst, del);
	free(*lst);
	*lst = NULL;
}