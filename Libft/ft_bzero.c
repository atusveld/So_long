/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 17:50:28 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/24 17:50:32 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *str, size_t n)
{
	char	*nstr;

	nstr = str;
	while (n > 0)
	{
		*nstr = '\0';
		nstr++;
		n--;
	}
}
