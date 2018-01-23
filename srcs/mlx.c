/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 17:41:36 by dcooray           #+#    #+#             */
/*   Updated: 2017/08/14 08:22:04 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_mlx_components(t_env *e)
{
	t_win	*win;

	if (!(e->mlx = mlx_init()))
		malloc_error(e);
	if (!(win = (t_win *)ft_memalloc(sizeof(t_win))))
		malloc_error(e);
	if (!(win->win = mlx_new_window(e->mlx, e->width, e->height, "Wolf3D")))
		malloc_error(e);
	win->win_troll = NULL;
	if (!(win->img = mlx_new_image(e->mlx, e->width, e->height)))
		malloc_error(e);
	if (!(win->data = mlx_get_data_addr(win->img, &win->bpp,
		&win->sizeline, &win->endian)))
		malloc_error(e);
	e->win = win;
}

void	mlx_put_xpm_to_image(t_win *win, t_tmp tmp, t_xpm *xpm)
{
	int	i;
	int	j;

	i = (tmp.i * win->bpp / 8) + tmp.j * win->sizeline;
	j = (tmp.offset * 4) + (tmp.scale * xpm->width * 4);
	win->data[i] = xpm->data[j];
	win->data[i + 1] = xpm->data[j + 1];
	win->data[i + 2] = xpm->data[j + 2];
}

int		close_win_esc(int keycode, void *param)
{
	t_env	*e;

	e = (t_env *)param;
	if (keycode == 53)
	{
		delete_env(e);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int		close_win_cross(void *param)
{
	t_env	*e;

	e = (void *)param;
	delete_env(e);
	exit(EXIT_SUCCESS);
	return (0);
}
