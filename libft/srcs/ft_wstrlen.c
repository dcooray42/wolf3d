/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:30:59 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 17:31:00 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(const wchar_t *wchar)
{
	size_t	i;

	i = 0;
	while (*wchar)
	{
		if (*wchar <= 0x7F)
			i += 1;
		else if (*wchar <= 0x7FF)
			i += 2;
		else if (*wchar <= 0xFFFF)
			i += 3;
		else if (*wchar <= 0x10FFFF)
			i += 4;
		wchar++;
	}
	return (i);
}
