/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_ls_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:13:54 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:13:55 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_ls_print(int *i, t_var *var)
{
	char	*s;
	int		j;

	s = ft_strdup("(null)");
	if (var->flag_precision && !var->precision && !var->ls && !var->champ)
	{
		*i += 6;
		ft_putstr("(null)");
	}
	else if (var->flag_precision && !var->precision)
		ft_printf_arg_sls_implicit_precision(var, i, &j);
	else if (!var->champ && var->precision)
		ft_printf_arg_ls_print_ter(i, var, s);
	else if (var->champ)
		ft_printf_arg_ls_print_bis(i, var, s);
	else
		ft_printf_arg_ls_print_quater(i, var);
	ft_strdel(&s);
}

void	ft_printf_arg_ls_print_bis(int *i, t_var *var, char *s)
{
	int		j;
	int		k;
	wchar_t	*tmp;

	k = 0;
	tmp = var->ls;
	if (!var->precision || var->precision >= (int)ft_wstrlen(var->ls))
		j = var->champ - ft_wstrlen(var->ls);
	else
	{
		while (var->precision >= k + ft_printf_arg_lc_size_return(*tmp))
			k += ft_printf_arg_lc_size_return(*(tmp++));
		j = var->champ - k;
	}
	if (j > 0)
		ft_printf_arg_ls_print_sexa(var, i, j, s);
	else
		ft_printf_arg_ls_print_ter(i, var, s);
}

void	ft_printf_arg_ls_print_ter(int *i, t_var *var, char *s)
{
	int		j;
	int		k;

	if (var->precision)
	{
		if (var->ls)
		{
			j = var->precision;
			k = 0;
			while (j > 0 && *var->ls != '\0')
			{
				k = ft_printf_arg_lc_size_return(*(var->ls));
				j -= k;
				if (j >= 0)
				{
					*i += k;
					ft_putwchar(*(var->ls++));
				}
			}
		}
		else
			ft_printf_arg_ls_print_quinque(var, i, &j, s);
	}
	else
		ft_printf_arg_ls_print_quater(i, var);
}

void	ft_printf_arg_ls_print_quater(int *i, t_var *var)
{
	if (var->ls)
	{
		*i += ft_wstrlen(var->ls);
		ft_putwstr(var->ls);
	}
	else
	{
		*i += 6;
		ft_putstr("(null)");
	}
}

void	ft_printf_arg_ls_print_quinque(t_var *var, int *i, int *j, char *s)
{
	*j = var->precision - 6;
	if (*j > 0)
	{
		*i += *j;
		while (*(j--) && s)
			ft_putchar(*(s++));
	}
	else
		ft_printf_arg_ls_print_quater(i, var);
}
