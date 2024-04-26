/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:11:37 by marvin            #+#    #+#             */
/*   Updated: 2024/04/25 01:43:09 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"

void index_stack(t_stack_a *args)
{
	t_stack_a	*head;
	t_stack_a	*tmp;
	tmp = args;
	while (tmp)
	{
		head = args;
		tmp->index = 0;
		while (head)
		{
			if (tmp->number > head->number)
				tmp->index++;
			head = head->next;
		}
		tmp = tmp->next;
	}
	
}

void print_stack(t_stack_a *stack)
{
	t_stack_a *tmp;

	tmp = stack;
	while(tmp)
	{
		printf("%d",tmp -> number);
		printf("   index => %d\n",tmp -> index);
		tmp = tmp -> next;
	}
	printf("=====================================");
}
void sort_stack(t_stack_a **a, t_stack_a **b)
{
	(void)b;
	index_stack(*a);
	// if (ft_lstsize(*a) == 2)
	// 	__swap__(a,'a');
	// else if (ft_lstsize(*a) == 3)
	// 	three_algo(a);
	// else if (ft_lstsize(*a) <= 5)
		// small_algo(a, b);
	// else if (ft_lstsize(*a) > 5)
	big_algo(a, b);
	printf("=============A=============\n");
	print_stack(*a);
	printf("=============B=============\n");
	print_stack(*b);
}

int	main(int ac, char **av)
{
	t_stack_a	*a;
	t_stack_a	*b;
	char		*nums;
	
	b = NULL;
	nums = set_buffer(av);
	if (ac > 1)
	{
		if (check_args(av))
		{
			free(nums);
			ft_perror("Error\n");
		}
		a = set_stack_a(nums);
		if (stack_sorted(a))
			sort_stack(&a, &b);
		// ft_lstclear(&args);
		free(nums);
	}
	else
		return (1);
}
