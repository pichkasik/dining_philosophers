
#ifndef PHILO_THREE_H
# define PHILO_THREE_H

//General headers
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

//structures.h
# include "structures.h"

/*
** philo_lifecycle.c
*/
void			*is_philosopher_death(void *arg);
void			*philo_lifecycle(t_self *self, int i);
void			create_process(t_self *self);

/*
** philo_lifecycle_utils.c
*/
int				my_usleep(useconds_t usec);
void			print_philo_message(t_philosopher *philo, \
		t_parameters *param, t_semaphore *semaphore, t_action_philo action);
t_death_thread	*constract_death_thread(t_self *self, int i);

/*
** fork.c
*/
int				take_fork(t_philosopher *philo, t_semaphore *semaphore);
int				put_fork(t_philosopher *philo, t_semaphore *semaphore, \
			int times_must_to_eat);
int				left(int position_philo, int total_philosophers);

/*
** death.c
*/
void			*is_philosopher_death(void *arg);

/*
** validate.c
*/
int				is_validate_parametrs(int argc, char *argv[]);

/*
** init.c
*/
t_parameters	*get_parameters(int argc, char *argv[]);
t_philosopher	*init_philosophers(t_parameters *param);
t_semaphore		*init_semaphore(t_parameters *param);

/*
** utils.c
*/
long long int	ft_atoi(const char *str);
void			*ft_calloc(size_t count, size_t size);
long int		get_current_time(void);
void			clear_all_data(t_self *self);

#endif
