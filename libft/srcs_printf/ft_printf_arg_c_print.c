/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_c_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 22:41:38 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/07 08:13:00 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_c_print(int *i, t_var *var)
{
	if (var->champ)
		ft_printf_arg_c_print_bis(i, var);
	else
	{
		*i += 1;
		ft_putchar(var->c);
	}
}

void	ft_printf_arg_c_print_bis(int *i, t_var *var)
{
	int	j;

	j = var->champ - 1;
	if (j > 0 && !var->champ_neg)
	{
		*i += j + 1;
		ft_printf_arg_clc_flag_zero(j, var);
		ft_putchar(var->c);
	}
	else if (j > 0 && var->champ_neg)
	{
		*i += j + 1;
		ft_putchar(var->c);
		ft_printf_arg_clc_flag_zero(j, var);
	}
	else if (j <= 0)
	{
		*i += 1;
		ft_putchar(var->c);
	}
}

void	ft_printf_arg_lc_print(int *i, t_var *var)
{
	if (var->champ)
		ft_printf_arg_lc_print_bis(i, var);
	else
	{
		*i += ft_printf_arg_lc_size_return(var->lc);
		ft_putwchar(var->lc);
	}
}

void	ft_printf_arg_lc_print_bis(int *i, t_var *var)
{
	int	j;

	j = var->champ - 1;
	if (j > 0 && !var->champ_neg)
	{
		*i += ft_printf_arg_lc_size_return(var->lc);
		ft_printf_arg_clc_flag_zero(j, var);
		ft_putwchar(var->lc);
	}
	else if (j > 0 && var->champ_neg)
	{
		*i += ft_printf_arg_lc_size_return(var->lc);
		ft_putwchar(var->lc);
		ft_printf_arg_clc_flag_zero(j, var);
	}
	else if (j <= 0)
	{
		*i += ft_printf_arg_lc_size_return(var->lc);
		ft_putwchar(var->lc);
	}
}

int		ft_printf_arg_lc_size_return(wchar_t w)
{
	if (w <= 0x7F)
		return (1);
	else if (w <= 0x7FF)
		return (2);
	else if (w <= 0xFFFF)
		return (3);
	else if (w <= 0x10FFFF)
		return (4);
	return (0);
}
