/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 08:24:12 by dcooray           #+#    #+#             */
/*   Updated: 2017/08/14 08:24:13 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	render_wall(double dist, t_vari *var, int i, t_env *e)
{
	double	beta;
	t_tmp	tmp;

	beta = fabs(var->v_angle - var->angle);
	dist *= cos(degree_to_radian(beta));
	tmp.wall_size = 64 * e->screen_dist / dist;
	tmp.i = i;
	if (var->h_or_v == 0)
		tmp.tmp_offset = (int)var->cxh_pos % 64;
	else
		tmp.tmp_offset = (int)var->cyv_pos % 64;
	if (tmp.wall_size / 2 < e->p_height)
		tmp.tmp_j = e->p_height - tmp.wall_size / 2;
	else
		tmp.tmp_j = 0;
	tmp.k = 0;
	tmp.l = e->p_height - tmp.wall_size / 2;
	tmp.offset = tmp.i;
	render_wall_bis(&tmp, e);
	render_wall_ter(&tmp, e);
}

void	render_wall_bis(t_tmp *tmp, t_env *e)
{
	int	haut;

	while (tmp->k < tmp->tmp_j)
	{
		tmp->j = tmp->k;
		tmp->scale = tmp->k;
		mlx_put_xpm_to_image(e->win, *tmp, e->xpm[1]);
		tmp->k++;
	}
	tmp->j = tmp->tmp_j;
	tmp->offset = tmp->tmp_offset;
	haut = e->height - (tmp->l * 2);
	while (tmp->j < ((e->p_height) + (tmp->wall_size / 2)) &&
			tmp->j < e->height)
	{
		tmp->scale = ((tmp->j * 2 - e->height + haut) * (64 / 2)) / haut;
		if (e->t_wall == 1)
			mlx_put_xpm_to_image(e->win, *tmp, e->xpm[0]);
		if (e->t_wall == 3)
			mlx_put_xpm_to_image(e->win, *tmp, e->xpm[3]);
		if (e->t_wall == 4)
			mlx_put_xpm_to_image(e->win, *tmp, e->xpm[4]);
		tmp->j++;
	}
}

void	render_wall_ter(t_tmp *tmp, t_env *e)
{
	double	dist_floor;

	while (tmp->j < e->height)
	{
		dist_floor = (double)(e->p_height * e->screen_dist) /
			(double)(tmp->j - e->p_height);
		tmp->scale = e->x_pos + (dist_floor *
				cos(degree_to_radian(e->var->angle)));
		tmp->offset = e->y_pos + (dist_floor *
				sin(degree_to_radian(e->var->angle)));
		tmp->scale %= 64;
		tmp->offset %= 64;
		if (tmp->scale < 0)
			tmp->scale += 64;
		if (tmp->offset < 0)
			tmp->offset += 64;
		mlx_put_xpm_to_image(e->win, *tmp, e->xpm[2]);
		tmp->j++;
	}
}
