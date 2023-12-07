/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:19:29 by ddemarco          #+#    #+#             */
/*   Updated: 2022/06/05 17:03:55 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft.h"
# include <stdarg.h>

# ifndef S_FORMAT
#  define S_FORMAT

typedef struct s_format
{
	int			active_format;
	int			buffer;
	int			buffer2;
	int			justify_left;
	int			buffer_justify;
	int			pad_0;
	int			arg_perc_on;
	int			argument_prec;
	int			print_sign;
	int			space_bf_value;
	char		preceed_val;
	int			sharp;
}	t_format;
# endif

//MACROS
# define TYPE_INT int
# define TYPE_CHAR int
# define TYPE_STR char *
# define TYPE_PTR unsigned long long
# define TYPE_UNSIGNED unsigned int
# define TYPE_HEXA unsigned int

int				ft_print_char(char c, t_format *data);
int				ft_print_int(int n, t_format *data);
int				ft_print_str(char *str, t_format *data);
int				ft_print_pointer(unsigned long long ptr, t_format *data);
int				ft_print_unsigned(unsigned int n, t_format *data);
int				ft_print_hexa(unsigned int n, const char fmat, t_format *data);
int				ft_pow(int base, int exponent);
void			ft_putnbr_unsig_fd(unsigned int n, int fd);
unsigned int	ft_unsig_num_len(unsigned int num);
int				ft_getnum_len(int num, t_format *data);
int				ft_process_arg(const char *fmat, va_list *args, t_format *data);
int				ft_proc_arg_utl(const char *fmat, va_list *args, t_format *dat);
int				ft_read_arg(const char *format, va_list *args, t_format *data);
const char		*ft_check_buffer(const char *format, t_format *data);
const char		*ft_check_format(const char *format, t_format *data);
const char		*ft_check_padding(const char *format, t_format *data);
void			ft_check_padding_util(const char *format, t_format *data);
void			ft_init_struct(t_format *data);
int				ft_write_sign(t_format *data, int *n, int *len);
int				ft_altbufferhandle(t_format *data, int len);
int				ft_write_format(t_format *data, int leng);
int				ft_write_format(t_format *format_data, int leng);
int				ft_write_format_n(t_format *data, int leng, int *n);
int				ft_write_format_un(t_format *data, int leng, unsigned int *n);
int				ft_printstr_fd(char *str, t_format *data, int *strlen, int fd);
void			ft_write_hexa(unsigned int n, const char format);
int				ft_int_zero(int *n, int n_len, int len, t_format *d);
void			ft_int_util(int n_len, int *len, t_format *d);
void			ft_int_ut2(int n, int *len, t_format *d);
void			ft_int_ut3(int n, int n_len, t_format *d, int *len);
int				ft_uint_zero(unsigned int *n, int n_len, int len, t_format *d);
void			ft_uint_util(int n_len, int *len, t_format *d);
void			ft_uint_ut2(unsigned int n, int *len, t_format *d);
void			ft_uint_ut3(unsigned int n, int n_len, int *len);
int				ft_hex_zero(unsigned int *n, int n_len, int len, t_format *d);
void			ft_hex_util(int n_len, int *len, t_format *d);
void			ft_hex_ut2(unsigned int n, const char f, int *len, t_format *d);
void			ft_hex_ut3(unsigned int n, int n_len, const char f, int *len);
int				ft_sharp_flag(unsigned int n, t_format *data, const char fmat);
const char		*ft_read_dot(const char *format, t_format *data);
void			ft_printnbr_fd(int n, t_format *data, int fd);
int				ft_printf(const char *format, ...);
#endif
