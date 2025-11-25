/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 11:51:05 by yousenna          #+#    #+#             */
/*   Updated: 2025/11/24 19:01:06 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_puthex(size_t nb, char c)
{
	char	*hex;
	int		count;

	count = 0;
	if (c == 'x')
		hex = "0123456789abcdef";
	else if (c == 'X')
		hex = "0123456789ABCDEF";
	else
		return (0);
	if (nb >= 16)
		count += ft_puthex(nb / 16, c);
	count += ft_putchar(hex[nb % 16]);
	return (count);
}
