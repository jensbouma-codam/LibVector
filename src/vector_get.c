/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_get.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/22 11:18:39 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/07/22 11:56:28 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	v_size(t_v *v)
{
	if (v)
		return (v->vector.total);
	return (-1);
}

void	*v_get(t_v *v, int index)
{
	void	*data;

	data = NULL;
	if (v)
	{
		if ((index >= 0) && (index < v->vector.total))
			data = v->vector.items[index];
	}
	return (data);
}
