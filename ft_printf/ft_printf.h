/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrush <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:12:20 by atrush            #+#    #+#             */
/*   Updated: 2017/01/09 14:14:38 by atrush           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include <wchar.h>

int				ft_printf(const char *restrict format, ...);
int				ft_atoi(const char *nptr);
void			ft_toupper(char **str);
size_t			ft_strlen(char *str);
size_t			ft_strlen_u(unsigned char *str);
unsigned char	*unicode(wchar_t c);
int				ft_strrealcat(unsigned char **str1, unsigned char **str2);
char			*ft_itoa_ll(long long int value, int base);
char			*ft_itoa_u(unsigned long long int value, int base);
char			*ft_itoa_size_t(size_t value, int base);
int				check_flags(const char *restrict str, int *i, int frmt[9]);
int				check_size_modifier(const char *restrict str, int *i,
				int frmt[9]);
int				check_precision(const char *restrict str, int *i,
				va_list args, int frmt[9]);
int				check_width(const char *restrict str, int *i,
				va_list args, int frmt[9]);
int				check_type(const char *restrict str, int *i,
				va_list args, int frmt[9]);
int				type_s(va_list args, int frmt[9]);
int				type_ls(va_list args, int frmt[9], int i);
int				type_p(va_list args, int frmt[9]);
int				type_c(va_list args, int frmt[9], int flag);
int				type_lc(va_list args, int frmt[9]);
int				print(void *str, int frmt[9], size_t size);

#endif
