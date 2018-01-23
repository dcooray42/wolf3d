/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:07:02 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:07:03 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_s(va_list ap, char *format, int *i, t_var *var)
{
	if (*format == 's' || *format == 'S')
	{
		ft_printf_arg_nlshhhls(ap, format, i, var);
		var->f = 1;
	}
}

void	ft_printf_arg_nlshhhls(va_list ap, char *format, int *i, t_var *var)
{
	if (*format == 's' && var->spe == '\0')
	{
		var->s = va_arg(ap, char *);
		ft_printf_arg_s_print(i, var);
	}
	if ((*format == 's' && var->spe == 'l') || (*format == 'S' &&
		(var->spe == '\0' || var->spe == 'H')))
	{
		var->ls = va_arg(ap, wchar_t *);
		ft_printf_arg_ls_print(i, var);
	}
}

void	ft_printf_arg_sls_print_flag_zero(t_var *var, int j)
{
	int	tmp;

	tmp = j;
	if (var->flag_zero && !var->flag_minus && !var->champ_neg)
		while (tmp--)
			ft_putchar('0');
	else
		while (tmp--)
			ft_putchar(' ');
}

void	ft_printf_arg_sls_implicit_precision(t_var *var, int *i, int *j)
{
	if (var->champ)
	{
		*j = var->champ;
		*i += *j;
		ft_printf_arg_sls_print_flag_zero(var, *j);
	}
}

void	ft_printf_arg_ls_print_sexa(t_var *var, int *i, int j, char *s)
{
	if (!var->champ_neg)
	{
		*i += j;
		ft_printf_arg_sls_print_flag_zero(var, j);
		ft_printf_arg_ls_print_ter(i, var, s);
	}
	if (var->champ_neg)
	{
		*i += j;
		ft_printf_arg_ls_print_ter(i, var, s);
		ft_printf_arg_sls_print_flag_zero(var, j);
	}
}
