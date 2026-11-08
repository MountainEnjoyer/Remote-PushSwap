/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:03:02 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/08 18:25:50 by mgrossen         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>

// Bitmask
# define FLAG_SIMPLE 1
# define FLAG_MEDIUM 2
# define FLAG_COMPLEXE 4
# define FLAG_ADAPTIVE 8
# define FLAG_BENCH 16

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

t_stack		*insert_tail(t_stack *tail, int data);
t_stack		*insert_head(t_stack *head, int data);
t_stack		*ft_stacknew(t_stack *head, int content);
int			wcount(char const *s, char c);
size_t		ft_strlen(const char *s);
size_t		ft_strstrlen(const char **s);
void		error(void);
char		*fetch_flag(char **verifs);
int			len_flag(char **flag);
char		*locate(char **av);
char		**locate_v(char **av);

#endif
