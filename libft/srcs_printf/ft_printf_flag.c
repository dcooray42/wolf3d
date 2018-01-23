/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 05:03:19 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 21:21:40 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_flag(char **format, t_var *var)
{
	if (**format == '#' || **format == '0' || **format == ' ' ||
		ft_printf_flag_minus_plus(*format))
	{
		if (**format == '#')
			var->flag_hash = 1;
		if (**format == '0' && *(*format - 1) != '-' &&
			!ft_isdigit(*(*format - 1)))
			var->flag_zero = 1;
		if (**format == '+')
		{
			if (var->flag_minus)
				var->flag_minus = 0;
			var->flag_plus = 1;
		}
		if (**format == '-')
		{
			if (var->flag_plus)
				var->flag_plus = 0;
			var->flag_minus = 1;
		}
		if (**format == ' ')
			var->flag_space = 1;
	}
}

int		ft_printf_flag_minus_plus(char *format)
{
	char	*tab;
	char	*tab_arg;
	int		i;

	if ((tab = ft_strdup("#0123456789+-. ")) == NULL)
		exit(EXIT_SUCCESS);
	if ((tab_arg = ft_strdup("diu")) == NULL)
		exit(EXIT_SUCCESS);
	while (*format)
	{
		if ((i = ft_printf_flag_minus_plus_bis(format, tab, tab_arg)) != 2)
			return (i);
		format++;
	}
	ft_printf_flag_minus_plus_ter(&tab, &tab_arg);
	return (0);
}

int		ft_printf_flag_minus_plus_bis(char *format, char *tab, char *tab_arg)
{
	int	i;

	i = 0;
	while (tab_arg[i])
		if (*format == tab_arg[i++])
		{
			ft_printf_flag_minus_plus_ter(&tab, &tab_arg);
			return (1);
		}
	i = 0;
	while (tab[i] && *format != tab[i])
	{
		i++;
		if (tab[i] == '\0')
		{
			ft_printf_flag_minus_plus_ter(&tab, &tab_arg);
			return (0);
		}
	}
	return (2);
}

void	ft_printf_flag_minus_plus_ter(char **tab, char **tab_arg)
{
	ft_strdel(tab);
	ft_strdel(tab_arg);
}
