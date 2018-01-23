/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_di_pos_zero_print.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:16:40 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:16:41 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_di_pos_zero_print(int *i, t_var *var)
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
		ft_printf_arg_di_pos_zero_print_quater(i, var);
}

void	ft_printf_arg_di_pos_zero_print_bis(int *i, t_var *var)
{
	int	j;

	if (var->precision >= (int)ft_strlen(var->s))
		j = var->champ - var->precision;
	else
		j = var->champ - ft_strlen(var->s);
	if (j > 0)
	{
		*i += j;
		ft_printf_arg_di_pos_zero_print_quinque(i, &j, var);
		ft_printf_arg_di_pos_zero_print_sexa(i, j, var);
	}
	else
	{
		if (var->flag_plus)
		{
			*i += 1;
			ft_putchar('+');
		}
		ft_printf_arg_di_pos_zero_print_ter(i, var);
	}
}

void	ft_printf_arg_di_pos_zero_print_ter(int *i, t_var *var)
{
	int	j;

	if (var->precision)
	{
		j = var->precision - ft_strlen(var->s);
		if (j > 0)
		{
			*i += j;
			while (j--)
				ft_putchar('0');
		}
		*i += ft_strlen(var->s);
		ft_putstr(var->s);
	}
	else
	{
		*i += ft_strlen(var->s);
		ft_putstr(var->s);
	}
}

void	ft_printf_arg_di_pos_zero_print_quater(int *i, t_var *var)
{
	int	j;

	if (var->flag_precision && !var->precision && !var->d)
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
