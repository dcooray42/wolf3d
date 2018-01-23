/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/17 17:42:10 by dcooray           #+#    #+#             */
/*   Updated: 2017/07/17 17:42:11 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	empty_file(t_env *e)
{
	ft_printf("Error: Empty file\n");
	delete_env(e);
	exit(EXIT_SUCCESS);
}

void	syntax_error(t_env *e)
{
	ft_printf("Error: Syntax incorrect\n");
	delete_env(e);
	exit(EXIT_SUCCESS);
}

void	xpm_error(t_env *e)
{
	ft_printf("Error: Xpm load error\n");
	delete_env(e);
	exit(EXIT_SUCCESS);
}

void	malloc_error(t_env *e)
{
	ft_printf("Error: Malloc failed\n");
	delete_env(e);
	exit(EXIT_SUCCESS);
}

void	basic_error(char *argv, t_env *e)
{
	if (errno == EISDIR)
		ft_printf("Error: %s %s\n", argv, strerror(errno));
	else
		perror("Error");
	delete_env(e);
	exit(EXIT_SUCCESS);
}
