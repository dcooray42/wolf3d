/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 17:41:59 by dcooray           #+#    #+#             */
/*   Updated: 2017/08/04 11:05:43 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_list(char *line, int y, t_env *e)
{
	char	*tmp;
	t_line	*tmp_line;
	t_list	*tmp_list;

	tmp = line;
	while ((*tmp == '0' || *tmp == '1' || *tmp == '2' || *tmp == '3' ||
		*tmp == '4' || *tmp == ' ') && *tmp != '\0')
		tmp++;
	if (*tmp != '\0')
		syntax_error(e);
	if (!(tmp_line = (t_line *)ft_memalloc(sizeof(t_line))))
		malloc_error(e);
	tmp_line->x = 0;
	tmp_line->y = y;
	if (!(tmp_line->line = ft_strsplit(line, ' ')))
		malloc_error(e);
	while (tmp_line->line[tmp_line->x])
		tmp_line->x++;
	if (!(tmp_list = ft_lstnew(tmp_line, sizeof(t_line))))
		malloc_error(e);
	ft_memdel((void **)&tmp_line);
	ft_lstadd(&e->list, tmp_list);
}

void	correct_file(t_env *e)
{
	t_list	*list;
	int		pos;
	int		x;

	list = e->list;
	x = 0;
	pos = 0;
	while (list)
	{
		correct_file_bis(&x, &pos, list, e);
		list = list->next;
	}
	if (!pos)
		syntax_error(e);
	e->x_tab = x;
	create_tab(e);
}

void	correct_file_bis(int *x, int *pos, t_list *list, t_env *e)
{
	t_line	*line;
	int		i;

	i = 0;
	line = (t_line *)list->content;
	if (!(*x))
		*x = line->x;
	while (line->line[i])
		if (!ft_strcmp(line->line[i++], "2"))
		{
			*pos += 1;
			if (*pos == 1)
			{
				e->x_pos = (i - 0.5) * 64;
				e->y_pos = (line->y + 0.5) * 64;
			}
		}
	if (!(*(line->line)) || *x != line->x || *pos > 1)
		syntax_error(e);
}

void	create_tab(t_env *e)
{
	t_list	*list;
	t_line	*line;
	int		i;
	int		j;

	list = e->list;
	line = (t_line *)list->content;
	i = 0;
	if (!(e->tab = (int **)ft_memalloc(sizeof(int *) * (e->y_tab))))
		malloc_error(e);
	while (i < e->y_tab)
		if (!(e->tab[i++] = (int *)ft_memalloc(sizeof(int) * line->x)))
			malloc_error(e);
	while (list)
	{
		i = 0;
		j = 0;
		line = (t_line *)list->content;
		while (line->line[j])
			e->tab[line->y][i++] = ft_atoi(line->line[j++]);
		i++;
		list = list->next;
	}
}

t_env	*read_file(char *argv)
{
	t_env	*e;
	int		fd;
	char	*line;
	int		y;

	line = NULL;
	e = init_env();
	y = 0;
	if ((fd = open(argv, O_RDONLY)) == -1)
		basic_error(argv, e);
	while (get_next_line(fd, &line) > 0)
	{
		init_list(line, y, e);
		ft_strdel(&line);
		y++;
	}
	e->y_tab = y;
	if (close(fd) == -1 || errno == EISDIR)
		basic_error(argv, e);
	if (!e->list)
		empty_file(e);
	return (e);
}
