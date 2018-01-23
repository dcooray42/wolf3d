/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_champ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:22:33 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 21:18:14 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_champ(char **format, t_var *var)
{
	if (var->champ)
		return ;
	if ((**format == '+' || **format == '-' || (ft_isdigit(**format) &&
					**format != '0')))
	{
		if (**format == '-')
			var->champ_sign = -1;
		while (**format == '+' || **format == '-' || **format == ' ' ||
				**format == '#')
		{
			(*format)++;
			ft_printf_flag(format, var);
		}
		if (ft_isdigit(**format) && **format != '0')
			var->champ = var->champ_sign * ft_atoi(*format);
		else
			return ;
	}
	else
		return ;
	ft_printf_champ_bis(var);
}

void		ft_printf_champ_bis(t_var *var)
{
	if (var->champ < 0)
	{
		var->champ *= -1;
		var->champ_neg = 1;
	}
	else if (var->champ > 0)
		var->champ_neg = 0;
}
