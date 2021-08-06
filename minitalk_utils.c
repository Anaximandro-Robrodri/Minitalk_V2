#include "minitalk.h"

void	ft_putchar(char c)
{
	write (1, &c, sizeof(char));
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write (1, &s[i++], sizeof(char));
	}
}

void	ft_putnbr(long n)
{
	char			z;
	unsigned int	nb;

	if (n < 0)
	{
		write (1, "-", sizeof(char));
		n = n * (-1);
	}
	nb = (unsigned int) n;
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		z = '0' + (nb % 10);
		write (1, &z, sizeof(char));
	}
	else
	{
		z = nb + '0';
		write (1, &z, sizeof(char));
	}
}

int	ft_isdigit (int c)
{
	if ((c < 48) || (c > 57))
	{
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int				i;
	unsigned int	nb;
	int				sign;

	i = 0;
	nb = 0;
	sign = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' \
			|| str[i] == '\f' || str[i] == '\v' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10) + (str[i++] - '0');
	if (nb > 2147483647 && !sign)
		return (-1);
	else if (nb > 2147483648 && sign)
		return (0);
	else if (sign)
		return ((int)nb * -1);
	return ((int) nb);
}

