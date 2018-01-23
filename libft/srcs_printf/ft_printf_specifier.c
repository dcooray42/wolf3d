/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:30:48 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 17:30:50 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_specifier(char **format, t_var *var)
{
	if (var->spe != '\0')
		return ;
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		var->spe = 'H';
		*format += 2;
	}
	if (**format == 'l' && *(*format + 1) == 'l')
	{
		var->spe = 'L';
		*format += 2;
	}
	if (**format == 'h' || **format == 'l' || **format == 'j' ||
		**format == 'z')
	{
		if (**format == 'h')
			var->spe = 'h';
		if (**format == 'l')
			var->spe = 'l';
		if (**format == 'j')
			var->spe = 'j';
		if (**format == 'z')
			var->spe = 'z';
		(*format)++;
	}
}

void	ft_printf_specifier_bis(char **format, t_var *var, int *i)
{
	if (var->spe != '\0')
		return ;
	if (**format == 'h' && *(*format + 1) == 'h')
	{
		var->spe = 'H';
		*format += 2;
		*i += 2;
	}
	if (**format == 'l' && *(*format + 1) == 'l')
	{
		var->spe = 'L';
		*format += 2;
		*i += 2;
	}
	ft_printf_specifier_ter(format, var, i);
}

void	ft_printf_specifier_ter(char **format, t_var *var, int *i)
{
	if (**format == 'h' || **format == 'l' || **format == 'j' ||
		**format == 'z')
	{
		if (**format == 'h')
			var->spe = 'h';
		if (**format == 'l')
			var->spe = 'l';
		if (**format == 'j')
			var->spe = 'j';
		if (**format == 'z')
			var->spe = 'z';
		(*format)++;
		(*i)++;
	}
}
