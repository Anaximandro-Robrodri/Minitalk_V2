#include "minitalk.h"

	t_signal	holder;

void	ft_init_struct()
{
	holder.msg = NULL;
	holder.pos = 0;
	holder.size = 0;
}

static	char	ft_decimal(int	nbr)
{
	int	holder;
	int	dec;
	char	ret;
	int	base;

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

/*void	ft_realloc()
{
	holder.msg = malloc(holder.pos * sizeof(char));
	if (holder.msg == NULL)
	{
		ft_putstr("Error\n");
		exit(-1);
	}
	holder.msg[holder.pos + 1] = '\0';
}*/

void	sig_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		holder.pos *= 10;
		holder.pos += 0;
		holder.size++;
	}
	else if (signal == SIGUSR2)
	{
		holder.pos *= 10;
		holder.pos += 1;
		holder.size++;
	}
/*	ft_realloc();
	if (signal == SIGUSR1)
	{
		holder.msg[holder.pos] = 48;		LA IDEA ERA USAR UNA CADENA. PUEDE QUE LA RETOME
		holder.pos++;
	}
	else if (signal == SIGUSR2)
	{
		holder.msg[holder.pos] = 49;
		holder.pos++;
	}*/
	if (holder.size == 7)
	{
		ft_putchar(ft_decimal(holder.pos));
		holder.size = 0;
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
