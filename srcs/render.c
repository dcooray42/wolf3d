/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 22:17:07 by dcooray           #+#    #+#             */
/*   Updated: 2017/08/14 08:23:47 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	render(t_env *e)
{
	int		i;

	i = 0;
	while (e->var->v_angle < 0)
		e->var->v_angle += 360.0;
	while (e->var->v_angle >= 360.0)
		e->var->v_angle -= 360.0;
	e->var->angle = e->var->v_angle - (e->fov / 2);
	while (i < e->width)
	{
		if (e->var->angle < 0)
			e->var->angle += 360;
		if (e->var->angle >= 360)
			e->var->angle -= 360;
		check_wall(e->var, i, e);
		e->var->angle += e->var->b_angle;
		i++;
	}
	mlx_clear_window(e->mlx, e->win->win);
	mlx_put_image_to_window(e->mlx, e->win->win, e->win->img, 0, 0);
}

void	check_wall(t_vari *var, int i, t_env *e)
{
	double	tmp_h;
	double	tmp_v;

	horizontal(var, e);
	vertical(var, e);
	tmp_h = sqrt(pow(e->x_pos - var->cxh_pos, 2) +
		pow(e->y_pos - var->cyh_pos, 2));
	tmp_v = sqrt(pow(e->x_pos - var->cxv_pos, 2) +
		pow(e->y_pos - var->cyv_pos, 2));
	if (tmp_h < tmp_v)
		check_wall_bis(tmp_h, var, i, e);
	else
		check_wall_ter(tmp_v, var, i, e);
}

void	check_wall_bis(double tmp_h, t_vari *var, int i, t_env *e)
{
	var->h_or_v = 0;
	var->vx_pos = var->cxh_pos / 64;
	var->vy_pos = var->cyh_pos / 64;
	if (var->vx_pos < 0 || var->vx_pos >= e->x_tab ||
			var->vy_pos < 0 || var->vy_pos >= e->y_tab)
		e->t_wall = 1;
	else
		e->t_wall = e->tab[var->vy_pos][var->vx_pos];
	render_wall(tmp_h, var, i, e);
}

void	check_wall_ter(double tmp_v, t_vari *var, int i, t_env *e)
{
	var->h_or_v = 1;
	var->vx_pos = var->cxv_pos / 64;
	var->vy_pos = var->cyv_pos / 64;
	if (var->vx_pos < 0 || var->vx_pos >= e->x_tab ||
			var->vy_pos < 0 || var->vy_pos >= e->y_tab)
		e->t_wall = 1;
	else
		e->t_wall = e->tab[var->vy_pos][var->vx_pos];
	render_wall(tmp_v, var, i, e);
}
