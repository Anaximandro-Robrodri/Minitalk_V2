#include "libft.h"

static int	gest_errors(char *base)
{
	int	d;
	int	e;
	int	f;

	e = 0;
	d = ft_strlen(base);
	f = 0;
	if (d <= 1)
		return (1);
	while (base[e] != '\0' && base[f] != '\0' && d > 1 )
	{
		while (base[e] != '\0' && base[f] != '\0')
		{	
			if ((base[e] == base[f] && e != f) || (base[f] == '+'\
				|| base[f] == '-'))
			{
				return (e);
			}
			f++;
		}
		e++;
		f = 0;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	a;
	int	b;

	if (gest_errors(base) == 0)
	{
		a = ft_strlen(base);
		if (nbr > 0)
		{
			ft_putnbr_base(nbr / a, base);
			b = nbr % a;
			write(1, &base[b], 1);
		}
		if (nbr < 0)
		{
			write(1, "-", 1);
			ft_putnbr_base(-nbr, base);
		}
	}
}
