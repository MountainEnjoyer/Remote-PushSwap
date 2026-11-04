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

typedef struct stack
{
	int				content;
	int				index;
	struct stack	*next;
	struct stack	*previous;
}					stack_list;

stack_list	*ft_stacknew(int content, stack_list *prev);
int			wcount(char const *s, char c);
size_t		ft_strlen(const char *s);
void		error(char *er);

#endif
