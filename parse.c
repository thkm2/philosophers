/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:50:20 by kgiraud           #+#    #+#             */
/*   Updated: 2024/12/09 15:38:12 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_all_digit(char *s)
{
	while (*s)
	{
		if ((*s >= '0' && *s <= '9')
			|| (*s >= 9 && *s <= 13) || *s == 32)
			s++;
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(char *s)
{
	int	nb;

	nb = 0;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	while (*s >= '0' && *s <= '9')
	{
		nb *= 10;
		nb += *s - '0';
		s++;
	}
	return (nb);
}

int	input_is_valid(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!is_all_digit(av[i]))
			return (0);
	}
	return (1);
}