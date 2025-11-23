/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brendos- <brendos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 09:47:25 by brendos-          #+#    #+#             */
/*   Updated: 2025/11/23 17:11:20 by brendos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

//# include "libft.h"

typedef struct s_node
{
	void			*data;
	size_t			index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_dlist
{
	t_node			*head;
	t_node			*tail;
	size_t			size;
}					t_dlist;

t_dlist	*dlist_init(void);
t_node	*dnode_new(void *data);
t_node	*dlist_detach_node(t_dlist *lst, t_node *node_to_detach);


int		dlist_push_back(t_dlist *lst, t_node *to_add);
int		dlist_push_front(t_dlist *lst, t_node *to_add);
t_node	*dlist_get_at(t_dlist *lst, size_t index);
int		dlist_insert_at(t_dlist *lst, t_node *node, size_t index);

void	dlist_destroy(t_dlist **lst, void (*del)(void*));


void	pa(t_dlist *stack_a, t_dlist *stack_b);
void	pb(t_dlist *stack_b, t_dlist *stack_a);
void	sa(t_dlist *stack_a, t_node *to_move, int print);
void	sb(t_dlist *stack_b, t_node *to_move, int print);
void	ss(t_dlist *stack_a, t_dlist *stack_b, t_node *node_a, t_node *node_b);


void	ra(t_dlist *stack_a, t_node *to_move, int print);
void	rb(t_dlist *stack_b, t_node *to_move, int print);
void	rr(t_dlist *stack_a, t_dlist *stack_b, t_node *node_a, t_node *node_b);
void	rra(t_dlist *stack_a, t_node *to_move, int print);
void	rrb(t_dlist *stack_b, t_node *to_move, int print);
void	rrr(t_dlist *stack_a, t_dlist *stack_b, t_node *node_a, t_node *node_b);


int		ft_is_a_valid_number(char *str);
long	str_to_long(const char *str);
bool	has_duplicate(t_dlist *stack_a, int nbr);
bool	push_value(t_dlist *stack_a, int nbr);
void	free_str_array(char **split);
bool	parse_input(t_dlist *stack_a, int argc, char **argv);


bool	is_sorted(t_dlist *stack_a);
void	sort_two_elements(t_dlist *stack_a);
void	sort_three_elements(t_dlist *stack_a);
void	sort_five_elements(t_dlist *stack_a, t_dlist *stack_b);
void	move_min_to_top(t_dlist *stack_a);


void	radix_bit_sort(t_dlist *stack_a, t_dlist *stack_b);

void	sort_stack(t_dlist *stack_a, t_dlist *stack_b);

#endif
