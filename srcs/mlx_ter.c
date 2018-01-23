/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_ter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 08:23:25 by dcooray           #+#    #+#             */
/*   Updated: 2017/08/14 08:23:27 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_troll(t_env *e)
{
	int	posx;
	int	posy;

	posx = (int)e->x_pos / 64;
	posy = (int)e->y_pos / 64;
	if (e->tab[posy][posx] == 4)
		return (1);
	else
		return (0);
}

void	exorciste(t_env *e)
{
	if (!e->exorciste)
	{
		e->exorciste = 1;
		if (e->win->win)
			mlx_destroy_window(e->mlx, e->win->win);
		if (!e->fmod->state)
			FMOD_Channel_SetPaused(e->fmod->channel, 1);
		e->fmod->result |= FMOD_System_PlaySound(e->fmod->system,
			e->fmod->scream, NULL, FALSE, NULL);
		fmod_error(e);
		if (!(e->win->win_troll = mlx_new_window(e->mlx, e->xpm[5]->width,
			e->xpm[5]->height, "EXORCISTE")))
			malloc_error(e);
		mlx_put_image_to_window(e->mlx, e->win->win_troll,
				e->xpm[5]->img, 0, 0);
		mlx_hook(e->win->win_troll, 17, (1L << 17), &close_win_cross, e);
		mlx_key_hook(e->win->win_troll, &close_win_esc, e);
	}
}

void	move_limit_up_down(int i, int j, t_env *e)
{
	double	dist_x;
	double	dist_y;
	double	tmp_x;
	double	tmp_y;

	tmp_x = e->x_pos;
	tmp_y = e->y_pos;
	dist_x = cos(degree_to_radian(e->var->v_angle)) * e->speed;
	dist_y = sin(degree_to_radian(e->var->v_angle)) * e->speed;
	if (i)
		tmp_x += dist_x;
	else
		tmp_x -= dist_x;
	if (j)
		tmp_y += dist_y;
	else
		tmp_y -= dist_y;
	if (tmp_x >= 0 && tmp_x < e->x_tab * 64 &&
			tmp_y >= 0 && tmp_y < e->y_tab * 64)
		if (e->tab[(int)(tmp_y / 64)][(int)(tmp_x / 64)] != 1)
		{
			e->x_pos = tmp_x;
			e->y_pos = tmp_y;
		}
}

void	move_limit_strafe_left_right(int i, int j, t_env *e)
{
	double	dist_x;
	double	dist_y;
	double	tmp_x;
	double	tmp_y;

	tmp_x = e->x_pos;
	tmp_y = e->y_pos;
	dist_x = sin(degree_to_radian(e->var->v_angle)) * e->speed;
	dist_y = cos(degree_to_radian(e->var->v_angle)) * e->speed;
	if (i)
		tmp_x += dist_x;
	else
		tmp_x -= dist_x;
	if (j)
		tmp_y += dist_y;
	else
		tmp_y -= dist_y;
	if (tmp_x >= 0 && tmp_x < e->x_tab * 64 &&
			tmp_y >= 0 && tmp_y < e->y_tab * 64)
		if (e->tab[(int)(tmp_y / 64)][(int)(tmp_x / 64)] != 1)
		{
			e->x_pos = tmp_x;
			e->y_pos = tmp_y;
		}
}

t_xpm	*init_xpm(char *path, t_env *e)
{
	t_xpm	*xpm;

	if (!(xpm = (t_xpm *)ft_memalloc(sizeof(t_xpm))))
		malloc_error(e);
	if (!(xpm->img = mlx_xpm_file_to_image(e->mlx, path,
		&xpm->width, &xpm->height)))
	{
		ft_memdel((void **)&xpm);
		xpm_error(e);
	}
	if (!(xpm->data = mlx_get_data_addr(xpm->img, &xpm->bpp,
		&xpm->sizeline, &xpm->endian)))
		malloc_error(e);
	return (xpm);
}
