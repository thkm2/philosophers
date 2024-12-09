/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:29:19 by kgiraud           #+#    #+#             */
/*   Updated: 2024/12/09 15:30:16 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	if (!(ac == 5 || ac == 6))
	{
		perror("wrong number of arguments");
		return (1);
	}
	if (!input_is_valid(ac, av))
		return_error("bad arguments");
	return (0);
}

/* program :
	check_is_valid
	init
	parse */