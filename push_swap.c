/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:11:37 by marvin            #+#    #+#             */
/*   Updated: 2024/04/19 23:11:16 by kael-ala         ###   ########.fr       */
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
		printf("%d\n",tmp -> number);
		tmp = tmp -> next;
	}
}
void sort_stack(t_stack_a **args)
{
	t_stack_a *stb;

	stb = NULL;
	index_stack(*args);
	if (ft_lstsize(args) == 2)
		__swap__(&args,'a');
	// else if (ft_lstsize(args) == 3)
	// 	three_algo(args);
	// else if (ft_lstsize(args) == 4)
	// 	four_algo(args);
	// else if (ft_lstsize(args) == 5)
	// 	five_algo(args);
	// else if (ft_lstsize(args) > 5)
		// big_algo(args);
	// while(args)
	// {
	// 	printf("%d\n",args->index);
	// 	args = args -> next;
	// }
}

int	main(int ac, char **av)
{
	t_stack_a	*args;
	char		*nums;
	
	nums = set_buffer(av);
	if (ac > 1)
	{
		if (check_args(av))
		{
			free(nums);
			ft_perror("Error\n");
		}
		args = set_stack_a(nums);
		if (stack_sorted(args))
			sort_stack(&args);
		// ft_lstclear(&args);
		free(nums);
	}
	else
		return (1);
}
