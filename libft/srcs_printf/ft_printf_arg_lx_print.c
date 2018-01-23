/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_lx_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:15:01 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:15:04 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_lx_print(int *i, t_var *var)
{
	int		j;
	char	*str;

	str = var->s;
	if (var->flag_precision && !var->precision && !var->x)
		ft_printf_arg_xlx_implicit_precision(var, i, &j);
	else if (!var->champ && var->precision)
		ft_printf_arg_lx_print_ter(i, var, var->s);
	else if (var->champ)
		ft_printf_arg_lx_print_bis(i, var);
	else
	{
		if (var->flag_hash && var->x && !var->hash_mem)
		{
			*i += 2;
			ft_putstr("0X");
			var->hash_mem = 1;
		}
		*i += ft_strlen(var->s);
		while (*str)
			ft_putchar(ft_toupper(*(str++)));
	}
}

void	ft_printf_arg_lx_print_bis(int *i, t_var *var)
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
			if (var->flag_hash && var->x && var->flag_zero &&
				!var->precision)
			{
				*i += 2;
				ft_putstr("0X");
				var->hash_mem = 1;
			}
			ft_printf_arg_xlx_flag_zero(i, j, var);
			ft_printf_arg_lx_print_ter(i, var, var->s);
		}
		ft_printf_arg_lx_print_quater(i, j, var);
	}
	else
		ft_printf_arg_lx_print_ter(i, var, var->s);
}

void	ft_printf_arg_lx_print_ter(int *i, t_var *var, char *str)
{
	int	j;

	if (var->precision)
	{
		j = var->precision - ft_strlen(var->s);
		if (j > 0)
		{
			*i += j;
			if (var->flag_hash && var->x && !var->hash_mem)
			{
				ft_putstr("0X");
				*i += 2;
				var->hash_mem = 1;
			}
			while (j--)
				ft_putchar('0');
			*i += ft_strlen(var->s);
			while (*str)
				ft_putchar(ft_toupper(*(str++)));
		}
		else if (j <= 0)
			ft_printf_arg_lx_print_quinque(i, var);
	}
	else
		ft_printf_arg_lx_print_quinque(i, var);
}

void	ft_printf_arg_lx_print_quater(int *i, int j, t_var *var)
{
	if (var->champ_neg)
	{
		ft_printf_arg_lx_print_ter(i, var, var->s);
		ft_printf_arg_xlx_flag_zero(i, j, var);
	}
}

void	ft_printf_arg_lx_print_quinque(int *i, t_var *var)
{
	char	*str;

	str = var->s;
	if (var->flag_hash && var->x && !var->hash_mem)
	{
		*i += 2;
		ft_putstr("0x");
		var->hash_mem = 1;
	}
	if (var->x)
	{
		*i += ft_strlen(var->s);
		while (*str)
			ft_putchar(ft_toupper(*(str++)));
	}
}
