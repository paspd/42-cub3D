/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leodauga <leodauga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:36:08 by ldauga            #+#    #+#             */
/*   Updated: 2021/03/18 14:11:39 by leodauga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../mlx/mlx.h"
# include "../libft/incs/libft.h"

typedef struct s_move
{
	int	left_arrow;
	int right_arrow;
	int	left;
	int	right;
	int	up;
	int	down;
	int	open_door;
}				t_move;

typedef	struct	s_mlx
{
	void	*id;
}				t_mlx;

typedef struct s_draw
{
	int	wall_height;
	int	draw_start;
	int	draw_end;
}				t_draw;

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	node_dist_x;
	double	node_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	step_x;
	double	step_y;
	double	dist_wall;
}				t_ray;

typedef	struct	s_rc
{
	double	camera;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_rc;

typedef	struct	s_texture
{
	char	*texture_sprite;

	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	
	double	coef_y;
	double	coef_x;
	double	texture_pos;
	double	sky_coef_x;
	double	sky_coef_y;
	int		x;
	int		y;
}				t_texture;

typedef	struct s_player
{
	int			spawn_direction;
	double		y;
	double		x;
	double		speed;
	double		rotate_speed;
	int			jump;
	char		*actual_pos;
}				t_player;

typedef	struct s_sky
{
	int			color;
	int			r;
	int			g;
	int			b;
	void        *img;
	int	        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
	int			width;
	int			height;
	double		coef_x;
	double		coef_y;
}				t_sky;

typedef	struct s_floor
{
	int		color;
	int		r;
	int		g;
	int		b;
}				t_floor;

typedef struct  s_xpm_img
{
    void        *img;
    int	        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
	int			width;
	int			height;
}               t_xpm_img;

typedef struct  s_rci
{
    void        *img;
    int	        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_rci;

typedef	struct	s_map
{
	char	**tab_map;
	int		x;
	int		y;
	int		x_minimap_coef;
	int		y_minimap_coef;
	int		x_full_map_coef;
	int		y_full_map_coef;
}				t_map;

typedef	struct	s_wind
{
	void	*id;
	int		height;
	int		width;
}				t_wind;

typedef struct	s_file
{
	char	*file_path;
	int		file_fd;
}				t_file;

typedef struct	s_verif
{
	int		pars;
	int		spawn;
	int		map;
	int		wall;
	int		wall_side;
	int		old_key;
	int		old_side;
	int		black;
	int		full_map;
	int		img;
	int		speed_hack;
	int		screen_shoot;
	int		shadow;
	char	*coord;
	int		old_map_x;
	int		old_map_y;
	int		black_col;
	int		side;
}				t_verif;

typedef	struct s_base
{
	char	*dec;
	char	*hex;
}				t_base;

typedef struct	s_cub
{
	t_file		file;
	t_wind		wind;
	t_texture	texture;
	t_map		map;
	t_player	player;
	t_verif		verif;
	t_mlx		mlx;
	t_floor		floor;
	t_sky		sky;
	t_base		base;
	t_rci		rci;
	t_ray		ray;
	t_rc		rc;
	t_draw		draw;
	t_move		move;
	t_xpm_img	tex;
	t_xpm_img	no;
	t_xpm_img	we;
	t_xpm_img	ea;
	t_xpm_img	so;
}				t_cub;

#endif