/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:39:51 by kgiraud           #+#    #+#             */
/*   Updated: 2024/12/09 16:54:37 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		// mettre thread ici
		table->philos[i].id = i + 1;
		// mettre les forks ici
		i++;
	}
	
}

void	init_table(t_table *table, int ac, char **av)
{
	table->start_time = 0;// mettre la date jsp quoi là
	table->nb_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->nb_must_eat = -1;
	if (ac == 6)
		table->nb_must_eat = ft_atoi(av[5]);
	table->philos = (t_philo *)malloc(sizeof(t_philo) * (table->nb_philos));
	if (!table->philos)
		return_error("malloc philos error");
	init_philos(table);
}