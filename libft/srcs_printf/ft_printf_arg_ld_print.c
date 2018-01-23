/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_ld_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:16:21 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:16:22 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_ld_print(int *i, t_var *var)
{
	if (var->ld >= 0)
		ft_printf_arg_ld_print_bis(i, var);
	else
		ft_printf_arg_di_neg_print(i, var);
}

void	ft_printf_arg_ld_print_bis(int *i, t_var *var)
{
	if (var->flag_space && !var->flag_minus && !var->flag_plus &&
			!var->champ && !var->flag_precision)
	{
		*i += ft_strlen(var->s) + 1;
		ft_putchar(' ');
		ft_putstr(var->s);
	}
	else if (var->flag_plus && !var->flag_precision && !var->champ)
	{
		*i += ft_strlen(var->s) + 1;
		ft_putchar('+');
		ft_putstr(var->s);
	}
	else
		ft_printf_arg_ld_print_ter(i, var);
}

void	ft_printf_arg_ld_print_ter(int *i, t_var *var)
{
	int	j;

	if (var->flag_precision && !var->precision && !var->ld)
		ft_printf_arg_di_implicit_precision(var, i, &j);
	else if (!var->champ && var->precision)
		ft_printf_arg_di_pos_zero_print_ter(i, var);
	else if (var->champ)
		ft_printf_arg_di_pos_zero_print_bis(i, var);
	else
	{
		*i += ft_strlen(var->s);
		ft_putstr(var->s);
	}
}
