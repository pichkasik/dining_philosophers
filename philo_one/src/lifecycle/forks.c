/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 21:34:49 by tilda             #+#    #+#             */
/*   Updated: 2021/04/25 21:35:03 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int			left(int position_philo, int total_philosophers)
{
	return ((position_philo + 1) % total_philosophers);
}

int			take_fork(t_philosopher* philo)
{
	if (philo->index_philo % 2 == 0)
	{
		pthread_mutex_lock(philo->is_right_fork);
		pthread_mutex_lock(philo->is_left_fork);
	}
	else
	{
		pthread_mutex_lock(philo->is_left_fork);
		pthread_mutex_lock(philo->is_right_fork);
	}
	pthread_mutex_lock(philo->mutex_last_meal);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(philo->mutex_last_meal);
	return (0);
}

void		put_fork(t_philosopher* philo)
{
	if (philo->index_philo % 2 != 0)
	{
		pthread_mutex_unlock(philo->is_right_fork);
		pthread_mutex_unlock(philo->is_left_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->is_left_fork);
		pthread_mutex_unlock(philo->is_right_fork);
	}
//	pthread_mutex_lock(philo->mutex_times_ate);
//	philo->times_ate++;
//	pthread_mutex_unlock(philo->mutex_times_ate);
}