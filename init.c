/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:39:51 by kgiraud           #+#    #+#             */
/*   Updated: 2024/12/10 13:44:49 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	get_time_in_ms(void)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	return ((long long)((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}

void	init_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		if (pthread_mutex_init(&table->forks[i].fork, NULL) != 0)
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
		table->philos[i].left_fork = &table->forks[i];
		if (i == table->nb_philos - 1)
			table->philos[i].right_fork = &table->forks[0];
		else
			table->philos[i].right_fork = &table->forks[i + 1];
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
	if (ac == 6)
		table->nb_must_eat = ft_atoi(av[5]);
	table->forks = (t_fork *)malloc(sizeof(t_fork) * (table->nb_philos));
	if (!table->forks)
		return_error("malloc forks error");
	init_forks(table);
	table->philos = (t_philo *)malloc(sizeof(t_philo) * (table->nb_philos));
	if (!table->philos)
		return_error("malloc philos error");
	init_philos(table);
}