/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 20:52:41 by kael-ala          #+#    #+#             */
/*   Updated: 2024/04/19 17:53:01 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_lstdelone(t_stack_a **lst)
{
	if (!*lst)
		return ;
  t_stack_a *tmp = *lst;
  *lst = (*lst)->next;
  free(tmp);
}
