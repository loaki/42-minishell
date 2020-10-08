#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int un;

	un = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		un = -n;
	}
	if (un < 10)
		ft_putchar_fd((char)(un + '0'), fd);
	else
	{
		ft_putnbr_fd(un / 10, fd);
		ft_putchar_fd((char)(un % 10 + '0'), fd);
	}
}