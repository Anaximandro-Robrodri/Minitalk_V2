#include "minitalk.h"

void	sig_handler(int signal)
{
	ft_putstr("He entrao");
	if (signal == SIGUSR1)
		ft_putnbr(0);
	else if (signal == SIGUSR2)
		ft_putnbr(1);
}

int main (void)
{
	ft_putstr("Your PID is: ");
	ft_putnbr(getpid());
	ft_putstr("\nInsert client PID\n");
	// ESTADO DE CONFORT, DIGAMOS QUE ESTA EN ESPERA PARA ALGO
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
	{
		pause();
	}
}
