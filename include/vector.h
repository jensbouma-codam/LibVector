/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/22 11:19:15 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/07/25 21:34:35 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define INIT_CAPACITY	6
# define SUCCESS		1
# define FAILURE		0

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_v	t_v;
struct s_v
{
	struct s_vector
	{
		void	**items;
		int		capicity;
		int		total;
		int		(*free)(void *);
	}		vector;
	int		(*size)(t_v *);
	int		(*resize)(t_v *, int);
	int		(*add)(t_v *, void *);
	int		(*set)(t_v *, int, void *);
	void	*(*get)(t_v *, int);
	int		(*del)(t_v *, int);
	int		(*free)(void *);
};

typedef struct s_test
{
	int		test1;
	int		test2;
	int		test3;
	char	*test;
}	t_test;

int		v_init(t_v *v, size_t size, int (*free)(void *), t_v *parent);
int		v_size(t_v *v);
int		v_resize(t_v *v, int capicity);
int		v_add(t_v *v, void *item);
int		v_set(t_v *v, int index, void *data);
void	*v_get(t_v *v, int index);
int		v_del(t_v *v, int index);
int		v_free(void *ptr);
void	*ft_realloc(void *ptr, size_t size);

#endif
