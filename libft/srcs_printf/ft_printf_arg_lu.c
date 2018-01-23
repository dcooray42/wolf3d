/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_lu.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:16:06 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:16:07 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_lu(va_list ap, char *format, int *i, t_var *var)
{
	if (*format == 'U')
	{
		ft_printf_arg_nllljzlu(ap, i, var);
		ft_printf_arg_hhhlu(ap, i, var);
		var->f = 1;
	}
}

void	ft_printf_arg_nllljzlu(va_list ap, int *i, t_var *var)
{
	if (var->spe == '\0')
	{
		var->lu = va_arg(ap, unsigned long);
		var->s = ft_itoa_base_usigned(var->lu, 10);
		ft_printf_arg_lu_print(i, var);
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

void	ft_printf_arg_hhhlu(va_list ap, int *i, t_var *var)
{
	if (var->spe == 'h' || var->spe == 'H')
	{
		var->lu = va_arg(ap, unsigned long);
		var->s = ft_itoa_base_usigned(var->lu, 10);
		ft_printf_arg_lu_print(i, var);
		ft_strdel(&(var->s));
	}
}
