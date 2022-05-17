/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_manipulate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:23:15 by mskeleto          #+#    #+#             */
/*   Updated: 2021/08/09 16:13:45 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int sleep_during)
{
	unsigned long long	max_time;

	max_time = gettime() + sleep_during;
	while (gettime() < max_time)
		usleep(50);
}

unsigned long long	gettime(void)
{
	struct timeval		time;
	unsigned long long	converted_time;

	gettimeofday(&time, NULL);
	converted_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (converted_time);
}
