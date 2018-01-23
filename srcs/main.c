/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 17:41:23 by dcooray           #+#    #+#             */
/*   Updated: 2017/08/14 08:40:33 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_env	*init_env(void)
{
	t_env	*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		malloc_error(e);
	e->mlx = NULL;
	e->win = NULL;
	e->width = 640;
	e->height = 400;
	e->fov = 60;
	e->screen_dist = (e->width / 2) / tan(degree_to_radian(e->fov / 2));
	e->x_pos = 0.0;
	e->y_pos = 0.0;
	e->p_height = e->height / 2;
	e->speed = 10;
	e->t_wall = 0;
	e->x_tab = 0;
	e->y_tab = 0;
	e->tab = NULL;
	e->exorciste = 0;
	e->var = init_variable(e);
	e->key = init_key(e);
	e->fmod = init_fmod(e);
	e->list = NULL;
	init_env_bis(e);
	return (e);
}

void	init_env_bis(t_env *e)
{
	int	i;

	i = 0;
	while (i < 6)
		e->xpm[i++] = NULL;
}

t_vari	*init_variable(t_env *e)
{
	t_vari	*var;

	if (!(var = (t_vari *)ft_memalloc(sizeof(t_vari))))
		malloc_error(e);
	var->cxh_pos = 0;
	var->cyh_pos = 0;
	var->cxv_pos = 0;
	var->cyv_pos = 0;
	var->vx_pos = 0;
	var->vy_pos = 0;
	var->x_grid = 0;
	var->y_grid = 0;
	var->nx_grid = 0;
	var->ny_grid = 0;
	var->v_angle = 0.0;
	var->angle = 0.0;
	var->b_angle = (double)e->fov / (double)e->width;
	return (var);
}

t_key	*init_key(t_env *e)
{
	t_key	*key;

	if (!(key = (t_key *)ft_memalloc(sizeof(t_key))))
		malloc_error(e);
	key->up = 0;
	key->down = 0;
	key->left = 0;
	key->right = 0;
	key->strafe_left = 0;
	key->strafe_right = 0;
	key->shift = 0;
	key->ctrl = 0;
	return (key);
}

int		main(int argc, char **argv)
{
	t_env	*e;

	if (argc == 2)
	{
		e = read_file(argv[1]);
		fmod_error(e);
		correct_file(e);
		init_mlx_components(e);
		e->xpm[0] = init_xpm("./textures/mur.xpm", e);
		e->xpm[1] = init_xpm("./textures/sky.xpm", e);
		e->xpm[2] = init_xpm("./textures/grass.xpm", e);
		e->xpm[3] = init_xpm("./textures/secret.xpm", e);
		e->xpm[4] = init_xpm("./textures/goal.xpm", e);
		e->xpm[5] = init_xpm("./textures/exorciste.xpm", e);
		mlx_hook(e->win->win, 2, (1L << 0), &key_press, (void *)e);
		mlx_hook(e->win->win, 3, (1L << 1), &key_release, (void *)e);
		mlx_hook(e->win->win, 17, (1L << 17), &close_win_cross, (void *)e);
		mlx_loop_hook(e->mlx, &key_hook, (void *)e);
		mlx_loop(e->mlx);
	}
	else
		ft_printf("Usage: %s <filename>\n", argv[0]);
	return (0);
}
