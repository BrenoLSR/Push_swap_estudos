/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brendos- <brendos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:31:36 by brendos-          #+#    #+#             */
/*   Updated: 2025/11/20 17:09:55 by brendos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist	*dlist_init(void)
{
	t_dlist	*dup_list;

	dup_list = (t_dlist *)malloc(sizeof(t_dlist));
	if (!dup_list)
		return (NULL);
	dup_list->head = NULL;
	dup_list->tail = NULL;
	dup_list->size = 0;
	return (dup_list);
}

t_node	*dnode_new(void *data)
{
	t_node	*new_node;

	new_node = (t_node *) malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*dlist_detach_node(t_dlist *lst, t_node *node_to_detach)
{
	if (!lst || !node_to_detach)
		return (NULL);
	if (node_to_detach->prev)
		node_to_detach->prev->next = node_to_detach->next;
	if (node_to_detach->next)
		node_to_detach->next->prev = node_to_detach->prev;
	if (lst->head == node_to_detach)
		lst->head = node_to_detach->next;
	if (lst->tail == node_to_detach)
		lst->tail = node_to_detach->prev;
	lst->size--;
	node_to_detach->next = NULL;
	node_to_detach->prev = NULL;
	return (node_to_detach);
}
