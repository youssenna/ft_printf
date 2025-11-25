/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:30:31 by yousenna          #+#    #+#             */
/*   Updated: 2025/11/25 22:24:09 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_putunsig(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr >= 10)
		count += ft_putunsig(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}
