/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_setters.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/22 11:23:18 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/07/22 11:25:04 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	v_add(t_v *v, void *item)
{
	if (v)
	{
		if (v->vector.capicity == v->vector.total)
		{
			if (v_resize(v, v->vector.capicity * 2))
			{
				v->vector.items[v->vector.total++] = item;
				return (SUCCESS);
			}
		}
		else
		{
			v->vector.items[v->vector.total++] = item;
			return (SUCCESS);
		}
	}
	return (FAILURE);
}

int	v_set(t_v *v, int index, void *data)
{
	if (v)
	{
		if ((index >= 0) && (index < v->vector.total))
		{
			v->vector.items[index] = data;
			return (SUCCESS);
		}
	}
	return (FAILURE);
}
