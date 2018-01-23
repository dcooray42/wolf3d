/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 22:17:56 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/06 22:29:10 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_p(va_list ap, char *format, int *i, t_var *var)
{
	if (*format == 'p')
	{
		var->p = va_arg(ap, long);
		var->s = ft_itoa_base(var->p, 16);
		ft_printf_arg_p_print(i, var);
		ft_strdel(&(var->s));
		var->f = 1;
	}
}

void	ft_printf_arg_p_flag_zero(int *i, int j, t_var *var)
{
	int	k;

	if (j == 1)
		*i += 1;
	*i -= 2;
	j -= 2;
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

void	ft_printf_arg_p_implicit_precision(t_var *var, int *i, int *j)
{
	if (var->champ)
	{
		*j = var->champ;
		*i += *j;
		ft_printf_arg_p_flag_zero(i, *j, var);
	}
}
