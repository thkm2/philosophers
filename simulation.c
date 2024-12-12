/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:33:12 by kgiraud           #+#    #+#             */
/*   Updated: 2024/12/12 15:24:58 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	sleep_think(t_philo *philo)
{
	if (is_end(philo->table))
		return ;
	print_log("is sleeping", philo);
	usleep(philo->table->time_to_sleep * 1000);
	if (is_end(philo->table))
		return ;
	print_log("is thinking", philo);
}

void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		if (is_end(philo->table))
		{
			pthread_mutex_unlock(&philo->left_fork->mutex);
			return ;
		}
		print_log("has taken a fork", philo);
	}
	pthread_mutex_lock(&philo->right_fork->mutex);
	if (is_end(philo->table))
	{
		pthread_mutex_unlock(&philo->right_fork->mutex);
		return ;
	}
	print_log("has taken a fork", philo);
	if (is_end(philo->table))
		return ;
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		if (is_end(philo->table))
		{
			pthread_mutex_unlock(&philo->left_fork->mutex);
			return ;
		}
		print_log("has taken a fork", philo);
	}
	print_log("is eating", philo);
	philo->meal_counter += 1;
	philo->last_meal = get_time_in_ms();
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

void	*philo_routine(void *arg)
{
	t_philo *philo;

	philo = arg;
	while (!is_end(philo->table))
	{
		eat(philo);
		sleep_think(philo);
	}
	return (NULL);
}

void	start_simulation(t_table *table)
{
	int	i;
	pthread_t	supervisor;

	i = 0;
	pthread_create(&supervisor, NULL, supervisor_routine, table);
	while (i < table->nb_philos)
	{
		pthread_create(&table->philos[i].thread, NULL, philo_routine, &table->philos[i]);
		i++;
	}
	pthread_join(supervisor, NULL);
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}