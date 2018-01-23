/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 00:35:48 by dcooray           #+#    #+#             */
/*   Updated: 2017/08/14 08:25:08 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	vertical(t_vari *var, t_env *e)
{
	if (var->angle < 90 - 10e-4 || var->angle > 270 + 10e-4)
	{
		var->x_grid = ((int)e->x_pos / 64) * 64 + 64;
		var->nx_grid = 64;
		if (var->angle > 360 - 10e-4 || var->angle < 10e-4)
		{
			var->y_grid = e->y_pos;
			var->ny_grid = 0;
		}
		else
		{
			var->y_grid = e->y_pos + (var->x_grid - e->x_pos) *
				tan(degree_to_radian(var->angle));
			var->ny_grid = 64 * tan(degree_to_radian(var->angle));
		}
	}
	vertical_bis(var, e);
}

void	vertical_bis(t_vari *var, t_env *e)
{
	if ((var->angle >= 90 - 10e-4 && var->angle <= 90 + 10e-4) ||
			(var->angle >= 270 - 10e-4 && var->angle <= 270 + 10e-4))
	{
		var->x_grid = e->x_pos;
		var->y_grid = HUGE_VAL;
	}
	vertical_ter(var, e);
}

void	vertical_ter(t_vari *var, t_env *e)
{
	if (var->angle > 90 + 10e-4 && var->angle < 270 - 10e-4)
	{
		var->x_grid = ((int)e->x_pos / 64) * 64 - 10e-4;
		var->nx_grid = -64;
		if (var->angle > 180 - 10e-4 && var->angle < 180 + 10e-4)
		{
			var->y_grid = e->y_pos;
			var->ny_grid = 0;
		}
		else
		{
			var->y_grid = e->y_pos + (var->x_grid - e->x_pos) *
				tan(degree_to_radian(var->angle));
			var->ny_grid = -64.0 * tan(degree_to_radian(var->angle));
		}
	}
	var->cxv_pos = var->x_grid;
	var->cyv_pos = var->y_grid;
	vertical_quater(var, e);
}

void	vertical_quater(t_vari *var, t_env *e)
{
	while (1)
	{
		var->vx_pos = var->cxv_pos / 64;
		var->vy_pos = var->cyv_pos / 64;
		if (var->vx_pos < 0 || var->vx_pos >= e->x_tab ||
			var->vy_pos < 0 || var->vy_pos >= e->y_tab ||
			var->cxh_pos < 0.0 || var->cyh_pos < 0.0)
		{
			var->cyv_pos = HUGE_VAL;
			return ;
		}
		else
		{
			if (e->tab[var->vy_pos][var->vx_pos] == 1 ||
				e->tab[var->vy_pos][var->vx_pos] == 3 ||
				e->tab[var->vy_pos][var->vx_pos] == 4)
				return ;
			else
			{
				var->cxv_pos += var->nx_grid;
				var->cyv_pos += var->ny_grid;
			}
		}
	}
}
