/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:23:02 by mskeleto          #+#    #+#             */
/*   Updated: 2021/08/09 16:34:48 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_strerror(char *str)
{
	printf("%s\n", str);
	return (NULL);
}

t_philosophers	*ft_init(t_philo *all)
{
	t_philosophers		*ps;
	int					i;
	unsigned long long	time;

	i = 0;
	ps = (t_philosophers *)malloc(sizeof(t_philosophers) * all->num);
	all->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * all->num);
	if (ps == NULL || all->forks == NULL)
		return (ft_strerror("Error: malloc error"));
	time = gettime();
	all->begin_time = time;
	while (i < all->num)
	{
		ps[i].parity = i % 2;
		ps[i].id = i;
		ps[i].last_eat = time;
		ps[i].meal_counter = 0;
		ps[i].left = i;
		ps[i].right = (i + 1) * (i != all->num - 1);
		ps[i].all = all;
		pthread_mutex_init(&(all->forks[i]), NULL);
		i++;
	}
	return (ps);
}

int	ft_DOA(t_philosophers *ps, t_philo *all)
{
	unsigned long long	time;
	int					i;

	i = 0;
	while (i < all->num)
	{
		time = gettime() - all->begin_time;
		if (all->num == 1)
			ps[i].last_eat = 0;
		if (ps[i].last_eat + all->die < time)
			return (ft_print(time, i, "died", all));
		if (all->phil_counter == all->num)
			return (ft_print(-1, -1, NULL, all));
		i++;
	}
	return (1);
}

int	ft_check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_check_digits(argv[i]) == 1)
			return (ft_error("Error: Bad symbol in arguments"));
		i++;
	}
	return (1);
}

int	ft_free(t_philosophers *ps)
{
	int	i;

	i = 0;
	while (i < ps->all->num)
	{
		pthread_mutex_destroy(&ps->all->forks[i]);
		i++;
	}
	free(ps->all->forks);
	free(ps->all);
	free(ps);
	return (0);
}
