/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 18:26:11 by mskeleto          #+#    #+#             */
/*   Updated: 2021/08/09 16:12:02 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(char *str)
{
	printf("%s\n", str);
	return (0);
}

t_philosophers	*ft_define(char **argv)
{
	t_philo			*all;
	t_philosophers	*tmp;

	all = (t_philo *)malloc(sizeof(t_philo));
	all->num = ft_atoi(argv[1]);
	all->die = ft_atoi(argv[2]);
	all->eat = ft_atoi(argv[3]);
	all->sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		all->times = ft_atoi(argv[5]);
	else
		all->times = -1;
	if (all->num < 1 || all->die < 1 || all->eat < 1
		|| all->sleep < 1 || all->times == 0)
		return (ft_strerror("Error: argument < 1"));
	pthread_mutex_init(&all->print, NULL);
	pthread_mutex_init(&all->butler, NULL);
	all->morgue = 0;
	all->phil_counter = 0;
	tmp = ft_init(all);
	return (tmp);
}

int	ft_isdigit(int c)
{
	if ((c > 47) && (c < 58))
		return (1);
	else
		return (0);
}

int	ft_check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long int	resul;
	int			positive;

	positive = 1;
	resul = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		positive = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		resul = resul * 10 + (*str - 48);
		if ((resul > 2147483648) && (positive == -1))
			return (0);
		if ((resul > 2147483647) && (positive == 1))
			return (-1);
		str++;
	}
	return (resul * positive);
}
