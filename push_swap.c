/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:11:37 by marvin            #+#    #+#             */
/*   Updated: 2024/04/15 00:47:25 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"

void sort_stack(t_stack_a *args)
{
	
}

int	main(int ac, char **av)
{
	t_stack_a	*args;
	t_stack_a	*temp;
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
		{
			sort_stack(args);
		}
		ft_lstclear(args);
		free(nums);
	}
	else
		return (1);
}
