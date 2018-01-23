/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_o_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:07:31 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:07:32 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_o_print(int *i, t_var *var)
{
	int	j;

	if (var->flag_hash && !var->lo)
	{
		*i += 1;
		ft_putchar('0');
	}
	else if (var->flag_precision && !var->precision && !var->lo)
		ft_printf_arg_olo_implicit_precision(var, i, &j);
	else if (!var->champ && var->precision)
		ft_printf_arg_o_print_ter(i, var);
	else if (var->champ)
		ft_printf_arg_o_print_bis(i, var);
	else
	{
		if (var->flag_hash)
		{
			*i += 1;
			ft_putchar('0');
		}
		*i += ft_strlen(var->s);
		ft_putstr(var->s);
	}
}

void	ft_printf_arg_o_print_bis(int *i, t_var *var)
{
	int	j;

	if (var->precision >= (int)ft_strlen(var->s))
		j = var->champ - var->precision;
	else
		j = var->champ - ft_strlen(var->s);
	if (j > 0)
	{
		if (var->flag_hash && var->precision)
			j++;
		*i += j;
		if (!var->champ_neg)
		{
			ft_printf_arg_olo_flag_zero(i, j, var);
			ft_printf_arg_o_print_ter(i, var);
		}
		ft_printf_arg_o_print_quater(i, j, var);
	}
	else
		ft_printf_arg_o_print_ter(i, var);
}

void	ft_printf_arg_o_print_ter(int *i, t_var *var)
{
	int	j;

	if (var->precision)
	{
		j = var->precision - ft_strlen(var->s);
		if (j > 0)
		{
			*i += j;
			if (var->flag_hash)
			{
				ft_putchar('0');
				j--;
			}
			while (j--)
				ft_putchar('0');
			*i += ft_strlen(var->s);
			ft_putstr(var->s);
		}
		else if (j <= 0)
			ft_printf_arg_o_print_quinque(i, var);
	}
	else
		ft_printf_arg_o_print_quinque(i, var);
}

void	ft_printf_arg_o_print_quater(int *i, int j, t_var *var)
{
	if (var->champ_neg)
	{
		ft_printf_arg_o_print_ter(i, var);
		ft_printf_arg_olo_flag_zero(i, j, var);
	}
}

void	ft_printf_arg_o_print_quinque(int *i, t_var *var)
{
	if (var->flag_hash)
	{
		*i += 1;
		ft_putchar('0');
	}
	if (var->lo)
	{
		*i += ft_strlen(var->s);
		ft_putstr(var->s);
	}
}
