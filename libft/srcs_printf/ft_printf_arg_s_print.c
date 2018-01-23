/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_s_print.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 06:07:40 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 17:59:40 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_s_print(int *i, t_var *var)
{
	char	*s;
	int		j;

	s = ft_strdup("(null)");
	if (var->flag_precision && !var->precision && !var->s && !var->champ)
	{
		*i += 6;
		ft_putstr("(null)");
	}
	else if (var->flag_precision && !var->precision)
		ft_printf_arg_sls_implicit_precision(var, i, &j);
	else if (!var->champ && var->precision)
		ft_printf_arg_s_print_ter(i, var, s);
	else if (var->champ)
		ft_printf_arg_s_print_bis(i, var, s);
	else
		ft_printf_arg_s_print_quater(i, var);
	ft_strdel(&s);
}

void	ft_printf_arg_s_print_bis(int *i, t_var *var, char *s)
{
	int	j;

	if (!var->precision || var->precision >= (int)ft_strlen(var->s))
		j = var->champ - ft_strlen(var->s);
	else
		j = var->champ - var->precision;
	if (j > 0)
	{
		if (!var->champ_neg)
		{
			*i += j;
			ft_printf_arg_sls_print_flag_zero(var, j);
			ft_printf_arg_s_print_ter(i, var, s);
		}
		if (var->champ_neg)
		{
			*i += j;
			ft_printf_arg_s_print_ter(i, var, s);
			ft_printf_arg_sls_print_flag_zero(var, j);
		}
	}
	else
		ft_printf_arg_s_print_ter(i, var, s);
}

void	ft_printf_arg_s_print_ter(int *i, t_var *var, char *s)
{
	int		j;

	if (var->precision)
	{
		if (var->s)
		{
			j = var->precision;
			if (j > (int)ft_strlen(var->s))
				*i += ft_strlen(var->s);
			else
				*i += j;
			while (j-- && *var->s != '\0')
				ft_putchar(*(var->s++));
		}
		else
			ft_printf_arg_s_print_quinque(var, i, &j, s);
	}
	else
		ft_printf_arg_s_print_quater(i, var);
}

void	ft_printf_arg_s_print_quater(int *i, t_var *var)
{
	if (var->s)
	{
		*i += ft_strlen(var->s);
		ft_putstr(var->s);
	}
	else
	{
		*i += 6;
		ft_putstr("(null)");
	}
}

void	ft_printf_arg_s_print_quinque(t_var *var, int *i, int *j, char *s)
{
	*j = var->precision - 6;
	if (*j > 0)
	{
		*i += *j;
		while (*(j--) && s)
			ft_putchar(*(s++));
	}
	else
		ft_printf_arg_s_print_quater(i, var);
}
