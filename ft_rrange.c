/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:45:10 by swenn             #+#    #+#             */
/*   Updated: 2024/09/29 17:06:55 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	size;
	int	i;
	int	*tab;

	size = start - end;
	if (size < 0)
		size *= -1;
	i = 0;
	tab = malloc(sizeof(int) * size);
	while (end != start)
	{
		tab[i] = end;
		if (start > end)
			end++;
		if (start < end)
			end--;
		i++;
	}
	tab[i] = start;
	return (tab);
}
