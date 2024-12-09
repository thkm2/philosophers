/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:29:19 by kgiraud           #+#    #+#             */
/*   Updated: 2024/12/09 14:44:42 by kgiraud          ###   ########.fr       */
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
	printf("%s", av[0]);
	return (0);
}

/* program :
	check_is_valid
	init
	parse */