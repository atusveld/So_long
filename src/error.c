/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                             :+:    :+:           */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 15:57:39 by atusveld      #+#    #+#                 */
/*   Updated: 2023/02/16 19:19:14 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	ft_close(void *param)
{
	(void)param;
	write(1, "EXIT\n", 5);
	exit(EXIT_SUCCESS);
}
