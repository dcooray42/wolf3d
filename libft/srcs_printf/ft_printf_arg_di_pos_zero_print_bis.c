/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_di_pos_zero_print_bis.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:16:46 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:16:47 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_di_implicit_precision(t_var *var, int *i, int *j)
{
	if (var->champ)
	{
		*j = var->champ;
		*i += *j;
		ft_printf_arg_di_flag_zero(*j, var);
	}
}

void	ft_printf_arg_di_pos_zero_print_quinque(int *i, int *j, t_var *var)
{
	if (var->flag_space && !var->flag_plus && !var->flag_minus)
	{
		(*j)--;
		ft_putchar(' ');
	}
	if (!var->champ_neg)
	{
		if (var->flag_plus)
		{
			(*j)--;
			if (var->flag_zero)
				ft_putchar('+');
		}
		ft_printf_arg_di_flag_zero(*j, var);
		if (var->flag_plus && !var->flag_zero)
			ft_putchar('+');
		ft_printf_arg_di_pos_zero_print_ter(i, var);
	}
}

void	ft_printf_arg_di_pos_zero_print_sexa(int *i, int j, t_var *var)
{
	if (var->champ_neg)
	{
		if (var->flag_plus)
		{
			j--;
			if (var->flag_zero)
				ft_putchar('+');
		}
		if (var->flag_plus && !var->flag_zero)
			ft_putchar('+');
		ft_printf_arg_di_pos_zero_print_ter(i, var);
		ft_printf_arg_di_flag_zero(j, var);
	}
}
