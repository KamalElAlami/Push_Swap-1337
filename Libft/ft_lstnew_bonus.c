/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 10:43:48 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/29 20:22:45 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

t_stack_a	*ft_lstnew(int content)
{
	t_stack_a	*ptr;

	ptr = malloc(sizeof(t_stack_a));
	if (!ptr)
		return (NULL);
	ptr->number = content;
	ptr->next = NULL;
	return (ptr);
}
