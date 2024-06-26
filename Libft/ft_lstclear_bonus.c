/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:01:54 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/27 04:47:23 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstclear(t_stack_a **lst)
{
	t_stack_a	*clear;

	if (!*lst)
		return ;
	while (*lst)
	{
		clear = *lst;
		*lst = (*lst)->next;
		free(clear);
	}
}
