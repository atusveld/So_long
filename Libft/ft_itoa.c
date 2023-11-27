/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 17:54:35 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/25 14:44:27 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	check_pol(int n, int i, char *rslt)
{
	int	pol;

	pol = 0;
	if (n < 0)
	{
		rslt[i] = '-';
		pol = -1;
	}
	else
		pol = 1;
	return (pol);
}

static void	calc_itoa(char *rslt, int n, int len)
{
	int	i;
	int	div;
	int	pol;

	i = 0;
	div = 1;
	pol = check_pol(n, i, rslt);
	if (pol == -1)
		i++;
	while ((len -1) > 0)
	{
		div *= 10;
		len--;
	}
	while (div >= 1)
	{
		rslt[i] = ((n / div) * pol) + 48;
		n %= div;
		div /= 10;
		i++;
	}
	rslt[i] = '\0';
}

char	*ft_itoa(int n)
{
	int		len;
	int		n_cpy;
	int		if_neg;
	char	*rslt;

	len = 0;
	n_cpy = n;
	if_neg = 0;
	while (n_cpy != 0)
	{
		len++;
		n_cpy /= 10;
	}
	if (n == 0)
		len++;
	if (n < 0)
		if_neg = 1;
	rslt = (char *) malloc(sizeof(char) * (len + 1 + if_neg));
	if (!rslt)
		return (0);
	calc_itoa(rslt, n, len);
	return (rslt);
}
