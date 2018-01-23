/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_mod_bis.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:11:50 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 21:23:17 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_mod_valid_ter(char **format, int j, t_tab *tab)
{
	t_var	*var;
	int		i;
	char	*tmp;

	var = tab->var;
	i = 0;
	tmp = *format;
	while (i < j && *tmp)
	{
		ft_printf_flag(&tmp, var);
		ft_printf_champ(&tmp, var);
		ft_printf_precision_bis(&tmp, var, &i);
		ft_printf_specifier_bis(&tmp, var, &i);
		ft_printf_flag(&tmp, var);
		tmp++;
	}
}

void	ft_printf_precision_bis(char **format, t_var *var, int *i)
{
	if (**format == '.')
	{
		var->flag_precision = 1;
		(*format)++;
		(*i)++;
		var->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
		{
			(*format)++;
			(*i)++;
		}
		ft_printf_flag(format, var);
	}
}
