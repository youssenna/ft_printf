/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousenna <yousenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 10:21:23 by yousenna          #+#    #+#             */
/*   Updated: 2025/11/25 22:53:00 by yousenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int nbr);
int	ft_putunsig(unsigned int nbr);
int	ft_puthex(size_t nb, char c);
int	ft_putaddr(void *p);
int	ft_printf(const char *str, ...);

#endif
