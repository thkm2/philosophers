/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:48:56 by kgiraud           #+#    #+#             */
/*   Updated: 2024/12/12 15:22:49 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_dead(t_philo philo)
{
	if (get_time_in_ms() - philo.last_meal >= philo.table->time_to_die)
	{
		print_log("died", &philo);
		return (1);
	}
	return (0);
}

void	*supervisor_routine(void *arg)
{
	t_table	*table;
	int		nb_eat_enough;
	int		i;

	table = (t_table *)arg;
	while (1)
	{
		nb_eat_enough = 0;
		i = 0;
		while (i < table->nb_philos)
		{
			if (table->nb_must_eat != -1
				&& table->philos[i].meal_counter >= table->nb_must_eat)
				nb_eat_enough++;
			if (nb_eat_enough == table->nb_philos
				|| is_dead(table->philos[i]))
			{
				pthread_mutex_lock(&table->end_mutex);
				table->end = 1;
				pthread_mutex_unlock(&table->end_mutex);
				return (NULL);
			}
			i++;
		}
		usleep(500);
	}
}