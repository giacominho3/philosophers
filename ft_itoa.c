/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:36:20 by gifulvi           #+#    #+#             */
/*   Updated: 2022/11/10 15:51:13 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib.h"

int	length(int nb, int base)
{
	int	count;

	count = 0;
	if (nb <= 0)
		++count;
	while (nb && ++count)
		nb /= base;
	return (count);
}

char	*ft_itoa(int nb)
{
	int			len;
	char		*str;
	const char	*digits = "0123456789";

	len = length(nb, 10);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len] = 0;
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
		str[0] = '-';
	while (nb)
	{
		if (nb > 0)
			str[--len] = digits[nb % 10];
		else
			str[--len] = digits[nb % 10 * -1];
		nb /= 10;
	}
	return (str);
}
