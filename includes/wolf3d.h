/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 17:42:39 by dcooray           #+#    #+#             */
/*   Updated: 2017/08/14 08:39:36 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <stdio.h>
# include <errno.h>
# include <OpenCL/opencl.h>
# include "mlx.h"
# include "./fmod/fmod.h"

typedef struct	s_line
{
	char	**line;
	int		x;
	int		y;
}				t_line;

typedef struct	s_win
{
	void	*win;
	void	*win_troll;
	void	*img;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_win;

typedef struct	s_xpm
{
	void	*img;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		sizeline;
	int		endian;
}				t_xpm;

typedef struct	s_vari
{
	double	cxh_pos;
	double	cxv_pos;
	double	cyh_pos;
	double	cyv_pos;
	int		vx_pos;
	int		vy_pos;
	double	x_grid;
	double	y_grid;
	double	nx_grid;
	double	ny_grid;
	double	v_angle;
	double	angle;
	double	b_angle;
	int		h_or_v;
}				t_vari;

typedef struct	s_key
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	strafe_left;
	int	strafe_right;
	int	shift;
	int	ctrl;
}				t_key;

typedef struct	s_fmod
{
	FMOD_SYSTEM		*system;
	FMOD_SOUND		*music;
	FMOD_SOUND		*scream;
	FMOD_CHANNEL	*channel;
	FMOD_BOOL		state;
	FMOD_RESULT		result;
}				t_fmod;

typedef struct	s_tmp
{
	int	i;
	int	j;
	int	tmp_j;
	int	k;
	int	l;
	int	wall_size;
	int	scale;
	int	offset;
	int	tmp_offset;
}				t_tmp;

typedef struct	s_env
{
	void	*mlx;
	t_win	*win;
	int		width;
	int		height;
	int		fov;
	int		screen_dist;
	double	x_pos;
	double	y_pos;
	int		p_height;
	int		speed;
	int		t_wall;
	int		x_tab;
	int		y_tab;
	int		**tab;
	int		exorciste;
	t_vari	*var;
	t_key	*key;
	t_xpm	*xpm[6];
	t_fmod	*fmod;
	t_list	*list;
}				t_env;

void			delete_env(t_env *e);
void			delete_win(t_env *e, t_win *win);
void			delete_tab(t_env *e);
void			delete_line(void *line, size_t n);
void			delete_xpm(t_env *e, t_xpm *xpm);
void			delete_fmod(t_fmod *fmod);
void			empty_file(t_env *e);
void			syntax_error(t_env *e);
void			fmod_error(t_env *e);
void			xpm_error(t_env *e);
void			malloc_error(t_env *e);
void			basic_error(char *argv, t_env *e);
t_env			*init_env(void);
void			init_env_bis(t_env *e);
t_vari			*init_variable(t_env *e);
t_key			*init_key(t_env *e);
t_fmod			*init_fmod(t_env *e);
void			init_list(char *line, int y, t_env *e);
void			init_mlx_components(t_env *e);
t_xpm			*init_xpm(char *path, t_env *e);
void			create_tab(t_env *e);
void			correct_file(t_env *e);
void			correct_file_bis(int *x, int *pos, t_list *list, t_env *e);
t_env			*read_file(char *argv);
double			degree_to_radian(double i);
void			render(t_env *e);
void			render_wall(double dist, t_vari *var, int i, t_env *e);
void			render_wall_bis(t_tmp *tmp, t_env *e);
void			render_wall_ter(t_tmp *tmp, t_env *e);
void			check_wall(t_vari *var, int i, t_env *e);
void			check_wall_bis(double tmp_h, t_vari *var, int i, t_env *e);
void			check_wall_ter(double tmp_v, t_vari *var, int i, t_env *e);
void			horizontal(t_vari *var, t_env *e);
void			horizontal_bis(t_vari *var, t_env *e);
void			horizontal_ter(t_vari *var, t_env *e);
void			horizontal_quater(t_vari *var, t_env *e);
void			vertical(t_vari *var, t_env *e);
void			vertical_bis(t_vari *var, t_env *e);
void			vertical_ter(t_vari *var, t_env *e);
void			vertical_quater(t_vari *var, t_env *e);
void			mlx_put_xpm_to_image(t_win *win, t_tmp tmp, t_xpm *xpm);
int				close_win_esc(int keycode, void *param);
int				close_win_cross(void *param);
int				key_press(int keycode, void *param);
int				key_release(int keycode, void *param);
int				key_hook(void *param);
void			key_hook_bis(t_env *e);
void			move_limit_up_down(int i, int j, t_env *e);
void			move_limit_strafe_left_right(int i, int j, t_env *e);
int				check_troll(t_env *e);
void			exorciste(t_env *e);

#endif
