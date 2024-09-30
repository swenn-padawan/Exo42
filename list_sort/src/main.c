/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:47:04 by swenn             #+#    #+#             */
/*   Updated: 2024/09/30 15:11:46 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

t_list	*node_init(void	*data)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node)
	{
		node->data = data;
	}
	return (node);
}

void	push(t_list	**head, t_list *node)
{
	if (node)
	{	
		node->next = *head;
		*head = node;
	}
}

void	print_list(t_list **head)
{
	t_list	*temp;

	if (head)
	{
		temp = *head;
		while (temp->next)
		{	
			printf("%d ", temp->data);
			temp = temp->next;
		}
		printf("%d\n", temp->data);
	}
}

int	main()
{
	t_list	*list;

	list = NULL;
	push(&list, node_init(5));
	push(&list, node_init(4));
	push(&list, node_init(3));
	push(&list, node_init(2));
	push(&list, node_init(1));
	print_list(&list);
	sort_list(list, (croissant));
	print_list(&list);
}
