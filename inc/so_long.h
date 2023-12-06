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

//==========[  ]==========//
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

//==========[ ERROR ]==========//
# define HERE "Error\n--> HERE <--.\n"
# define ARG "Error\nGive map no funny business.\n"
# define MAP "Error\nInvalid map yo.\n"
# define FDER "Error\nFile descriptor fell down.\n"
# define MLX "Error\nMLX failed us all.\n"
//==========[ SPRITE STRUCT ]==========//
typedef struct s_sprt
{
	mlx_image_t	*tile;
	mlx_image_t	*wall;
	mlx_image_t	*cltbl;
	mlx_image_t	*exit;
	mlx_image_t	*playr;
}	t_sprt;
//==========[ SL STRUCT ]==========//
typedef struct s_sl
{
	int			x;
	int			y;
	int			c;
	int			tc;
	int			fc;
	int			fe;
	int			st;
	char		**map;
	char		**map2;
	mlx_t		*mlx;
	t_sprt		sprt;
}	t_sl;
//==========[ INIT ]==========//
mlx_image_t	*ft_tile_gen(mlx_t *mlx, int rgb, int x, int y);
mlx_t		*ft_mlx_init(void);
t_sprt		ft_init_sprites(mlx_t *mlx);
t_sl		ft_init_structs(mlx_t *mlx, char **map);
void		ft_init_map(t_sl *so_long);
//==========[ READ MAP ]==========//
char		**ft_read_map(char *map_name);
char		**ft_split_sl(char const *str, char c);
//==========[ CHECK MAP ]==========//
void		ft_check_map(t_sl *sl);
void		ft_criteria(t_sl *sl);
void		ft_check_arg(char *argv);
void		ft_walls(t_sl *sl, int xx, int yy);
int			ft_pathfinder(t_sl *sl, int x, int y);
//==========[ HOOKS ]==========//
void		ft_error(char *str);
void		ft_close(void *param);
void		ft_keyhook(mlx_key_data_t keydata, void *param);
void		ft_update_player(t_sl *sl, int x, int y);
//==========[  ]==========//
#endif
