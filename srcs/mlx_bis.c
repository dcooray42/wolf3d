/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_bis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 08:22:15 by dcooray           #+#    #+#             */
/*   Updated: 2017/08/14 08:39:47 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		key_press(int keycode, void *param)
{
	t_env	*e;

	e = (t_env *)param;
	close_win_esc(keycode, param);
	if (keycode == 126 || keycode == 13)
		e->key->up = 1;
	if (keycode == 125 || keycode == 1)
		e->key->down = 1;
	if (keycode == 123 || keycode == 0)
		e->key->left = 1;
	if (keycode == 124 || keycode == 2)
		e->key->right = 1;
	if (keycode == 12)
		e->key->strafe_left = 1;
	if (keycode == 14)
		e->key->strafe_right = 1;
	if (keycode == 257)
		e->key->shift = 1;
	if (keycode == 256)
		e->key->ctrl = 1;
	return (0);
}

int		key_release(int keycode, void *param)
{
	t_env	*e;

	e = (t_env *)param;
	if (keycode == 126 || keycode == 13)
		e->key->up = 0;
	if (keycode == 125 || keycode == 1)
		e->key->down = 0;
	if (keycode == 123 || keycode == 0)
		e->key->left = 0;
	if (keycode == 124 || keycode == 2)
		e->key->right = 0;
	if (keycode == 12)
		e->key->strafe_left = 0;
	if (keycode == 14)
		e->key->strafe_right = 0;
	if (keycode == 257)
		e->key->shift = 0;
	if (keycode == 256)
		e->key->ctrl = 0;
	return (0);
}

int		key_hook(void *param)
{
	t_env	*e;

	e = (t_env *)param;
	if (!check_troll(e))
	{
		if (e->key->up)
			move_limit_up_down(1, 1, e);
		if (e->key->down)
			move_limit_up_down(0, 0, e);
		if (e->key->strafe_left)
			move_limit_strafe_left_right(1, 0, e);
		if (e->key->strafe_right)
			move_limit_strafe_left_right(0, 1, e);
		key_hook_bis(e);
	}
	else
		exorciste(e);
	return (0);
}

void	key_hook_bis(t_env *e)
{
	if (e->key->left)
		e->var->v_angle = (e->var->v_angle - 2 < 0) ? 359 :
			e->var->v_angle - 2;
	if (e->key->right)
		e->var->v_angle = (e->var->v_angle + 2 >= 360) ? 0 :
			e->var->v_angle + 2;
	if (e->key->shift)
		e->speed = 20;
	if (e->key->ctrl)
		e->speed = 2;
	if ((!e->key->shift && !e->key->ctrl) || (e->key->shift && e->key->ctrl))
		e->speed = 10;
	render(e);
}
