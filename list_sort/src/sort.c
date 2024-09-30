/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:19:05 by swenn             #+#    #+#             */
/*   Updated: 2024/09/30 15:24:32 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

int	croissant(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list *lst, int(*cmp)(int, int))
{
	t_list	*temp;
	t_list	*swap_node;
	t_list	*current;

	if (!lst)
		return (NULL);
	temp = lst;
	swap_node->data = NULL;
	while (current->next)
	{	
		while (temp->next)
		{
			if ((cmp)(temp->data, temp->next->data))
			{
				swap_node->data = temp->data;
				temp->data = temp->next->data;
				temp->next->data = swap_node->data;
			}
			temp = temp->next;
		}
		temp = lst;
		current = current->next;
	}
	return (temp);
}
