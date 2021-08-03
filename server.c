#include "minitalk.h"

	t_signal	holder;

void	ft_init_struct()
{
	holder.msg = NULL;
	holder.pos = 0;
	holder.size = 0;
}

static	char	ft_decimal(char	*msg)
{
	int	nbr;
	int	holder;
	int	dec;
	char	ret;
	int	base;

	nbr = ft_atoi(msg);
	holder = 0;
	dec = 0;
	base = 1;
	while (nbr > 0)
	{
		holder = nbr % 10;
		nbr /= 10;
		dec = dec + holder * base;
		base *= 2;
	}
	ret = dec;
	return (ret);
}

static void	ft_invert_nbr()
{
	char	tmp;
	int	i;
	int	len;
	int	div;

	i = 0;
	len = ft_strlen(holder.msg);
	div = len / 2;
	while (i < div)
	{
		tmp = holder.msg[i];
		holder.msg[i] = holder.msg[len - i - 1];
		holder.msg[len - i - 1] = tmp;
		i++;
	}
}

void	sig_handler(int signal)
{
/*	if (signal == SIGUSR1)
	{
		holder.pos *= 10;
		holder.size++;
	}
	else if (signal == SIGUSR2)			0 * 0 es 0, normal que no funcione no?
	{
		holder.pos *= 10;
		holder.pos += 1;
		holder.size++;
	}*/
	if (holder.msg == NULL)
		holder.msg = ft_calloc(7, sizeof(char));
	if (signal == SIGUSR1)
	{
		holder.msg[holder.pos] = 48;
		holder.pos++;
	}
	else if (signal == SIGUSR2)
	{
		holder.msg[holder.pos] = 49;
		holder.pos++;
	}
	if (holder.pos == 7)
	{
		ft_invert_nbr();
		ft_putchar(ft_decimal(holder.msg));
		holder.pos = 0;
	}
}

int main (void)
{
	ft_putstr("Your PID is: ");
	ft_putnbr(getpid());
	ft_putstr("\nInsert client PID\n");
	// ESTADO DE CONFORT, DIGAMOS QUE ESTA EN ESPERA PARA ALGO
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	ft_init_struct();
	while (1)
	{
		pause();
	}
}
