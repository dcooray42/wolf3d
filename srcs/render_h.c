/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_h.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 23:12:24 by dcooray           #+#    #+#             */
/*   Updated: 2017/08/14 08:24:48 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	horizontal(t_vari *var, t_env *e)
{
	if (var->angle > 10e-4 && var->angle < 180 - 10e-4)
	{
		var->y_grid = ((int)e->y_pos / 64) * 64 + 64;
		var->ny_grid = 64;
		if (var->angle > 90 - 10e-4 && var->angle < 90 + 10e-4)
		{
			var->x_grid = e->x_pos;
			var->nx_grid = 0;
		}
		else
		{
			var->x_grid = e->x_pos + (var->y_grid - e->y_pos) /
				tan(degree_to_radian(var->angle));
			var->nx_grid = 64 / tan(degree_to_radian(var->angle));
		}
	}
	horizontal_bis(var, e);
}

void	horizontal_bis(t_vari *var, t_env *e)
{
	if (var->angle >= 360 - 10e-4 || var->angle <= 10e-4 ||
		(var->angle >= 180 - 10e-4 && var->angle <= 180 + 10e-4))
	{
		var->y_grid = e->y_pos;
		var->x_grid = HUGE_VAL;
	}
	horizontal_ter(var, e);
}

void	horizontal_ter(t_vari *var, t_env *e)
{
	if (var->angle > 180 + 10e-4 && var->angle < 360 - 10e-4)
	{
		var->y_grid = ((int)e->y_pos / 64) * 64 - 10e-4;
		var->ny_grid = -64;
		if (var->angle > 270 - 10e-4 && var->angle < 270 + 10e-4)
		{
			var->x_grid = e->x_pos;
			var->nx_grid = 0;
		}
		else
		{
			var->x_grid = e->x_pos + (var->y_grid - e->y_pos) /
				tan(degree_to_radian(var->angle));
			var->nx_grid = -64.0 / tan(degree_to_radian(var->angle));
		}
	}
	var->cxh_pos = var->x_grid;
	var->cyh_pos = var->y_grid;
	horizontal_quater(var, e);
}

void	horizontal_quater(t_vari *var, t_env *e)
{
	while (1)
	{
		var->vx_pos = var->cxh_pos / 64;
		var->vy_pos = var->cyh_pos / 64;
		if (var->vx_pos < 0 || var->vx_pos >= e->x_tab ||
				var->vy_pos < 0 || var->vy_pos >= e->y_tab ||
				var->cxh_pos < 0.0 || var->cyh_pos < 0.0)
		{
			var->cxh_pos = HUGE_VAL;
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
				var->cxh_pos += var->nx_grid;
				var->cyh_pos += var->ny_grid;
			}
		}
	}
}
