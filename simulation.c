/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:33:12 by kgiraud           #+#    #+#             */
/*   Updated: 2024/12/12 12:46:42 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	think(t_philo *philo)
{
	print_log("is thinking", philo);
	usleep(5 * 1000000);
}

void	ft_sleep(t_philo *philo)
{
	print_log("is sleeping", philo);
	usleep(philo->table->time_to_sleep * 1000);
}

void	eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		print_log("has taken a fork", philo);
	}
	pthread_mutex_lock(&philo->right_fork->mutex);
	print_log("has taken a fork", philo);
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		print_log("has taken a fork", philo);
	}
	print_log("is eating", philo);
	usleep(philo->table->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

void	*philo_routine(void *arg)
{
	t_philo philo;

	philo = *(t_philo *)arg;
	while (1)
	{
		eat(&philo);
		ft_sleep(&philo);
		think(&philo);
	}
	return (NULL);
}

void	start_simulation(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->nb_philos)
	{
		pthread_create(&table->philos[i].thread, NULL, philo_routine, &table->philos[i]);
		i++;
	}
	i = 0;
	while (i < table->nb_philos)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}