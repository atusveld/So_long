/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 17:59:12 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/25 17:11:03 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	nbrchr;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write (fd, "-", 1);
	}
	nbrchr = (n % 10) + 48;
	n = n / 10;
	if (n > 0)
		ft_putnbr_fd(n, fd);
	write (fd, &nbrchr, 1);
}
