/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgiraud <kgiraud@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:42:07 by kgiraud           #+#    #+#             */
/*   Updated: 2024/12/10 13:24:45 by kgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_fork
{
	pthread_mutex_t		fork;
	int					id;
}	t_fork;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	t_fork			*left_fork;
	t_fork			*right_fork;
}	t_philo;

typedef struct s_table
{
	long long		start_time;
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	t_philo			*philos;
	t_fork			*forks;
}	t_table;

// utils.c
void	return_error(char *s);

// parse.c
int		ft_atoi(char *s);
int		input_is_valid(int ac, char **av);

// init.c
void	init_table(t_table *table, int ac, char **av);

#endif