/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoif.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 08:30:22 by dcooray           #+#    #+#             */
/*   Updated: 2017/05/17 08:31:37 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long		power(int n)
{
	int	i;
	int	ite;

	i = 1;
	ite = 0;
	while (ite < n)
	{
		i *= 10;
		ite++;
	}
	return (i);
}

static double	ft_atoif_bis(const char *str, int neg, double rslt)
{
	const char	*tmp;
	int			len;

	tmp = str;
	len = 0;
	while (ft_isdigit(*tmp) && *tmp != '\0')
	{
		len++;
		tmp++;
	}
	if (len)
	{
		if (neg)
			rslt -= (double)ft_atoi(str) / power(len);
		else
			rslt += (double)ft_atoi(str) / power(len);
	}
	return (rslt);
}

double			ft_atoif(const char *str)
{
	double	rslt;
	int		neg;

	neg = 0;
	while (ft_isspace(*str) && *str != '\0')
		str++;
	if (*str == '-')
		neg = 1;
	rslt = (double)ft_atoi(str);
	while ((ft_isdigit(*str) || *str == '-' || *str == '+')
			&& *str != '\0')
		str++;
	if (*str == '.')
		str++;
	else
		return (rslt);
	rslt = ft_atoif_bis(str, neg, rslt);
	return (rslt);
}
