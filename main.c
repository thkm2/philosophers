/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:29:19 by kgiraud           #+#    #+#             */
/*   Updated: 2024/12/10 13:47:09 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_philos(t_table *table)
{
	int i = 0;

	while (i < table->nb_philos)
	{
		printf("i : %d\n", i);
		printf("philo id : %d\n", table->philos[i].id);
		printf("philo left fork id : %d\n", table->philos[i].left_fork->id);
		printf("philo right fork id : %d\n\n", table->philos[i].right_fork->id);
		i++;
	}
	
}

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
	print_philos(&table);
	return (0);
}
