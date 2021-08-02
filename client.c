#include "minitalk.h"
#include <stdio.h>

int	ft_int_len(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_binary(char ptr)
{
	int		div;
	int		holder;
	char	*ret;

	div = (int)ptr;
	holder = 0;
	while (div > 0)
	{
		holder *= 10;
		holder += div % 2;
		div /= 2;
	}
	while (ft_int_len(holder) < 7)
		holder *= 10;
	ret = ft_itoa(holder);
	return (ret);
}

static void	ft_send_signal(char **argv, int argc)
{
	int			pid;
	int			i;
	char		*str;
	char		*binary;

	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (--argc)
	{
		while(*str)
		{
			binary = ft_binary(*str);
			i = 0;
			while (binary[i])
			{
				if (binary[i++] == 0)
					kill(SIGUSR1, pid);
				else
					kill(SIGUSR2, pid);
			}
			str++;
		}
	}
}

int main (int argc, char **argv)
{
	if (argc == 3)
	{
		ft_send_signal(argv, argc);
	}
	else
		ft_putstr("You must include server PID and a message\n");
	return (0);
}
