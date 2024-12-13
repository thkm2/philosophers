/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:39:51 by kgiraud           #+#    #+#             */
/*   Updated: 2024/12/13 13:57:24 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_mutex_init(&table->forks[i].mutex, NULL) != 0)
			return_error("init mutex error");
		table->forks[i].id = i + 1;
		i++;
	}
}

void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meal_counter = 0;
		table->philos[i].last_meal = get_time_in_ms();
		table->philos[i].left_fork = &table->forks[i];
		if (i == table->nb_philos - 1)
			table->philos[i].right_fork = &table->forks[0];
		else
			table->philos[i].right_fork = &table->forks[i + 1];
		table->philos[i].table = table;
		i++;
	}
}

void	init_table(t_table *table, int ac, char **av)
{
	table->start_time = get_time_in_ms();
	table->nb_philos = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->nb_must_eat = -1;
	table->end = 0;
	if (ac == 6)
		table->nb_must_eat = ft_atoi(av[5]);
	table->forks = (t_fork *)malloc(sizeof(t_fork) * (table->nb_philos));
	if (!table->forks)
		return_error("malloc forks error");
	init_forks(table);
	table->philos = (t_philo *)malloc(sizeof(t_philo) * (table->nb_philos));
	if (!table->philos)
	{
		free(table->forks);
		return_error("malloc philos error");
	}
	init_philos(table);
	pthread_mutex_init(&table->log_mutex, NULL);
	pthread_mutex_init(&table->meal_mutex, NULL);
	pthread_mutex_init(&table->end_mutex, NULL);
}
