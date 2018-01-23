/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_di_neg_print.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:16:52 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:16:53 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_di_neg_print(int *i, t_var *var)
{
	if (!var->champ && var->precision)
		ft_printf_arg_di_neg_print_ter(i, var);
	else if (var->champ)
		ft_printf_arg_di_neg_print_bis(i, var);
	else
	{
		*i += ft_strlen(var->s);
		ft_putstr(var->s);
	}
}

void	ft_printf_arg_di_neg_print_bis(int *i, t_var *var)
{
	int	j;

	if (var->precision >= (int)ft_strlen(var->s))
		j = var->champ - var->precision - 1;
	else
		j = var->champ - ft_strlen(var->s);
	if (j > 0)
	{
		*i += j;
		if (!var->champ_neg)
		{
			if (var->flag_zero)
				ft_putchar('-');
			ft_printf_arg_di_flag_zero(j, var);
			ft_printf_arg_di_neg_print_ter(i, var);
		}
		if (var->champ_neg)
		{
			ft_printf_arg_di_neg_print_ter(i, var);
			ft_printf_arg_di_flag_zero(j, var);
		}
	}
	else
		ft_printf_arg_di_neg_print_ter(i, var);
}

void	ft_printf_arg_di_neg_print_ter(int *i, t_var *var)
{
	int	j;

	if (var->precision)
	{
		j = var->precision - ft_strlen(var->s) + 1;
		ft_putchar('-');
		if (j > 0)
		{
			*i += j;
			while (j--)
				ft_putchar('0');
		}
		*i += ft_strlen(var->s);
		ft_putstr(var->s + 1);
	}
	else
	{
		*i += ft_strlen(var->s);
		if (!var->champ_neg && var->flag_zero)
			ft_putstr(var->s + 1);
		else
			ft_putstr(var->s);
	}
}
