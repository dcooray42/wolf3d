/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 19:23:54 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 21:23:36 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_var	*init_var(void)
{
	t_var	*var;

	if ((var = (t_var *)ft_memalloc(sizeof(t_var))) == NULL)
		exit(EXIT_SUCCESS);
	var->champ = 0;
	var->champ_sign = 1;
	var->champ_neg = 0;
	var->precision = 0;
	var->flag_hash = 0;
	var->flag_zero = 0;
	var->flag_plus = 0;
	var->flag_minus = 0;
	var->flag_space = 0;
	var->flag_precision = 0;
	var->spe = '\0';
	var->f = 0;
	var->hash_mem = 0;
	return (var);
}

void	ft_printf_precision(char **format, t_var *var)
{
	if (**format == '.')
	{
		var->flag_precision = 1;
		(*format)++;
		var->precision = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
		ft_printf_flag(format, var);
	}
}

void	ft_printf_arg(va_list ap, char **format, int *i, t_var *var)
{
	ft_printf_flag(format, var);
	ft_printf_champ(format, var);
	ft_printf_precision(format, var);
	ft_printf_specifier(format, var);
	ft_printf_flag(format, var);
	ft_printf_arg_mod(*format, i, var);
	ft_printf_arg_s(ap, *format, i, var);
	ft_printf_arg_p(ap, *format, i, var);
	ft_printf_arg_di(ap, *format, i, var);
	ft_printf_arg_ld(ap, *format, i, var);
	ft_printf_arg_o(ap, *format, i, var);
	ft_printf_arg_lo(ap, *format, i, var);
	ft_printf_arg_u(ap, *format, i, var);
	ft_printf_arg_lu(ap, *format, i, var);
	ft_printf_arg_x(ap, *format, i, var);
	ft_printf_arg_lx(ap, *format, i, var);
	ft_printf_arg_c(ap, *format, i, var);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_var	*var;
	int		i;

	va_start(ap, format);
	i = 0;
	var = init_var();
	ft_printf_bis(ap, (char **)&format, &i, var);
	va_end(ap);
	ft_memdel((void **)&var);
	return (i);
}
