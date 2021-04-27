/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tilda <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:08:51 by tilda             #+#    #+#             */
/*   Updated: 2021/04/20 20:08:52 by tilda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct s_parameters
{
	int					times_must_to_eat;
	int					nbr_philosophers;
	char				*wait_all_philo;
	long int			time_to_eat;
	long int			time_to_sleep;
	long int			time_to_die;
	pthread_mutex_t		print_mutex;
	pthread_mutex_t		*arr_mutex_last_meal;
	pthread_mutex_t		*fork_arr;
}						t_parameters;

typedef struct s_philosopher
{
	int					times_ate;
	int					index_philo;
	long int			last_meal;
	pthread_t			thread_id;
	t_parameters		*param;
	pthread_mutex_t		*is_right_fork;
	pthread_mutex_t		*is_left_fork;
	pthread_mutex_t		*mutex_last_meal;
}						t_philosopher;

#endif

