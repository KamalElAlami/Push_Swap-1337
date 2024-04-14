/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 22:51:53 by kael-ala          #+#    #+#             */
/*   Updated: 2024/03/28 22:31:39 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include "./includes/push_swap.h"

int	extra_operator(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '-' || buffer[i] == '+' )
		{
			i++;
			if (buffer[i] && !(ft_isdigit(buffer[i])))
				return (1);
		}
		i++;
	}
	return (0);
}

int	strange_character(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] != ' ' && buffer[i] != '+'
			&& buffer[i] != '-' && !(ft_isdigit(buffer[i])))
			return (1);
		i++;
	}
	return (0);
}

int	check_dup_ints(char *buffer)
{
	char	**nums;
	int		i;
	int		j;

	i = 0;
	j = 1;
	nums = ft_split(buffer, ' ');
	while (nums[i])
	{
		j = i + 1;
		while (nums[j])
		{
			if (ft_atoi(nums[i]) == ft_atoi(nums[j]))
			{
				ft_free_array(nums);
				return (1);
			}
			j++;
		}
		i++;
	}
	ft_free_array(nums);
	return (0);
}

static	int	num_check(char digit, char **digits, long num, int sign)
{
	if (ft_isdigit(digit))
	{
		num = num * 10 + (digit - '0');
		if ((num * sign) > INT_MAX || (num * sign) < INT_MIN)
		{
			ft_free_array(digits);
			return (1);
		}
	}
	return (0);
}

int	check_overflow(char *buffer)
{
	char	**digits;
	char	*digit;
	int		sign;
	long	num;
	int		i;

	digits = ft_split(buffer, ' ');
	i = 0;
	while (digits[i])
	{
		sign = 1;
		digit = digits[i];
		num = 0;
		if (*digit == '-')
			sign = -1;
		while (*digit)
		{
			if (num_check(*digit, digits, num, sign))
				return (1);
			digit++;
		}
		i++;
	}
	ft_free_array(digits);
	return (0);
}
