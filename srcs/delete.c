/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 17:41:17 by dcooray           #+#    #+#             */
/*   Updated: 2017/08/14 08:52:52 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	delete_win(t_env *e, t_win *win)
{
	if (win->img)
		mlx_destroy_image(e->mlx, win->img);
	if (win->win && !e->exorciste)
		mlx_destroy_window(e->mlx, win->win);
	if (win->win_troll)
		mlx_destroy_window(e->mlx, win->win_troll);
	ft_memdel((void **)&win);
}

void	delete_line(void *line, size_t n)
{
	t_line	*tmp;
	int		i;

	(void)n;
	i = 0;
	tmp = (t_line *)line;
	while (tmp->line[i])
		ft_strdel(&(tmp->line[i++]));
	ft_memdel((void **)&tmp->line);
	ft_memdel((void **)&tmp);
}

void	delete_tab(t_env *e)
{
	t_line	*line;
	int		i;

	line = (t_line *)e->list->content;
	i = 0;
	while (i < e->y_tab)
		ft_memdel((void **)&e->tab[i++]);
	ft_memdel((void **)&e->tab);
}

void	delete_xpm(t_env *e, t_xpm *xpm)
{
	if (xpm)
	{
		if (xpm->img)
			mlx_destroy_image(e->mlx, xpm->img);
		ft_memdel((void **)&xpm);
	}
}

void	delete_env(t_env *e)
{
	int	i;

	if (e)
	{
		i = 0;
		if (e->win)
			delete_win(e, e->win);
		if (e->var)
			ft_memdel((void **)&e->var);
		if (e->tab)
			delete_tab(e);
		if (e->key)
			ft_memdel((void **)&e->key);
		while (i < 6)
			delete_xpm(e, e->xpm[i++]);
		if (e->fmod)
			delete_fmod(e->fmod);
		if (e->list)
			ft_lstdel(&e->list, &delete_line);
		ft_memdel((void **)&e);
	}
}
