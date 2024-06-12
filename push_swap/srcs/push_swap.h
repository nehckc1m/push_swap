/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:23:14 by micchen           #+#    #+#             */
/*   Updated: 2024/05/27 17:59:01 by micchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>

typedef struct nbr_node
{
	int				value;
	int 				index;
	int				cost;
	bool				above_mediane;
	bool				cheapest;
	struct nbr_node *target;
	struct nbr_node	*next;
	struct nbr_node	*previous;	
}	t_stack;

//operation
void	push(t_stack **from, t_stack **to, char n);
void 	rotate_stack(t_stack **a, char n);
void 	rev_rotate_stack(t_stack **a, char n);
void 	rr(t_stack **a, t_stack **b, int n);
void 	rrr(t_stack **a, t_stack **b, int n);
#endif
