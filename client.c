#include "minitalk.h"

/*static int	ft_int_len(long n)
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
	if (ft_int_len(holder) == 7)
	{
		ret = ft_reverse_nbr(holder);
		ft_putstr(ret);
		return (ret);
	}
	while (ft_int_len(holder) < 7)
		holder *= 10;
	ft_putnbr(holder);
	write(1, "\n", 1);
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
//				sleep(1);
				if (binary[i++] == 48)
					kill(pid, SIGUSR1);
				else
					kill(pid, SIGUSR2);
			}
			str++;
			free(binary);
		}
	}
}
*/
void	ft_send_signal(char **argv)
{
	int	pid;
	char	*str;
	int	shift;

	pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		shift = 0;
		while (shift < 7)
		{
			if (((*str >> shift) & 1))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
		 	shift++;	 
			usleep(50);
		}
		str++;
	}
}

int main (int argc, char **argv)
{
	if (argc == 3)
	{
		ft_send_signal(argv);
	}
	else
		ft_putstr("You must include server PID and a message\n");
	return (0);
}
