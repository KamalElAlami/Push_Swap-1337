/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:11:37 by marvin            #+#    #+#             */
/*   Updated: 2024/04/14 21:23:48 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"


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
		// args = set_stack_a(nums);
		// if (stack_sorted(args))
		// {
		// 	if (ft_lstsize(args) <= 2)
		// 		// sa(args);
		// 	index_stack(args);
		// }
		// ft_lstclear(args);
		// free(nums);
	}
	else
		return (1);
}
