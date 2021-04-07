/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldauga <ldauga@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:36:08 by ldauga            #+#    #+#             */
/*   Updated: 2021/04/07 09:26:11 by ldauga           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "../mlx/mlx.h"
# include "../libft/incs/libft.h"

typedef struct s_move
{
	int	left_arrow;
	int	right_arrow;
	int	left;
	int	right;
	int	up;
	int	down;
	int	open_door;
}				t_move;

typedef struct s_mlx
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

typedef struct s_rc
{
	double	buff[3000];
	double	camera;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}				t_rc;

typedef struct s_texture
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

typedef struct s_player
{
	int			spawn_direction;
	double		y;
	double		x;
	double		spawn_x;
	double		spawn_y;
	double		speed;
	double		rotate_speed;
	int			jump;
	char		*actual_pos;
}				t_player;

typedef struct s_sky
{
	int			color;
	int			r;
	int			g;
	int			b;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	double		coef_x;
	double		coef_y;
}				t_sky;

typedef struct s_floor
{
	int		color;
	int		r;
	int		g;
	int		b;
}				t_floor;

typedef struct s_xpm_img
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_xpm_img;

typedef struct s_rci
{
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_rci;

typedef struct s_map
{
	char	**tab_map;
	int		x;
	int		y;
	int		x_minimap_coef;
	int		y_minimap_coef;
	int		x_full_map_coef;
	int		y_full_map_coef;
}				t_map;

typedef struct s_wind
{
	void	*id;
	int		height;
	int		width;
}				t_wind;

typedef struct s_file
{
	char	*file_path;
	int		file_fd;
}				t_file;

typedef struct s_sprite
{
	double	pos_x[500];
	double	pos_y[500];
	int		nb_sprite;
	double	corec_coef;
	int		draw_start_y;
	int		draw_end_y;
	int		draw_start_x;
	int		draw_end_x;
	int		y;
	int		x;
}				t_sprite;

typedef struct s_verif
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
	int		shadow;
	char	*coord;
	int		old_map_x;
	int		old_map_y;
	int		black_col;
	int		side;
	int		old_s_x;
	int		old_s_y;
	int		save;
	int		gnl;
}				t_verif;

typedef struct s_base
{
	char	*dec;
	char	*hex;
}				t_base;

typedef struct s_mpx
{
	int	temp_color;
	int	tx;
	int	ty;
	int	mx;
	int	my;
}				t_mpx;

typedef struct s_afs
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		spr_screen_x;
	int		v_move_scre;
	int		spr_hei;
	t_draw	draw_x;
	t_draw	draw_y;
	int		spr_wid;
	int		color;
	int		tex_x;
	int		d;
	int		tex_y;
}				t_afs;

typedef struct s_cub
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
	t_xpm_img	s_img;
	t_sprite	sprite;
	t_rci		sfi;
	t_mpx		m;
	t_afs		afs;
}				t_cub;

void	error(char *error_msg, t_cub *cub);
int		parsing_texture_sprite(t_cub *cub, char *line);
int		parsing_texture_ea(t_cub *cub, char *line);
int		parsing_texture_we(t_cub *cub, char *line);
int		parsing_texture_so(t_cub *cub, char *line);
int		parsing_texture_no(t_cub *cub, char *line);
int		parsing_res(t_cub *cub, char *line);
int		parsing_texture_check(char *line);
int		ft_tablen(t_cub *cub);
void	fill_flood_map(t_cub *cub, int y, int x);
void	parsing_sky_color_bis(t_cub *cub, char *line, int i);
void	parsing_sky_color(t_cub *cub, char *line);
void	parsing_floor_color_bis(t_cub *cub, char *line, int i);
void	parsing_floor_color(t_cub *cub, char *line);
char	*ft_strjoin_cub(char *s1, char *s2);
void	clean_map(t_cub *cub);
void	parsing_map_3(t_cub *cub);
void	parsing_map_2(t_cub *cub);
void	check_coef_map(t_cub *cub);
int		parsing_map(t_cub *cub, char **str);
int		parsing_file(t_cub *cub);
void	check_file_path(char *path, t_cub *cub);
void	init_structs(char *path, t_cub *cub);
void	free_all(t_cub *cub);
void	aff_player(int c);
void	aff_map(t_cub *cub);
void	aff_all(t_cub *cub);
int		game_finish(t_cub *cub);
void	multiply_px_minimap(t_cub *cub, int color, int y, int x);
void	multiply_px_map(t_cub *cub, int color, int y, int x);
void	up_key(t_cub *cub);
void	down_key(t_cub *cub);
void	left_key(t_cub *cub);
void	right_key(t_cub *cub);
void	aff_map_wind(t_cub *cub);
void	init_node_dist(t_cub *cub);
int		check_s(t_cub *cub);
void	check_ray(t_cub *cub);
void	select_texture(t_cub *cub);
void	check_4_texture(t_cub *cub);
void	draw_vertical_line(int x, int y_min, int y_max, t_cub *cub);
void	draw(t_cub *cub, int x);
void	left_arrow(t_cub *cub);
void	right_arrow(t_cub *cub);
void	init_vector(t_cub *cub);
void	check_move(t_cub *cub);
void	put_gray(t_cub *cub);
void	full_map(t_cub *cub);
void	check_direction(t_cub *cub);
int		check_s_dist(t_cub *cub, int i);
void	sort_sprite(t_cub *cub);
void	aff_sprite(t_cub *cub);
int		raycasting(t_cub *cub);
int		key_press(int key, t_cub *cub);
int		key_release(int	key, t_cub *cub);
void	init_we(t_cub *cub);
void	init_so(t_cub *cub);
void	init_ea(t_cub *cub);
void	init_no(t_cub *cub);
void	init_sprite(t_cub *cub);
void	init_final_img(t_cub *cub);
void	init_img(t_cub *cub);
void	start_graphic(t_cub	*cub);
int		parsing(t_cub *cub);
int		main(int argc, char *argv[]);
void	screen_shoot(t_cub *cub);
void	norm(t_cub *cub);
void	move_2(t_cub *cub);
void	parsing_map_4(t_cub *cub);
void	check_rayca(t_cub *cub, int x);
void	check_ray_bis(t_cub *cub);
void	draw_sprite_2(t_afs *afs, t_cub *cub, int y, int stripe);

#endif