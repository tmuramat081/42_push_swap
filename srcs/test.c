#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int	(*t_comparator)(const void *, const void *);

typedef struct s_binary {
	int hi;
	int lo;
}	t_binary;

int	cmp(const void *a, const void *b)
{
	int *ac;
	int *bc;

	ac = (int *)a;
	bc = (int *)b;
	if (*ac > *bc)
		return (1);
	else if (*ac < *bc)
		return (-1);
	return (0);
}

void	ft_memswap(void *a, void *b, size_t size)
{
	unsigned char	*cast_a;
	unsigned char	*cast_b;
	unsigned char	*a_end;
	unsigned char	tmp;

	cast_a = (unsigned char *)a;
	cast_b = (unsigned char *)b;
	a_end = a + size;
	while (cast_a < a_end)
	{
		tmp = *cast_a;
		*cast_a = *cast_b;
		*cast_b = tmp;
		cast_a++;
		cast_b++;
	}
}

void quickSort(void *base, int lo, int hi, size_t size, t_comparator cmp)
{
    void *pivot;
    int i;
	int	j;
    char *v;
	
    if(lo >= hi)
        return;
	v = base;
    pivot = v + size * lo;
    i = lo;
    j = hi;
    while(true) 
	{
        while (cmp(v + size * i, pivot) < 0) 
            i++;
        while (cmp(v + size * j, pivot) > 0) 
            j--;
        if (i >= j) 
            break;
		ft_memswap(v + i *size, v + j* size, size);
        i++;
        j--;
    }
    quickSort(base, lo, i - 1, size, cmp);
    quickSort(base, j + 1, hi, size, cmp);
}

void ft_qsort(void *base, size_t n, size_t size, t_comparator cmp) 
{
    quickSort(base, 0, n - 1, size, cmp);
}

int main (void)
{
	int arr[] = {3, 2, 1, 5, -1, -2};
	size_t	i;

	ft_qsort(arr, 6, sizeof(int), cmp);
	i = 0;
	while (i < 6)
	{
		printf("%d ", arr[i]);
		i++;
	}
	return (0);
}