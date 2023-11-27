/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: atusveld <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/08 15:56:00 by atusveld      #+#    #+#                 */
/*   Updated: 2023/02/16 19:05:15 by atusveld      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include "MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_sprt
{
	mlx_image_t	*tile;
	mlx_image_t	*wall;
	mlx_image_t	*cltbl;
	mlx_image_t	*exit;
	mlx_image_t	*playr;
}	t_sprt;

typedef struct s_sl
{
	int			x;
	int			y;
	int			tc;
	int			c;
	int			st;
	char		**map;
	mlx_t		*mlx;
	t_sprt		sprt;
}	t_sl;

//=========[ INIT ]==========//
void		ft_init_map(t_sl *so_long);
mlx_image_t	*ft_tile_gen(mlx_t *mlx, int rgb, int x, int y);
t_sprt		ft_init_sprites(mlx_t *mlx);
t_sl		ft_init_structs(mlx_t *mlx, char **map);
//========[ READ MAP ]========//
char		**ft_read_map(char *map_name);
char		**ft_split_sl(char const *str, char c);
//========[ CHECK MAP ]========//
void		ft_check_map(t_sl *sl);
//=========[ HOOKS ]==========//
void		ft_error(int f);
void		ft_close(void *param);
void		ft_keyhook(mlx_key_data_t keydata, void *param);
void		ft_update_player(t_sl *sl, int x, int y);

#endif
