/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 21:30:17 by kael-ala          #+#    #+#             */
/*   Updated: 2023/12/06 20:22:37 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alptr;

	if (count && SIZE_MAX / count < size)
		return (NULL);
	alptr = malloc(count * size);
	if (!alptr)
		return (NULL);
	ft_bzero(alptr, count * size);
	return (alptr);
}
