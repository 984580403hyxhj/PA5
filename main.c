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
	//for(int i =0;i<1000;i++)
	//	{printf("%ld\n", arr[i]);}
	fclose(fp);
	return arr;

}

int Array_Save_To_File(char *filename, long *array, int size)
{
	FILE *fp = fopen(filename, "wb");
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

int main(int argc, char** argv)
{
    

	return EXIT_SUCCESS;
}
