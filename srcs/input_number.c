#include <limits.h>
#include "push_swap.h"

bool	array_is_unique(int *arr, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while(j < size)
		{
			if (arr[i] == arr[j])
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

int	convert_number(char *str)
{
	char 	*endptr;
	long 	l_num;
	
	endptr = NULL;
	l_num = ft_strtol_d(str, &endptr);
	if (l_num < INT_MIN || INT_MAX < l_num)
		hundle_error(NULL);
	else if (*endptr || endptr == str)
		hundle_error(NULL);
	return ((int)l_num);
}

int	*input_numbers(char **args, size_t n)
{
	size_t	i;
	int 	*arr;

	arr = (int *)ft_xmalloc(sizeof(int) * (n));
	i = 0;
	while (i < n)
	{
		arr[i] = convert_number(args[i]);
		i++;
	}
	if (array_is_unique(arr, i) == false)
		hundle_error(NULL);
	return (arr);
}
