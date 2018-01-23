/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_p_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:05:54 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:05:56 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_p_print(int *i, t_var *var)
{
	int	j;

	if (var->flag_precision && !var->precision && !var->p)
	{
		*i += 2;
		ft_putstr("0x");
		ft_printf_arg_p_implicit_precision(var, i, &j);
	}
	else if (!var->champ && var->precision)
		ft_printf_arg_p_print_ter(i, var);
	else if (var->champ)
		ft_printf_arg_p_print_bis(i, var);
	else
	{
		if (!var->hash_mem)
		{
			*i += 2;
			ft_putstr("0x");
			var->hash_mem = 1;
		}
		*i += ft_strlen(var->s);
		ft_putstr(var->s);
	}
}

void	ft_printf_arg_p_print_bis(int *i, t_var *var)
{
	int	j;

	if (var->precision >= (int)ft_strlen(var->s))
		j = var->champ - var->precision;
	else
		j = var->champ - ft_strlen(var->s);
	if (j > 0)
	{
		*i += j;
		if (!var->champ_neg)
		{
			if (var->flag_zero && !var->precision &&
				!var->hash_mem)
			{
				*i += 2;
				ft_putstr("0x");
				var->hash_mem = 1;
			}
			ft_printf_arg_p_flag_zero(i, j, var);
			ft_printf_arg_p_print_ter(i, var);
		}
		ft_printf_arg_p_print_quater(i, j, var);
	}
	else
		ft_printf_arg_p_print_ter(i, var);
}

void	ft_printf_arg_p_print_ter(int *i, t_var *var)
{
	int	j;

	if (var->precision)
	{
		j = var->precision - ft_strlen(var->s);
		if (j > 0)
		{
			*i += j;
			if (!var->hash_mem)
			{
				ft_putstr("0x");
				*i += 2;
				var->hash_mem = 1;
			}
			while (j--)
				ft_putchar('0');
			*i += ft_strlen(var->s);
			ft_putstr(var->s);
		}
		else if (j <= 0)
			ft_printf_arg_p_print_quinque(i, var);
	}
	else
		ft_printf_arg_p_print_quinque(i, var);
}

void	ft_printf_arg_p_print_quater(int *i, int j, t_var *var)
{
	if (var->champ_neg)
	{
		ft_printf_arg_p_print_ter(i, var);
		ft_printf_arg_p_flag_zero(i, j, var);
	}
}

void	ft_printf_arg_p_print_quinque(int *i, t_var *var)
{
	if (!var->hash_mem)
	{
		*i += 2;
		ft_putstr("0x");
		var->hash_mem = 1;
	}
	*i += ft_strlen(var->s);
	ft_putstr(var->s);
}
