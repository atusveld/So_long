/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/24 17:50:56 by atusveld      #+#    #+#                 */
/*   Updated: 2022/05/24 17:50:58 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int arg)
{
	if (47 < arg && arg < 58)
		return (1);
	else if (64 < arg && arg < 91)
		return (1);
	else if (96 < arg && arg < 123)
		return (1);
	else
		return (0);
}
