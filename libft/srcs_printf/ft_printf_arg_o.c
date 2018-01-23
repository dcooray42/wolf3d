/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_o.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:10:41 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 21:32:11 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_o(va_list ap, char *format, int *i, t_var *var)
{
	if (*format == 'o')
	{
		ft_printf_arg_nllljzo(ap, i, var);
		ft_printf_arg_hhho(ap, i, var);
		var->f = 1;
	}
}

void	ft_printf_arg_nllljzo(va_list ap, int *i, t_var *var)
{
	if (var->spe == '\0')
	{
		var->lo = va_arg(ap, long);
		if (var->lo > HEX_MAX)
			var->lo %= HEX_MAX + 1;
		var->s = ft_itoa_base(var->lo, 8);
		ft_printf_arg_o_print(i, var);
		ft_strdel(&(var->s));
	}
	if (var->spe == 'l' || var->spe == 'L' || var->spe == 'j' ||
		var->spe == 'z')
	{
		var->llo = va_arg(ap, unsigned long);
		var->s = ft_itoa_base_usigned(var->llo, 8);
		ft_printf_arg_lo_print(i, var);
		ft_strdel(&(var->s));
	}
}

void	ft_printf_arg_hhho(va_list ap, int *i, t_var *var)
{
	if (var->spe == 'h')
	{
		var->llo = (unsigned short)va_arg(ap, unsigned long);
		var->s = ft_itoa_base_usigned((unsigned long)var->llo, 8);
		ft_printf_arg_lo_print(i, var);
		ft_strdel(&(var->s));
	}
	if (var->spe == 'H')
	{
		var->llo = (unsigned char)va_arg(ap, unsigned long);
		var->s = ft_itoa_base_usigned((unsigned long)var->llo, 8);
		ft_printf_arg_lo_print(i, var);
		ft_strdel(&(var->s));
	}
}

void	ft_printf_arg_olo_flag_zero(int *i, int j, t_var *var)
{
	int	k;

	if (var->flag_hash)
	{
		*i -= 1;
		j--;
	}
	k = j;
	if (var->flag_zero && !var->flag_minus && !var->flag_hash &&
		!var->flag_precision)
		while (k--)
			ft_putchar('0');
	else
		while (k--)
			ft_putchar(' ');
}

void	ft_printf_arg_olo_implicit_precision(t_var *var, int *i, int *j)
{
	if (var->champ)
	{
		*j = var->champ;
		*i += *j;
		ft_printf_arg_olo_flag_zero(i, *j, var);
	}
}
