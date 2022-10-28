/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpeggie <tpeggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 01:41:01 by tpeggie           #+#    #+#             */
/*   Updated: 2022/06/23 23:43:09 by tpeggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# define IMG_SIZE 64

typedef struct s_game	t_game;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	PLAYER = 'P',
	EXIT = 'E',
	ENEMY = 'V',
}	t_tiletype;

typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

void	draw_wall(t_tile tile, t_game game, t_vector pos);
void	open_wallimgs_up(t_game *game);
void	open_wallimgs_down(t_game *game);

typedef struct s_empty
{
	void	*img;
	int		x;
	int		y;
}	t_empty;

typedef struct s_wall_img
{
	void	*block;
	void	*up_left;
	void	*up;
	void	*up_right;
	void	*right;
	void	*down_right;
	void	*down;
	void	*down_left;
	void	*left;
}	t_wall_img;

typedef struct s_coll_img
{
	void	*current_img;
	int		anim_frames;
	void	*img_0;
	void	*img_1;
}	t_collect_img;

typedef struct s_effect
{
	void		*img;
	t_vector	pos;
	int			frames;
	int			counter;
}	t_effect;

typedef enum e_enemytype
{
	HORIZONTAL_ENEM = 'H',
	VERTICAL_ENEM = 'V',
}	t_enemyytpe;

typedef struct s_enemy_imgs
{
	int		basic_anim;
	void	*basic_current;
	void	*basic_01;
	void	*basic_02;

}	t_enemy_img;

typedef struct s_enemy
{
	t_enemyytpe			type;
	int					dir;
	t_tile				*og_tile;
	t_tile				*tile;
	struct s_enemy		*next;
}	t_enemy;

enum e_keycode
{
	KEY_UP = 13,
	KEY_DOWN = 1,
	KEY_LEFT = 0,
	KEY_RIGHT = 2,
	RESET = 15,
	ESC = 53
};

typedef struct s_player
{
	t_tile	*tile;
	void	*current_img;
	int		framecount;
	int		idle_frames;
	void	*idle_img_0;
	void	*idle_img_1;
	int		action_frames;
	void	*action_img;
}	t_player;

typedef struct s_game
{
	void			*mlx;
	void			*window;
	t_vector		wndw_size;
	t_tile			**tilemap;
	t_player		player;
	int				og_collects;
	int				collects;
	int				moves;
	t_enemy			*enemy_list;
	t_vector		img_size;
	t_wall_img		wall_imgs;
	t_collect_img	collects_imgs;
	t_enemy_img		enemy_imgs;
	t_empty			*empty;
	void			*door_open_img;
	t_effect		effect;
	void			*red_panel;
	void			*white_panel;
}	t_game;

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

int		get_next_line(int fd, char **line);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_linelen(char *line);
int		ft_newread(int fd, char **oldread);
char	*ft_getline(int len, char *read);
char	*ft_clearline(int len, char *read);

int		valid_file(int argc, char *file);
char	**read_map(char *file);
int		valid_map(char **map);

typedef struct s_mapcheckerdata
{
	t_vector	size;
	t_vector	point;
	t_bool		b_player;
	t_bool		b_exit;
	t_bool		b_collect;
}				t_mapcheckerdata;

void	add_enemy(t_game *game, t_enemyytpe type, t_tile *tile);

t_bool	start(t_game *game, int argc, char **argv);

int		input(int key, t_game *game);
int		update(t_game *game);
void	render(t_game game);
void	action_anim(t_player *player);
int		end_program(t_game *game);

#endif