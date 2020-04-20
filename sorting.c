#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sorting.h"


void merge(long *array, long *temp, int l, int m, int r)
{
	int a = l;
	int b = m+1;
	//int size = r - l + 1;
	int indx = l;
	while(a <= m && b <= r)
	{
		if(array[a] < array[b])
		{
			temp[indx++] = array[a++];
		}else{
			temp[indx++] = array[b++];
		}
	}
	while(a <= m)
	{
		temp[indx++] = array[a++];
	}
	while(b <= r)
	{
		temp[indx++] = array[b++];
	}
	/*for(int x=l;x<r;x++)
	{
		array[x] = temp[x];
	}*/

	return;
}

void msort(long *array, long *temp, int l, int r, int which)
{
	if(r <= l) return;

	int m = (l+r)/2;
	if(which == 0)
	{
		msort(array,temp, l, m, 1);
		msort(array,temp, m+1, r, 1);
		merge(temp,array, l, m, r);
	}else{
		msort(array,temp, l, m, 0);
		msort(array,temp, m+1, r, 0);
		merge(array,temp, l, m, r);
	}
	
}

void Merge_Sort(long *Array, int Size)
{
	long *temp = malloc(Size * sizeof(long));
	msort(Array, temp, 0, Size - 1,0);
	free(temp);
}


int partition(long *array, int lb, int ub)
{
	long pivot = array[lb];
	int l = lb;
	int r = ub;
	long temp;
	while(l < r)
	{
		while(array[l] <= pivot && l < r)
		{
			l++;
		}
		while(array[r] > pivot)
		{
			r--;
		}
		if(l < r)
		{
			temp = array[l];
			array[l] = array[r];
			array[r] = temp;
		}
	}
	array[lb] = array[r];
	array[r] = pivot;

	return r;
	
}

void printarray(long *array,int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%ld.  ", array[i]);
	}
	printf("\n");
}

void q_sort(long *array, int lb, int ub)
{
	if(ub <= lb) return;

	int pivotloc = partition(array, lb, ub);
	//printarray(array, 20);
	q_sort(array, lb, pivotloc-1);
	q_sort(array, pivotloc+1, ub);
}

void Quick_Sort(long *Array, int Size)
{
	q_sort(Array, 0, Size - 1);
}

