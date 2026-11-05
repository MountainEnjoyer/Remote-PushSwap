/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:03:02 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/04 17:04:55 by zchauve          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>

typedef struct t_stack
{
	int				content;
	int				index;
	struct t_stack	*next;
	struct t_stack	*previous;
}					s_stack;

s_stack		*ft_stacknew(int content, s_stack *prev);
int			wcount(char const *s, char c);
size_t		ft_strlen(const char *s);
size_t		ft_strstrlen(const char **s);
void		error(void);
char		*fetch_flag(char **verifs);
int			len_flag(char **flag);
char		*locate(char **av);
char		**locate_v(char **av);

#endif
