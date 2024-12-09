/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:29:19 by kgiraud           #+#    #+#             */
/*   Updated: 2024/12/09 16:56:56 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_table	table;
	
	if (!(ac == 5 || ac == 6))
	{
		perror("wrong number of arguments");
		return (1);
	}
	if (!input_is_valid(ac, av))
		return_error("bad arguments");
	init_table(&table, ac, av);
	return (0);
}

/* program :
	check_is_valid
	init
	parse */