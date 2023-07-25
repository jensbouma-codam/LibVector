/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/21 00:35:36 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/07/25 21:34:07 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	v_init(t_v *v, size_t size, int (*free)(void *), t_v *parent)
{
	v->size = v_size;
	v->resize = v_resize;
	v->add = v_add;
	v->set = v_set;
	v->get = v_get;
	v->free = v_free;
	v->del = v_del;
	v->vector.capicity = INIT_CAPACITY;
	v->vector.total = 0;
	v->vector.items = malloc(size * v->vector.capicity);
	if (v->vector.items == NULL)
		return (FAILURE);
	v->vector.free = free;
	if (parent)
		if (parent->add(parent, (void *)v) == FAILURE)
			return (FAILURE);
	return (SUCCESS);
}

int	v_resize(t_v *v, int capicity)
{
	void	**items;

	if (v)
	{
		items = ft_realloc(v->vector.items, sizeof(void *) * capicity);
		if (items)
		{
			v->vector.items = items;
			v->vector.capicity = capicity;
			return (SUCCESS);
		}	
	}
	return (FAILURE);
}

int	v_del(t_v *v, int index)
{
	int	i;

	i = index;
	if (v)
	{
		if ((index >= 0) && (index < v->vector.total))
		{
			if (v->vector.free)
				v->vector.free(v->vector.items[index]);
			v->vector.items[index] = NULL;
			while (i < v->vector.total - 1)
			{
				v->vector.items[i] = v->vector.items[i + 1];
				v->vector.items[i + 1] = NULL;
				++i;
			}
			v->vector.total--;
			if ((v->vector.total > 0)
				&& (v->vector.total == (v->vector.capicity / 4)))
				v_resize(v, v->vector.capicity / 2);
			return (SUCCESS);
		}
	}
	return (FAILURE);
}

int	v_free(void *ptr)
{
	t_v	*v;

	v = (t_v *)ptr;
	if (v)
	{
		if (v->vector.free)
		{
			while (v->vector.total > 0)
			{
				v->vector.total--;
				if (v->vector.free(v->vector.items[v->vector.total]) == FAILURE)
					return (FAILURE);
				v->vector.items[v->vector.total] = NULL;
			}
		}
		free(v->vector.items);
		v->vector.items = NULL;
		v->vector.total = 0;
		return (SUCCESS);
	}
	return (FAILURE);
}
