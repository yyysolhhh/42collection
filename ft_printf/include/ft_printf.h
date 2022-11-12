/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yesollee <yesollee@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:47:51 by yesollee          #+#    #+#             */
/*   Updated: 2022/11/12 16:06:47 by yesollee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_print_pointer(void *ptr);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned int nbr, char format);

#endif
