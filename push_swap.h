/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zchauve <zchauve@student.42.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:03:02 by zchauve           #+#    #+#             */
/*   Updated: 2026/11/15 16:32:29 by zchauve          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>

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
char		**fetch_flag(char **verifs);
int			len_flag(char **flag);
char		*locate(char **av);
char		**locate_v(char **av);
int			count_flag(char **flag);
t_stack		*indexator(t_stack *head);
int			len_stack(t_stack *head);
void		ft_ps_logic(t_stack *stack_a, int flags);

// PS operations utils
void		print_operation(char *operation_str);
void		swap_toptwo(t_stack *stack);
t_stack		*pop_head(t_stack **stack);
void		push_head(t_stack **stack, t_stack *node);

// PS operations
void		sa(t_stack **stack);
void		sb(t_stack **stack);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

#endif
