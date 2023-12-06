/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 15:57:39 by atusveld      #+#    #+#                 */
/*   Updated: 2023/02/16 19:19:14 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char			**map;
	mlx_t			*mlx;
	t_sl			sl;

	if (argc != 2)
		ft_error(ARG);
	ft_check_arg(argv[1]);
	map = ft_read_map(argv[1]);
	mlx = ft_mlx_init();
	sl = ft_init_structs(mlx, map);
	sl.map2 = ft_read_map(argv[1]);
	ft_check_map(&sl);
	ft_init_map(&sl);
	mlx_close_hook(mlx, &ft_close, NULL);
	mlx_key_hook(mlx, &ft_keyhook, (void *)&sl);
	mlx_loop(mlx);
	return (0);
}
