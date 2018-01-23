/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_lo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:16:29 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:16:31 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_lo(va_list ap, char *format, int *i, t_var *var)
{
	if (*format == 'O')
	{
		ft_printf_arg_nllljzlo(ap, i, var);
		ft_printf_arg_hhhlo(ap, i, var);
		var->f = 1;
	}
}

void	ft_printf_arg_nllljzlo(va_list ap, int *i, t_var *var)
{
	if (var->spe == '\0')
	{
		var->llo = va_arg(ap, unsigned long);
		var->s = ft_itoa_base_usigned(var->llo, 8);
		ft_printf_arg_lo_print(i, var);
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

void	ft_printf_arg_hhhlo(va_list ap, int *i, t_var *var)
{
	if (var->spe == 'h' || var->spe == 'H')
	{
		var->llo = va_arg(ap, unsigned long);
		var->s = ft_itoa_base_usigned(var->llo, 8);
		ft_printf_arg_lo_print(i, var);
		ft_strdel(&(var->s));
	}
}
