#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_signal
{
	char		msg;
	int			pos;
}	t_signal;

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(long n);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

#endif
