/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:03:11 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:03:12 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_c(va_list ap, char *format, int *i, t_var *var)
{
	if (*format == 'c' || *format == 'C')
	{
		if (*format == 'c')
			ft_printf_arg_nlc(ap, i, var);
		if (*format == 'C')
			ft_printf_arg_hhlc(ap, i, var);
		var->f = 1;
	}
}

void	ft_printf_arg_nlc(va_list ap, int *i, t_var *var)
{
	if (var->spe == '\0')
	{
		var->c = (char)va_arg(ap, int);
		ft_printf_arg_c_print(i, var);
	}
	if (var->spe == 'l')
	{
		var->lc = va_arg(ap, wchar_t);
		ft_printf_arg_lc_print(i, var);
	}
}

void	ft_printf_arg_hhlc(va_list ap, int *i, t_var *var)
{
	if (var->spe == '\0' || var->spe == 'H')
	{
		var->lc = va_arg(ap, wchar_t);
		ft_printf_arg_lc_print(i, var);
	}
}

void	ft_printf_arg_clc_flag_zero(int j, t_var *var)
{
	if (!var->flag_zero)
		while (j--)
			ft_putchar(' ');
	if (var->flag_zero)
		while (j--)
			ft_putchar('0');
}
