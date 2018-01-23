/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:29:35 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 17:30:39 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_reset(t_var *var)
{
	var->f = 0;
	var->hash_mem = 0;
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
}
