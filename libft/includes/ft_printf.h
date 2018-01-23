/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 21:19:56 by dcooray           #+#    #+#             */
/*   Updated: 2017/03/13 21:31:51 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

# define HEX_MAX	4294967295

typedef struct	s_var
{
	int				champ;
	int				champ_sign;
	int				champ_neg;
	int				precision;
	int				flag_hash;
	int				flag_zero;
	int				flag_plus;
	int				flag_minus;
	int				flag_space;
	int				flag_precision;
	char			spe;
	int				f;
	int				hash_mem;
	char			*s;
	char			c;
	int				d;
	long			p;
	unsigned long	llo;
	long			x;
	long			ld;
	wchar_t			lc;
	wchar_t			*ls;
	unsigned int	u;
	unsigned long	lu;
	long			lo;
}				t_var;

typedef struct	s_tab
{
	char	*tab;
	char	*tab_v;
	t_var	*var;
}				t_tab;

t_var			*init_var(void);
t_tab			*init_tab(t_var *var);
void			destroy_tab(t_tab **tab);
void			ft_printf_flag(char **format, t_var *var);
int				ft_printf_flag_minus_plus(char *format);
int				ft_printf_flag_minus_plus_bis(char *format, char *tab,
					char *tab_arg);
void			ft_printf_flag_minus_plus_ter(char **tab, char **tab_arg);
void			ft_printf_champ(char **format, t_var *var);
void			ft_printf_champ_bis(t_var *var);
void			ft_printf_precision(char **format, t_var *var);
void			ft_printf_precision_bis(char **format, t_var *var, int *i);
void			ft_printf_arg_mod(char *format, int *i, t_var *var);
int				ft_printf_arg_mod_valid(char **format, t_var *var);
int				ft_printf_arg_mod_valid_bis(char **format, char **str,
					int *j, t_tab *tab);
void			ft_printf_arg_mod_valid_ter(char **format, int j, t_tab *tab);
void			ft_printf_specifier(char **format, t_var *var);
void			ft_printf_specifier_bis(char **format, t_var *var, int *i);
void			ft_printf_specifier_ter(char **format, t_var *var, int *i);
void			ft_printf_arg(va_list ap, char **format, int *i, t_var *var);
void			ft_printf_arg_c(va_list ap, char *format, int *i, t_var *var);
void			ft_printf_arg_nlc(va_list ap, int *i, t_var *var);
void			ft_printf_arg_hhlc(va_list ap, int *i, t_var *var);
void			ft_printf_arg_c_print(int *i, t_var *var);
void			ft_printf_arg_c_print_bis(int *i, t_var *var);
void			ft_printf_arg_lc_print(int *i, t_var *var);
void			ft_printf_arg_lc_print_bis(int *i, t_var *var);
int				ft_printf_arg_lc_size_return(wchar_t w);
void			ft_printf_arg_clc_flag_zero(int j, t_var *var);
void			ft_printf_arg_s(va_list ap, char *format, int *i,
					t_var *var);
void			ft_printf_arg_nlshhhls(va_list ap, char *format, int *i,
					t_var *var);
void			ft_printf_arg_s_print(int *i, t_var *var);
void			ft_printf_arg_sls_print_flag_zero(t_var *var, int j);
void			ft_printf_arg_sls_implicit_precision(t_var *var, int *i,
					int *j);
void			ft_printf_arg_s_print_bis(int *i, t_var *var, char *s);
void			ft_printf_arg_s_print_ter(int *i, t_var *var, char *s0);
void			ft_printf_arg_s_print_quater(int *i, t_var *var);
void			ft_printf_arg_s_print_quinque(t_var *var, int *i, int *j,
					char *s);
void			ft_printf_arg_ls_print(int *i, t_var *var);
void			ft_printf_arg_ls_print_bis(int *i, t_var *var, char *s);
void			ft_printf_arg_ls_print_ter(int *i, t_var *var, char *s);
void			ft_printf_arg_ls_print_quater(int *i, t_var *var);
void			ft_printf_arg_ls_print_quinque(t_var *var, int *i, int *j,
					char *s);
void			ft_printf_arg_ls_print_sexa(t_var *var, int *i, int j, char *s);
void			ft_printf_arg_p(va_list ap, char *format, int *i, t_var *var);
void			ft_printf_arg_p_flag_zero(int *i, int j, t_var *var);
void			ft_printf_arg_p_implicit_precision(t_var *var, int *i, int *j);
void			ft_printf_arg_p_print(int *i, t_var *var);
void			ft_printf_arg_p_print_bis(int *i, t_var *var);
void			ft_printf_arg_p_print_ter(int *i, t_var *var);
void			ft_printf_arg_p_print_quater(int *i, int j, t_var *var);
void			ft_printf_arg_p_print_quinque(int *i, t_var *var);
void			ft_printf_arg_di(va_list ap, char *format, int *i, t_var *var);
void			ft_printf_arg_di_flag_zero(int j, t_var *var);
void			ft_printf_arg_di_implicit_precision(t_var *var, int *i, int *j);
void			ft_printf_arg_nllljzdi(va_list ap, int *i, t_var *var);
void			ft_printf_arg_hhhdi(va_list ap, int *i, t_var *var);
void			ft_printf_arg_di_print(int *i, t_var *var);
void			ft_printf_arg_di_pos_zero_print(int *i, t_var *var);
void			ft_printf_arg_di_pos_zero_print_bis(int *i, t_var *var);
void			ft_printf_arg_di_pos_zero_print_ter(int *i, t_var *var);
void			ft_printf_arg_di_pos_zero_print_quater(int *i, t_var *var);
void			ft_printf_arg_di_pos_zero_print_quinque(int *i, int *j,
					t_var *var);
void			ft_printf_arg_di_pos_zero_print_sexa(int *i, int j, t_var *var);
void			ft_printf_arg_di_neg_print(int *i, t_var *var);
void			ft_printf_arg_di_neg_print_bis(int *i, t_var *var);
void			ft_printf_arg_di_neg_print_ter(int *i, t_var *var);
void			ft_printf_arg_ld(va_list ap, char *format, int *i, t_var *var);
void			ft_printf_arg_ld_print(int *i, t_var *var);
void			ft_printf_arg_ld_print_bis(int *i, t_var *var);
void			ft_printf_arg_ld_print_ter(int *i, t_var *var);
void			ft_printf_arg_nllljzld(va_list ap, int *i, t_var *var);
void			ft_printf_arg_hhhld(va_list ap, int *i, t_var *var);
void			ft_printf_arg_o(va_list ap, char *format, int *i, t_var *var);
void			ft_printf_arg_olo_flag_zero(int *i, int j, t_var *var);
void			ft_printf_arg_olo_implicit_precision(t_var *var, int *i,
					int *j);
void			ft_printf_arg_nllljzo(va_list ap, int *i, t_var *var);
void			ft_printf_arg_hhho(va_list ap, int *i, t_var *var);
void			ft_printf_arg_o_print(int *i, t_var *var);
void			ft_printf_arg_o_print_bis(int *i, t_var *var);
void			ft_printf_arg_o_print_ter(int *i, t_var *var);
void			ft_printf_arg_o_print_quater(int *i, int j, t_var *var);
void			ft_printf_arg_o_print_quinque(int *i, t_var *var);
void			ft_printf_arg_lo(va_list ap, char *format, int *i, t_var *var);
void			ft_printf_arg_nllljzlo(va_list ap, int *i, t_var *var);
void			ft_printf_arg_hhhlo(va_list ap, int *i, t_var *var);
void			ft_printf_arg_lo_print(int *i, t_var *var);
void			ft_printf_arg_lo_print_bis(int *i, t_var *var);
void			ft_printf_arg_lo_print_ter(int *i, t_var *var);
void			ft_printf_arg_lo_print_quater(int *i, int j, t_var *var);
void			ft_printf_arg_lo_print_quinque(int *i, t_var *var);
void			ft_printf_arg_u(va_list ap, char *format, int *i, t_var *var);
void			ft_printf_arg_ulu_flag_zero(int j, t_var *var);
void			ft_printf_arg_ulu_implicit_precision(t_var *var, int *i,
					int *j);
void			ft_printf_arg_nllljzu(va_list ap, int *i, t_var *var);
void			ft_printf_arg_hhhu(va_list ap, int *i, t_var *var);
void			ft_printf_arg_u_print(int *i, t_var *var);
void			ft_printf_arg_u_print_bis(int *i, t_var *var);
void			ft_printf_arg_u_print_ter(int *i, t_var *var);
void			ft_printf_arg_u_print_quater(int *i, int j, t_var *var);
void			ft_printf_arg_lu(va_list ap, char *format, int *i, t_var *var);
void			ft_printf_arg_lu_print(int *i, t_var *var);
void			ft_printf_arg_nllljzlu(va_list ap, int *i, t_var *var);
void			ft_printf_arg_hhhlu(va_list ap, int *i, t_var *var);
void			ft_printf_arg_x(va_list ap, char *format, int *i, t_var *var);
void			ft_printf_arg_xlx_flag_zero(int *i, int j, t_var *var);
void			ft_printf_arg_xlx_implicit_precision(t_var *var, int *i,
					int *j);
void			ft_printf_arg_nx(va_list ap, int *i, t_var *var);
void			ft_printf_arg_hhhllljzx(va_list ap, int *i, t_var *var);
void			ft_printf_arg_x_print(int *i, t_var *var);
void			ft_printf_arg_x_print_bis(int *i, t_var *var);
void			ft_printf_arg_x_print_ter(int *i, t_var *var);
void			ft_printf_arg_x_print_quater(int *i, int j, t_var *var);
void			ft_printf_arg_x_print_quinque(int *i, t_var *var);
void			ft_printf_arg_lx(va_list ap, char *format, int *i, t_var *var);
void			ft_printf_arg_nlx(va_list ap, int *i, t_var *var);
void			ft_printf_arg_hllljzlx(va_list ap, int *i, t_var *var);
void			ft_printf_arg_hhlx(va_list ap, int *i, t_var *var);
void			ft_printf_arg_lx_print(int *i, t_var *var);
void			ft_printf_arg_lx_print_bis(int *i, t_var *var);
void			ft_printf_arg_lx_print_ter(int *i, t_var *var, char *str);
void			ft_printf_arg_lx_print_quater(int *i, int j, t_var *var);
void			ft_printf_arg_lx_print_quinque(int *i, t_var *var);
void			ft_printf_reset(t_var *var);
void			ft_printf_quater(char **format, int *i, t_var *var);
void			ft_printf_ter(va_list ap, char **format, int *i, t_var *var);
void			ft_printf_bis(va_list ap, char **format, int *i, t_var *var);
int				ft_printf(const char *format, ...);

#endif
