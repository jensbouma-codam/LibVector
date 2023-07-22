/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   example.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jensbouma <jensbouma@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/22 11:22:02 by jensbouma     #+#    #+#                 */
/*   Updated: 2023/07/22 11:36:50 by jensbouma     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

int	free_test(void *test)
{
	printf("Lets free the test\n");
	free(test);
	return (SUCCESS);
}

int	main2(void)
{
	t_v		v;
	t_v		v2;
	t_test	*test;
	int		i;

	v_init(&v, sizeof(void *), NULL, NULL);
	v_init(&v2, sizeof(t_test), free_test, NULL);
	v.add(&v, "TEST1234");
	v.add(&v, "TEST1235");
	v.add(&v, "JAHOOR");
	v.add(&v, "EN DRIE!");
	v.add(&v, "EN DRIE!");
	i = 0;
	while (i < v.size(&v))
	{
		printf("1> %s\n", (char *)v.get(&v, i));
		i++;
	}
	test = malloc(sizeof(t_test) * 1);
	test->test1 = 10;
	test->test2 = 20;
	test->test3 = 30;
	test->test = "Hallo12345\0";
	v.add(&v2, (void *)test);
	printf("int %i\n", (int)(((t_test *)v.get(&v2, 0))->test1));
	printf("int %i\n", (int)(((t_test *)v.get(&v2, 0))->test2));
	printf("int %i\n", (int)(((t_test *)v.get(&v2, 0))->test3));
	printf("Char %s\n", (char *)(((t_test *)v.get(&v2, 0))->test));
	v.set(&v, 1, "REPLACED");
	v.del(&v2, 0);
	v.del(&v, 0);
	i = 0;
	while (i < v.size(&v))
	{
		printf("1> %s\n", (char *)v.get(&v, i));
		i++;
	}
	i = 0;
	v.free(&v);
	v.free(&v2);
	i = 0;
	while (i < v.size(&v2))
	{
		printf("NIET PRITEN WANT IS ER NEIT> %s\n", (char *)v.get(&v2, i));
		i++;
	}
	return (0);
}


int	main(void)
{
	t_v		v;
	t_v		x;
	t_v		y;
	t_test	*test;
	t_test	*test2;

	v_init(&v, sizeof(t_v), v_free, NULL);
	v_init(&x, sizeof(void *), NULL, &v);
	v_init(&y, sizeof(t_test), free_test, &v);

	test = malloc(sizeof(t_test) * 1);
	test->test1 = 10;
	test->test2 = 20;
	test->test3 = 30;
	test->test = "Hallo12345\0";

	test2 = malloc(sizeof(t_test) * 1);
	test2->test1 = 10;
	test2->test2 = 20;
	test2->test3 = 30;
	test2->test = "Hallo12345\0";

	v.add(&x, "Dit is een test");
	v.add(&y, (void *)test);
	v.add(&y, (void *)test2);

	printf("int %i\n", (int)(((t_test *)v.get(&y, 0))->test1));
	printf("int %i\n", (int)(((t_test *)v.get(&y, 0))->test2));
	printf("int %i\n", (int)(((t_test *)v.get(&y, 0))->test3));
	printf("Char %s\n", (char *)(((t_test *)v.get(&y, 0))->test));

	printf("1> %s\n", (char *)v.get(&x, 0));
	if (v.free(&v) == SUCCESS)
		printf("Succesfully freed\n");
	else
		printf("Failed to free\n");
	main2();
}
