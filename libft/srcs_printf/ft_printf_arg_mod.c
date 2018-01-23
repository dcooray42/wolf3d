/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg_mod.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:09:20 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:10:15 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_arg_mod(char *format, int *i, t_var *var)
{
	int	j;

	if (*format == '%')
	{
		if (var->champ > 1 && var->champ_neg == 0)
		{
			j = var->champ - 1;
			*i += j;
			ft_printf_arg_clc_flag_zero(j, var);
			ft_putchar('%');
		}
		else if (var->champ > 1 && var->champ_neg == 1)
		{
			j = var->champ - 1;
			*i += j;
			ft_putchar('%');
			while (j--)
				ft_putchar(' ');
		}
		else
			ft_putchar('%');
		*i += 1;
		var->f = 1;
	}
}

int		ft_printf_arg_mod_valid(char **format, t_var *var)
{
	t_tab	*tab;
	int		i;
	int		j;
	char	*str;

	i = 2;
	j = 0;
	str = *format;
	tab = init_tab(var);
	while (*str && i && i != 1)
		i = ft_printf_arg_mod_valid_bis(format, &str, &j, tab);
	if (i == 1)
	{
		destroy_tab(&tab);
		return (1);
	}
	if ((*(*format - 1) == '%' && !str[i]) || (i == 2))
	{
		*format += j;
		destroy_tab(&tab);
		return (2);
	}
	destroy_tab(&tab);
	return (0);
}

int		ft_printf_arg_mod_valid_bis(char **format, char **str, int *j,
			t_tab *tab)
{
	int	i;

	i = 0;
	while (tab->tab[i])
		if (**str == tab->tab[i++])
			return (1);
	i = 0;
	while (tab->tab_v[i])
	{
		if (**str == tab->tab_v[i++])
		{
			*str += 1;
			*j += 1;
			return (2);
		}
		else if (!tab->tab_v[i])
		{
			ft_printf_arg_mod_valid_ter(format, *j, tab);
			*format += *j + 1;
			return (0);
		}
	}
	return (2);
}

t_tab	*init_tab(t_var *var)
{
	t_tab	*tab;

	if (!(tab = (t_tab *)malloc(sizeof(t_tab))))
		exit(EXIT_SUCCESS);
	if (!(tab->tab = ft_strdup("%sSpdDioOuUxXcC")))
		exit(EXIT_SUCCESS);
	if (!(tab->tab_v = ft_strdup("#0123456789 +-.hljz")))
		exit(EXIT_SUCCESS);
	if (var)
		tab->var = var;
	return (tab);
}

void	destroy_tab(t_tab **tab)
{
	t_tab	*tmp;

	tmp = *tab;
	ft_strdel(&(tmp->tab));
	ft_strdel(&(tmp->tab_v));
	ft_memdel((void **)tab);
}
