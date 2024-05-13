/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 00:59:10 by kael-ala          #+#    #+#             */
/*   Updated: 2024/05/13 03:09:16 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap_bonus.h"
#include "../includes/ft_printf.h"

void	ft_free_array(char **strs)
{
	int	i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	strs = NULL;
}

void	ft_perror(char *msg)
{
	ft_printf("%s", msg);
	exit(EXIT_FAILURE);
}
