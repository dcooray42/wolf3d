/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:32:43 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 17:32:44 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_bis(va_list ap, char **format, int *i, t_var *var)
{
	int	j;

	while (**format != '\0')
	{
		if (**format == '%')
		{
			*format += 1;
			j = ft_printf_arg_mod_valid(format, var);
			if (**format == '\0' && j == 2)
				return ;
			*format -= 1;
		}
		if (**format == '%' && j == 1)
			ft_printf_ter(ap, format, i, var);
		else if (**format != '%')
			ft_printf_quater(format, i, var);
		*format += 1;
	}
}

void		ft_printf_ter(va_list ap, char **format, int *i, t_var *var)
{
	while (!var->f)
	{
		*format += 1;
		ft_printf_arg(ap, format, i, var);
	}
	ft_printf_reset(var);
}

void		ft_printf_quater(char **format, int *i, t_var *var)
{
	int	j;

	if (var->champ)
	{
		j = var->champ;
		*i += j;
		if (!var->champ_neg)
		{
			ft_printf_arg_clc_flag_zero(j - 1, var);
			ft_putchar(**format);
		}
		if (var->champ_neg)
		{
			ft_putchar(**format);
			ft_printf_arg_clc_flag_zero(j - 1, var);
		}
		ft_printf_reset(var);
	}
	else
	{
		ft_putchar(**format);
		*i += 1;
	}
}
