/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_usigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 18:17:32 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 18:17:34 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_char_len(unsigned long n, unsigned int base)
{
	int	len;

	len = 0;
	while (n >= base)
	{
		n = n / base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base_usigned(unsigned long n, int base)
{
	char	*tab;
	char	*dest;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	if ((tab = ft_strdup("0123456789abcdef")) == NULL)
		return (NULL);
	i = ft_count_char_len(n, (unsigned int)base);
	if (!(dest = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	dest[i + 1] = '\0';
	while (i >= 0)
	{
		dest[i--] = tab[n % base];
		n = n / base;
	}
	free(tab);
	return (dest);
}
