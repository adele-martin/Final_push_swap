/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademarti <ademarti@student.42berlin.de     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 15:26:22 by ademarti          #+#    #+#             */
/*   Updated: 2024/05/08 13:19:07 by ademarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	tiny_sort(t_s **s_a)
{
	if (stack_len(*s_a) == 2)
		sa(s_a);
	else if (stack_len(*s_a) == 3)
	{
		sort_three(s_a);
		return (0);
	}
	return (1);
}

void	sort_three(t_s **s_a)
{
	t_s	*biggest_node;

	biggest_node = find_max_value(*s_a);
	if (*s_a == biggest_node)
		ra(s_a);
	else if ((*s_a)->next == biggest_node)
		rra(s_a);
	if ((*s_a)->value > (*s_a)->next->value)
		sa(s_a);
}

void	sorting_stacks(t_s **a, t_s **b)
{
	if (stack_len(*a) > 3 && !stack_sorted(a))
		pb(a, b);
	if (stack_len(*a) > 3 && !stack_sorted(a))
		pb(a, b);
	while (stack_len(*a) > 3 && !stack_sorted(a))
	{
		prep_nodes_a(a, b);
		move_a_to_b(a, b);
	}
	tiny_sort(a);
	while (*b)
	{
		prep_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	set_index(*a);
	min_on_top(a);
}

void	find_cheapest(t_s	*stack)
{
	int		cheapest_value;
	t_s		*cheapest_node;
	t_s		*ptr;

	ptr = stack;
	if (!stack)
		return ;
	cheapest_value = INT_MAX;
	while (ptr)
	{
		if (ptr->cost < cheapest_value)
		{
			cheapest_value = ptr->cost;
			cheapest_node = ptr;
		}
		ptr = ptr->next;
	}
	cheapest_node->cheapest = true;
}
