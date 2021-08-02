#ifndef MINITALK_H
# define MINITALK_H
#define sa_handler		__sigaction_u.__sa_handler
#define sa_sigaction	__sigaction_u.__sa_sigaction
# include <signal.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_signal
{
	unsigned char	msg;
}	t_signal;

#endif
