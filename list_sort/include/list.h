/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 21:14:41 by swenn             #+#    #+#             */
/*   Updated: 2024/09/19 22:09:28 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

typedef struct s_list
{
	void *data;
	struct s_list *next; 
}	t_list;

int	croissant(int a, int b);

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));
