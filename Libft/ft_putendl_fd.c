/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 17:59:03 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/24 17:59:04 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *str, int fd)
{
	if (str == NULL)
		return ;
	write (fd, str, ft_strlen(str));
	write (fd, "\n", 1);
}
