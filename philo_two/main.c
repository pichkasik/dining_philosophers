
#include "philo_two.h"

int	main(int argc, char *argv[])
{
	t_self	*self;

	if (is_validate_parametrs(argc, argv) != -1)
		return (1);
	self = ft_calloc(1, sizeof(t_self));
	self->param = get_parameters(argc, argv);
	self->semaphore = init_semaphore(self->param);
	self->arr_philo = init_philosophers(self->param);
	create_threads(self);
	clear_all_data(self);
	printf("End of simulation\n");
	return (0);
}
