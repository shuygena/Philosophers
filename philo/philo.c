/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:12:14 by mskeleto          #+#    #+#             */
/*   Updated: 2021/08/09 17:01:36 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print(unsigned long long time, int id, char *str, t_philo *all)
{
	pthread_mutex_lock(&(all->print));
	if (str == NULL)
		return (0);
	printf("%lld %d %s\n", time, (id + 1), str);
	if (str[0] == 'd')
		return (0);
	pthread_mutex_unlock(&(all->print));
	return (0);
}

unsigned long long	ft_eat(int id, int left, int right, t_philo *all)
{
	unsigned long long	time;

	pthread_mutex_lock(&(all->forks[left]));
	time = gettime() - all->begin_time;
	ft_print(time, id, "has taken a fork", all);
	pthread_mutex_lock(&(all->forks[right]));
	time = gettime() - all->begin_time;
	ft_print(time, id, "has taken a fork", all);
	return (time);
}

int	ft_live(t_philosophers *ps, t_philo *all)
{
	unsigned long long	time;

	while (1)
	{
		time = ft_eat(ps->id, ps->left, ps->right, all);
		ps->last_eat = time;
		ft_print(time, ps->id, "is eating", all);
		ft_usleep(all->eat);
		pthread_mutex_unlock(&(all->forks[(ps->left)]));
		pthread_mutex_unlock(&(all->forks[(ps->right)]));
		time = gettime() - all->begin_time;
		ft_print(time, ps->id, "is sleeping", all);
		ft_usleep(all->sleep);
		ps->meal_counter++;
		if (ps->meal_counter == all->times)
			all->phil_counter++;
		time = gettime() - all->begin_time;
		ft_print(time, ps->id, "is thinking", all);
		if (all->morgue != 0 || all->phil_counter == all->num)
			return (0);
	}
}

void	*ft_begin(void *ex)
{
	t_philosophers	*ps;

	ps = (t_philosophers *)ex;
	if (ps->parity == 0 && ps->all->num != 1)
		ft_usleep(ps->all->eat / 2);
	ft_live(ps, ps->all);
	return (NULL);
}

int	main(int argc, char **argv)
{
	int				i;
	t_philosophers	*ps;

	i = 0;
	if (argc < 5 || argc > 6)
		return (ft_error("Error: Bad count arguments"));
	if (ft_check_args(argv) == 0)
		return (0);
	ps = ft_define(argv);
	if (!ps)
		return (0);
	while (i < ps->all->num)
	{
		pthread_create(&ps[i].thread, NULL, ft_begin, (void *)&(ps[i]));
		pthread_detach(ps[i].thread);
		i++;
	}
	while (1)
	{
		if (ft_DOA(ps, (*ps).all) == 0)
			return (ft_free(ps));
	}
	return (0);
}
