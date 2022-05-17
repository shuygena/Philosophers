/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mskeleto <mskeleto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 19:47:39 by mskeleto          #+#    #+#             */
/*   Updated: 2021/08/09 16:36:03 by mskeleto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_philo
{
	int					num;
	int					die;
	int					sleep;
	int					eat;
	int					times;
	int					morgue;
	int					phil_counter;
	unsigned long long	begin_time;
	pthread_mutex_t		print;
	pthread_mutex_t		*forks;
	pthread_mutex_t		butler;
}				t_philo;

typedef struct s_philosophers
{
	int					parity;
	int					id;
	unsigned long long	last_eat;
	int					meal_counter;
	int					left;
	int					right;
	pthread_t			thread;
	t_philo				*all;
}					t_philosophers;

int					ft_check_digits(char *str);
int					ft_error(char *str);
int					ft_atoi(const char *str);
int					ft_isdigit(int c);
t_philosophers		*ft_define(char **argv);
t_philosophers		*ft_init(t_philo *all);
int					ft_print(unsigned long long time, int id, char *str,
						t_philo *all);
unsigned long long	gettime(void);
void				ft_usleep(int sleep_during);
int					ft_DOA(t_philosophers *ps, t_philo *all);
unsigned long long	ft_eat(int id, int left, int right, t_philo *all);
int					ft_live(t_philosophers *ps, t_philo *all);
void				*ft_begin(void *arg);
int					ft_check_args(char **argv);
void				*ft_strerror(char *str);
int					ft_free(t_philosophers *ps);

#endif
