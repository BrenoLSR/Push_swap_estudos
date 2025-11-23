#include "push_swap.h"
#include <stdio.h>
#include <stdint.h>

void	ft_print(void *head)
{
	t_node	*temp;

	temp = head;
	printf("Foward: ");
	while (temp)
	{
		printf("%d ", (int)(intptr_t)temp->data);
		temp = temp->next;
	}
	printf("\n");
}

// main test
int	main(void)
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	t_node	*tmp1;
	t_node	*tmp2;
	t_node	*tmp3;
	t_node	*btmp1;
	t_node	*btmp2;
	t_node	*btmp3;

	stack_a = ft_dlist_initi();
	stack_b = ft_dlist_initi();

	printf("stack a: \n");
	tmp1 = ft_new_node((void *)11);
	tmp2 = ft_new_node((void *)22);
	tmp3 = ft_new_node((void *)33);
	tmp1->next = tmp2;
	tmp2->prev = tmp1;
	tmp2->next = tmp3;
	tmp3->prev = tmp2;
	stack_a->head = tmp1;
	stack_a->tail = tmp3;
	stack_a->size = 3;
	ft_print((void *)tmp1);
	sa(stack_a, tmp1, 1);
	ft_print((void *)stack_a->head);
	ra(stack_a, tmp2, 1);
	ft_print((void *)stack_a->head);
	rra(stack_a, tmp2, 1);
	ft_print((void *)stack_a->head);

	printf("\nstack b: \n");
	btmp1 = ft_new_node((void *)1);
	btmp2 = ft_new_node((void *)2);
	btmp3 = ft_new_node((void *)3);
	btmp1->next = btmp2;
	btmp2->prev = btmp1;
	btmp2->next = btmp3;
	btmp3->prev = btmp2;
	stack_b->head = btmp1;
	stack_b->tail = btmp3;
	stack_b->size = 3;
	ft_print((void *)btmp1);
	sa(stack_b, btmp1, 1);
	ft_print((void *)stack_b->head);
	ra(stack_b, btmp2, 1);
	ft_print((void *)stack_b->head);
	rra(stack_b, btmp2, 1);
	ft_print((void *)stack_b->head);

	printf("\npush: \n");
	pa(stack_a, stack_b, btmp2);
	ft_print((void *)stack_a->head);
	ft_print((void *)stack_b->head);
	pb(stack_b, stack_a, btmp2);
	ft_print((void *)stack_a->head);
	ft_print((void *)stack_b->head);

	printf("\nat the same time: \n");
	ss(stack_a, stack_b, tmp2, btmp2);
	ft_print((void *)stack_a->head);
	ft_print((void *)stack_b->head);
	rr(stack_a, stack_b, tmp1, btmp1);
	ft_print((void *)stack_a->head);
	ft_print((void *)stack_b->head);
	rrr(stack_a, stack_b, tmp1, btmp1);
	ft_print((void *)stack_a->head);
	ft_print((void *)stack_b->head);

	ft_destroy_dlst(&stack_a, NULL);
	ft_destroy_dlst(&stack_b, NULL);
	return (0);
}