/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:13:05 by tilda             #+#    #+#             */
/*   Updated: 2021/04/28 19:13:06 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int		is_philo_died(t_philosopher *arr_philo)
{
	int			i;
	int			is_time_to_die;
	int			is_done_eat;
	long int	cur_time;
	long int	last_meal;

	i = 0;
	while (arr_philo->param->nbr_philosophers != i)
	{
		cur_time = get_current_time();
		pthread_mutex_lock(arr_philo[i].mutex_last_meal);
		last_meal = arr_philo[i].last_meal;
		pthread_mutex_unlock(arr_philo[i].mutex_last_meal);
		pthread_mutex_lock(arr_philo[i].mutex_times_ate);
		is_done_eat = arr_philo[i].times_ate == arr_philo->param->times_must_to_eat;
		pthread_mutex_unlock(arr_philo[i].mutex_times_ate);
		is_time_to_die = cur_time - last_meal > arr_philo->param->time_to_die && last_meal != 0;
		if (is_time_to_die && !is_done_eat)
			return (arr_philo[i].index_philo);
		i++;
	}
	return (-1);
}

int		is_all_philo_done_eat(t_philosopher *arr_philo)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (arr_philo->param->nbr_philosophers != i)
	{
		pthread_mutex_lock(arr_philo[i].mutex_times_ate);
		if (arr_philo[i].times_ate == arr_philo->param->times_must_to_eat)
			count++;
		pthread_mutex_unlock(arr_philo[i].mutex_times_ate);
		i++;
	}
	return (count == arr_philo->param->nbr_philosophers);
}

void	*is_philosopher_death(void *arg)
{
	int				index_died_philo;
	t_philosopher	*arr_philo;

	arr_philo = arg;
	while (wait_philo_sit_to_table(arr_philo));
	while (1)
	{
		index_died_philo = is_philo_died(arr_philo);
		if (index_died_philo != -1)
		{
			print_philo_message(&arr_philo[index_died_philo], DIED);
			return (NULL);
		}
		if (is_all_philo_done_eat(arr_philo))
		{
			print_times_ate(arr_philo);
			return (NULL);
		}
	}
}