/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_di.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:21:56 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:21:57 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_di(va_list ap, char *format, int *i, t_var *var)
{
	if (*format == 'd' || *format == 'i')
	{
		ft_printf_arg_nllljzdi(ap, i, var);
		ft_printf_arg_hhhdi(ap, i, var);
		var->f = 1;
	}
}

void	ft_printf_arg_nllljzdi(va_list ap, int *i, t_var *var)
{
	if (var->spe == '\0')
	{
		var->d = va_arg(ap, int);
		var->s = ft_itoa(var->d);
		ft_printf_arg_di_print(i, var);
		ft_strdel(&(var->s));
	}
	if (var->spe == 'l' || var->spe == 'L' || var->spe == 'j' ||
		var->spe == 'z')
	{
		var->ld = va_arg(ap, long);
		var->s = ft_itoa_base(var->ld, 10);
		ft_printf_arg_di_print(i, var);
		ft_strdel(&(var->s));
	}
}

void	ft_printf_arg_hhhdi(va_list ap, int *i, t_var *var)
{
	if (var->spe == 'h')
	{
		var->d = (short)va_arg(ap, int);
		var->s = ft_itoa(var->d);
		ft_printf_arg_di_print(i, var);
		ft_strdel(&(var->s));
	}
	if (var->spe == 'H')
	{
		var->d = (char)va_arg(ap, int);
		var->s = ft_itoa(var->d);
		ft_printf_arg_di_print(i, var);
		ft_strdel(&(var->s));
	}
}

void	ft_printf_arg_di_print(int *i, t_var *var)
{
	if (var->d >= 0)
		ft_printf_arg_di_pos_zero_print(i, var);
	else
		ft_printf_arg_di_neg_print(i, var);
}

void	ft_printf_arg_di_flag_zero(int j, t_var *var)
{
	int	i;

	i = j;
	if (var->flag_zero && !var->flag_minus && !var->flag_hash &&
		!var->flag_precision)
		while (i--)
			ft_putchar('0');
	else
		while (i--)
			ft_putchar(' ');
}
