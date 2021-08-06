/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 13:42:27 by robrodri          #+#    #+#             */
/*   Updated: 2021/08/06 13:49:33 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_signal	g_holder;

static void	ft_init_struct(void)
{
	g_holder.msg = 0;
	g_holder.pos = 0;
}

static void	final_message(void)
{
	g_holder.msg = '\n';
	ft_putchar(g_holder.msg);
	ft_putstr("Message received!\n");
}

static void	sig_handler(int signal)
{
	if (signal == SIGUSR2)
		g_holder.msg |= 1;
	g_holder.pos++;
	if (g_holder.pos < 8)
		g_holder.msg <<= 1;
	else if (g_holder.pos == 8)
	{
		if (g_holder.msg == 0)
			final_message();
		else
			ft_putchar(g_holder.msg);
		ft_init_struct();
	}
}

int	main(void)
{
	ft_putstr("Your PID is: ");
	ft_putnbr(getpid());
	ft_putstr("\nWaiting for a message\n");
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	ft_init_struct();
	while (1)
	{
		pause();
	}
}
