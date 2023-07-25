/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector_mem.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/25 21:31:33 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/07/25 21:34:27 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}	
	return (dst);
}

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}
