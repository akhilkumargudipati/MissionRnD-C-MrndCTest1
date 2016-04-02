/*
Given an array which has two arithmetic sequences and 
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array  
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array  
will be start and end indexes of Second A.P 

The final_arr[4], final_arr[5] values in final array  
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index . 

Difficulty : Medium
there are three possibilites for the sequence(AAG,AGA,GAA)
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
int first_ari(int*ptr1, int temp1,int len);
void sec_ari(int*ptr1, int len);
void geo_pro(int*ptr1, int len);
int ari(int *prt, int len);
int final_array[6];
int *ptr1;
int * find_sequences(int *arr, int len)
{
	//Return final array which has 6indexes [AP1_S,AP1_E,AP2_S,AP2_E,GP1_S,GP2_E]
	int key;
	key = ari(arr, len);
	if (key == 0)
	{
		geo_pro(arr, len);
	}
	
	return NULL;
}
int first_ari(int*ptr1, int temp1,int len)
{
	int diff,temp,count=0;
	diff = *(ptr1 + 1) - *(ptr1);
	for (temp = temp1; temp < len; temp++)
	{
		if (*(ptr1+temp) - *ptr1 == diff)
		{
			++count;
		}
		else
			break;
	}
	if (count >= 1)
	{
		final_array[0] = temp1 + 1;
		final_array[1] = temp;
		final_array[2] = temp + 1;
		final_array[3] = len;
	}

	return 0;
}
void geo_pro(int*ptr1, int len)
{
	int temp, r,count=0;
	r = ptr1[1] / ptr1[0];
	for (temp = 1; temp < len; temp++)
	{
		if (ptr1[temp + 1] / ptr1[temp] != r)
			break;
	}
	final_array[4] = 0;
	final_array[5] = temp;
	first_ari(ptr1, temp,len);
}
int ari(int *ptr, int len)
{
	int diff, temp, count = 0;
	diff = *(ptr1 + 1) - *(ptr1);
	for (temp =0; temp < len; temp++)
	{
		if (*(ptr1 + 1) - *ptr1 == diff)
		{
			++count;
		}
		else
			break;
	}
	if (count >= 1)
	{
		final_array[0] = 0;
		final_array[1] = temp;
}