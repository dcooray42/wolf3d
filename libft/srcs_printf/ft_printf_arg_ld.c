/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_ld.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:16:12 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:16:13 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_ld(va_list ap, char *format, int *i, t_var *var)
{
	if (*format == 'D')
	{
		ft_printf_arg_nllljzld(ap, i, var);
		ft_printf_arg_hhhld(ap, i, var);
		var->f = 1;
	}
}

void	ft_printf_arg_nllljzld(va_list ap, int *i, t_var *var)
{
	if (var->spe == '\0')
	{
		var->ld = va_arg(ap, long);
		var->s = ft_itoa_base(var->ld, 10);
		ft_printf_arg_ld_print(i, var);
		ft_strdel(&(var->s));
	}
	if (var->spe == 'l' || var->spe == 'L' || var->spe == 'j' ||
		var->spe == 'z')
	{
		var->ld = va_arg(ap, long);
		var->s = ft_itoa_base(var->ld, 10);
		ft_printf_arg_ld_print(i, var);
		ft_strdel(&(var->s));
	}
}

void	ft_printf_arg_hhhld(va_list ap, int *i, t_var *var)
{
	if (var->spe == 'h' || var->spe == 'H')
	{
		var->ld = va_arg(ap, long);
		var->s = ft_itoa_base(var->ld, 10);
		ft_printf_arg_ld_print(i, var);
		ft_strdel(&(var->s));
	}
}
