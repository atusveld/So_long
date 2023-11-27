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
	mlx_t			*mlx;
	t_sl			sl;
	char			**map;

	map = ft_read_map(argv[1]);
	if (!map)
		return (1);
	if (argc == 2)
	{
		mlx = mlx_init(1440, 1080, "So_long", false);
		if (!mlx)
			ft_error(1);
		sl = ft_init_structs(mlx, map);
		ft_check_map(&sl);
		ft_init_map(&sl);
		mlx_close_hook(mlx, &ft_close, NULL);
		mlx_key_hook(mlx, &ft_keyhook, (void *)&sl);
		mlx_loop(mlx);
	}
	return (0);
}
