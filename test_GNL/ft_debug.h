/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_debug.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 20:02:35 by florian           #+#    #+#             */
/*   Updated: 2018/12/11 14:47:34 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEBUG_H
# define FT_DEBUG_H

#include <stdio.h>
#include "libft/libft.h"
#include "get_next_line.h"

#define NRM  "\x1B[0m"
#define FAIL  "\x1B[31m"
#define OK  "\x1B[32m"
#define KO  "\x1B[33m"
#define BLU  "\x1B[34m"

//#define debug(x) printf(BLU"Debug ->"OK"  %d\n", x); printf(FAIL);
#define DEBUG(x) printf(BLU"Debug ->"OK"  %s\n", x); printf(FAIL);
//#define DEBUG_LOG(x)	fprintf(stderr, OK"%s line %d\n",__FILE__,__LINE__); printf(x); printf("\n"); printf(FAIL);

#endif
