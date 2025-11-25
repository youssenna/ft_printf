/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 12:18:34 by yousenna          #+#    #+#             */
/*   Updated: 2025/11/25 10:49:44 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int	ft_putaddr(void *p)
{
	int	count;

	if (!p)
		return (ft_putstr("(nil)"));
	count = 0;
	if (!p)
		return (0);
	count = ft_putstr("0x") + ft_puthex((size_t)p, 'x');
	return (count);
}
