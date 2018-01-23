/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:32:22 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 21:32:24 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_x(va_list ap, char *format, int *i, t_var *var)
{
	if (*format == 'x')
	{
		ft_printf_arg_nx(ap, i, var);
		ft_printf_arg_hhhllljzx(ap, i, var);
		var->f = 1;
	}
}

void	ft_printf_arg_nx(va_list ap, int *i, t_var *var)
{
	if (var->spe == '\0')
	{
		var->x = (int)va_arg(ap, long);
		if (var->x < 0)
			var->x += HEX_MAX + 1;
		var->s = ft_itoa_base(var->x, 16);
		ft_printf_arg_x_print(i, var);
		ft_strdel(&(var->s));
	}
}

void	ft_printf_arg_hhhllljzx(va_list ap, int *i, t_var *var)
{
	if (var->spe == 'l' || var->spe == 'L' || var->spe == 'j' ||
		var->spe == 'z')
	{
		var->x = va_arg(ap, long);
		var->s = ft_itoa_base_usigned((unsigned long)var->x, 16);
		ft_printf_arg_x_print(i, var);
		ft_strdel(&(var->s));
	}
	if (var->spe == 'h')
	{
		var->x = (unsigned short)va_arg(ap, long);
		var->s = ft_itoa_base(var->x, 16);
		ft_printf_arg_x_print(i, var);
		ft_strdel(&(var->s));
	}
	if (var->spe == 'H')
	{
		var->x = (unsigned char)va_arg(ap, unsigned long);
		var->s = ft_itoa_base(var->x, 16);
		ft_printf_arg_x_print(i, var);
		ft_strdel(&(var->s));
	}
}

void	ft_printf_arg_xlx_flag_zero(int *i, int j, t_var *var)
{
	int	k;

	if (var->flag_hash && var->x)
	{
		if (j == 1)
			*i += 1;
		*i -= 2;
		j -= 2;
	}
	k = j;
	if (k > 0)
	{
		if (var->flag_zero && !var->flag_minus && !var->flag_precision &&
			!var->champ_neg)
			while (k--)
				ft_putchar('0');
		else
			while (k--)
				ft_putchar(' ');
	}
}

void	ft_printf_arg_xlx_implicit_precision(t_var *var, int *i, int *j)
{
	if (var->champ)
	{
		*j = var->champ;
		*i += *j;
		ft_printf_arg_xlx_flag_zero(i, *j, var);
	}
}
