/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:58:16 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 17:58:17 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_u(va_list ap, char *format, int *i, t_var *var)
{
	if (*format == 'u')
	{
		ft_printf_arg_nllljzu(ap, i, var);
		ft_printf_arg_hhhu(ap, i, var);
		var->f = 1;
	}
}

void	ft_printf_arg_nllljzu(va_list ap, int *i, t_var *var)
{
	if (var->spe == '\0')
	{
		var->u = va_arg(ap, unsigned int);
		var->s = ft_itoa_base((long)var->u, 10);
		ft_printf_arg_u_print(i, var);
		ft_strdel(&(var->s));
	}
	if (var->spe == 'l' || var->spe == 'L' || var->spe == 'j' ||
		var->spe == 'z')
	{
		var->lu = va_arg(ap, unsigned long);
		var->s = ft_itoa_base_usigned(var->lu, 10);
		ft_printf_arg_lu_print(i, var);
		ft_strdel(&(var->s));
	}
}

void	ft_printf_arg_hhhu(va_list ap, int *i, t_var *var)
{
	if (var->spe == 'h')
	{
		var->lu = (unsigned short)va_arg(ap, unsigned long);
		var->s = ft_itoa_base_usigned((unsigned long)var->lu, 10);
		ft_printf_arg_lu_print(i, var);
		ft_strdel(&(var->s));
	}
	if (var->spe == 'H')
	{
		var->lu = (unsigned char)va_arg(ap, unsigned long);
		var->s = ft_itoa_base_usigned((unsigned long)var->lu, 10);
		ft_printf_arg_lu_print(i, var);
		ft_strdel(&(var->s));
	}
}

void	ft_printf_arg_ulu_flag_zero(int j, t_var *var)
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

void	ft_printf_arg_ulu_implicit_precision(t_var *var, int *i, int *j)
{
	if (var->champ)
	{
		*j = var->champ;
		*i += *j;
		ft_printf_arg_ulu_flag_zero(*j, var);
	}
}
