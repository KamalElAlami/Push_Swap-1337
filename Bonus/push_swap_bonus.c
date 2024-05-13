/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 22:11:37 by marvin            #+#    #+#             */
/*   Updated: 2024/05/13 03:10:01 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include "../includes/push_swap_bonus.h"

void	charge_instructions(t_stack_a **a, t_stack_a **b)
{
	char	*buffer;

	buffer = NULL;
	while (1)
	{
		buffer = get_next_line(0);
		if (!buffer)
			break ;
		if (check_op(buffer, a, b))
		{
			ft_lstclear(a);
			ft_lstclear(b);
			free (buffer);
			ft_perror("Error");
		}
		free(buffer);
		buffer = NULL;
	}
	if (!stack_sorted(*a) && ft_lstsize(*b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
		charge_instructions(&a, &b);
		ft_lstclear(&a);
		ft_lstclear(&b);
		free(nums);
	}
	else
		return (1);
}
