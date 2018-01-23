/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_lu_print.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:16:01 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:16:02 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_lu_print(int *i, t_var *var)
{
	int	j;

	if (var->flag_precision && !var->precision && !var->lu)
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
