/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 08:55:08 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 19:09:10 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_char_len(long n, int base)
{
	int	len;

	len = 0;
	if (n < 0)
		n = -n;
	while (n >= base)
	{
		n = n / base;
		len++;
	}
	return (len);
}

static int	ft_inverse_neg(long *n)
{
	int	neg;

	neg = 0;
	if (*n < 0)
	{
		*n *= -1;
		neg = 1;
	}
	return (neg);
}

static char	*ft_itoa_base_bis(long n, int base, char **tab)
{
	if ((*tab = ft_strdup("0123456789abcdef")) == NULL)
		return (NULL);
	if (base < 2 || base > 16)
		return (NULL);
	if (n < 0 && base != 10)
		return (NULL);
	return ("0K");
}

char		*ft_itoa_base(long n, int base)
{
	char	*tab;
	char	*dest;
	int		i;
	int		neg;

	if (!ft_itoa_base_bis(n, base, &tab))
		return (NULL);
	if (n == LONG_MIN && base == 10)
		return (ft_strdup("-9223372036854775808"));
	neg = ft_inverse_neg(&n);
	i = ft_count_char_len(n, base);
	if (!(dest = (char *)malloc(sizeof(char) * (i + neg + 2))))
		return (NULL);
	dest[i + neg + 1] = '\0';
	while (i >= 0)
	{
		dest[i-- + neg] = tab[n % base];
		n = n / base;
	}
	if (neg)
		dest[0] = '-';
	ft_strdel(&tab);
	return (dest);
}
