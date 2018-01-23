/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_lx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:15:16 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 21:32:38 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_lx(va_list ap, char *format, int *i, t_var *var)
{
	if (*format == 'X')
	{
		ft_printf_arg_nlx(ap, i, var);
		ft_printf_arg_hllljzlx(ap, i, var);
		ft_printf_arg_hhlx(ap, i, var);
		var->f = 1;
	}
}

void	ft_printf_arg_nlx(va_list ap, int *i, t_var *var)
{
	int	j;

	if (var->spe == '\0')
	{
		j = 0;
		var->x = (int)va_arg(ap, long);
		if (var->x < 0)
			var->x += HEX_MAX + 1;
		var->s = ft_itoa_base(var->x, 16);
		ft_printf_arg_lx_print(i, var);
		ft_strdel(&(var->s));
	}
}

void	ft_printf_arg_hllljzlx(va_list ap, int *i, t_var *var)
{
	int	j;

	if (var->spe == 'l' || var->spe == 'L' || var->spe == 'j' ||
		var->spe == 'z')
	{
		j = 0;
		var->x = va_arg(ap, long);
		var->s = ft_itoa_base_usigned((unsigned long)var->x, 16);
		*i += ft_strlen(var->s);
		while (var->s[j])
			ft_putchar(ft_toupper(var->s[j++]));
		ft_strdel(&(var->s));
	}
	if (var->spe == 'h')
	{
		j = 0;
		var->x = (unsigned short)va_arg(ap, long);
		var->s = ft_itoa_base_usigned((unsigned long)var->x, 16);
		*i += ft_strlen(var->s);
		while (var->s[j])
			ft_putchar(ft_toupper(var->s[j++]));
		ft_strdel(&(var->s));
	}
}

void	ft_printf_arg_hhlx(va_list ap, int *i, t_var *var)
{
	int	j;

	if (var->spe == 'H')
	{
		j = 0;
		var->x = (unsigned char)va_arg(ap, unsigned long);
		var->s = ft_itoa_base_usigned((unsigned long)var->x, 16);
		*i += ft_strlen(var->s);
		while (var->s[j])
			ft_putchar(ft_toupper(var->s[j++]));
		ft_strdel(&(var->s));
	}
}
