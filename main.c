#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sorting.h"

long *Array_Load_From_File(char *filename, int *size)
{
	FILE *fp;
	long *arr;
	fp = fopen(filename, "rb");
	if(fp == NULL) return NULL;

	fseek(fp,0,SEEK_END);
	//find the size of the file
	*size = ftell(fp);
	fseek(fp,0,SEEK_SET);
	*size = *size/sizeof(long);

	//alloc space for array
	arr = malloc(*size * sizeof(long));
	if(*size == 0)
	{
		fclose(fp);
		return arr;
	}
	fread(arr, sizeof(long), *size, fp);
	fclose(fp);
	return arr;

}

int Array_Save_To_File(char *filename, long *array, int size)
{
	FILE *fp = fopen(filename, "wb+");
	int count = 0;

	for(int indx = 0; indx < size; indx++)
	{
		//printf("%ld\n", array[indx]);
		count++;
		fwrite(&array[indx], sizeof(long), 1, fp);
	}

	fclose(fp);

	return count;
}

void issorted(long *array, int size)
{
	for(int i = 0; i < size-1; i++)
	{
		if(array[i] > array[i+1])
		{
			printf("%d:%ld,%d:%ld\n", i, array[i], i+1, array[i+1]);
			printf("not sorted\n");
			return;
		}
	}
	printf("sorted\n");
}

int main(int argc, char** argv)
{
	int size = 0;
	long *array = Array_Load_From_File(argv[2], &size);
	issorted(array, size);
	printf("size = %d\n", size);
	if(!strcmp(argv[1], "-m"))
	{
		Merge_Sort(array, size);	
	}
	if(!strcmp(argv[1],"-q"))
	{
		Quick_Sort(array, size);
	}
	
	issorted(array, size);

	return EXIT_SUCCESS;
}



