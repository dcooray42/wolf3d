/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_u_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:56:37 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 17:57:20 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_u_print(int *i, t_var *var)
{
	int	j;

	if (var->flag_precision && !var->precision && !var->u)
		ft_printf_arg_ulu_implicit_precision(var, i, &j);
	else if (!var->champ && var->precision)
		ft_printf_arg_u_print_ter(i, var);
	else if (var->champ)
		ft_printf_arg_u_print_bis(i, var);
	else
	{
		*i += ft_strlen(var->s);
		ft_putstr(var->s);
	}
}

void	ft_printf_arg_u_print_bis(int *i, t_var *var)
{
	int	j;

	if (var->precision >= (int)ft_strlen(var->s))
		j = var->champ - var->precision;
	else
		j = var->champ - ft_strlen(var->s);
	if (j > 0)
	{
		*i += j;
		if (var->flag_space && !var->flag_plus && !var->flag_minus)
		{
			j--;
			ft_putchar(' ');
		}
		if (!var->champ_neg)
		{
			ft_printf_arg_ulu_flag_zero(j, var);
			ft_printf_arg_u_print_ter(i, var);
		}
		ft_printf_arg_u_print_quater(i, j, var);
	}
	else
		ft_printf_arg_u_print_ter(i, var);
}

void	ft_printf_arg_u_print_ter(int *i, t_var *var)
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

void	ft_printf_arg_u_print_quater(int *i, int j, t_var *var)
{
	if (var->champ_neg)
	{
		ft_printf_arg_u_print_ter(i, var);
		ft_printf_arg_ulu_flag_zero(j, var);
	}
}
