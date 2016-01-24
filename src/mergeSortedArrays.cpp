/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdlib.h>

struct transaction
{
	int amount;
	char date[11];
	char description[20];
};


bool greaterthan(char date1[11], char date2[11])
{
	int     year1 = ((date1[6] - 48) * 1000) + ((date1[7] - 48) * 100) + ((date1[8] - 48) * 10) + date1[9] - 48;
	int  	month1 = (date1[3] - 48) * 10 + date1[4] - 48;
	int 	date11 = (date1[0] - 48) * 10 + date1[1] - 48;
	int     year2 = ((date2[6] - 48) * 1000) + ((date2[7] - 48) * 100) + ((date2[8] - 48) * 10) + date2[9] - 48;
	int  	month2 = (date2[3] - 48) * 10 + date2[4] - 48;
	int 	date21 = (date2[0] - 48) * 10 + date2[1] - 48;
	if (year1 > year2)return true;
	else if (year2 > year1) return false;
	else{
		if (month1 > month2)return true;
		else if (month2 > month1)return false;
		else{
			if (date11 > date21)return true;
			else return false;
		}
	}
}

void strcp(char result[20], char A[20])
{
	int i = 0;
	while (A[i] != '\0')
	{
		result[i] = A[i];
		i++;
	}
	result[i] = '\0';

}
void strswap(char str1[11], char str2[11])
{
	int i = 0; char temp;
	while (str2[i] != '\0')
	{
		temp = str1[i];
		str1[i] = str2[i];
		str2[i] = temp;
		i++;
	}
	str1[i] = '\0';
}
struct transaction *SortedArrays(struct transaction *Arr, int len)
{
	int i, j, temp;
	for (i = 1; i < len; i++)
	{
		for (j = 0; j < len - 1; j++)
		{
			if (greaterthan(Arr[j].date, Arr[j + 1].date))
			{
				temp = Arr[j].amount;
				Arr[j].amount = Arr[j + 1].amount;
				Arr[j + 1].amount = temp;
				strswap(Arr[j].date, Arr[j + 1].date);
				strswap(Arr[j].description, Arr[j + 1].description);
			}
		}
	}
	/*char a[11] = "123", b[11] = "456";
	strswap(tempdesc,a );
	strswap(a,b);
	strswap(b,tempdesc);
	printf("a=%s,b=%s", a, b);*/
	return Arr;
}

struct transaction *mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	if (ALen == 0 || BLen == 0)
		return NULL;
	if (A == NULL || B == NULL)
		return NULL;
	int k = 0, i = 0, j = 0, length;
	length = ALen + BLen;
	struct transaction *result = (struct transaction*)malloc(sizeof(struct transaction)* length + 1);
	for (i = 0; i < ALen; i++)
	{
		result[i].amount = A[i].amount;
		strcp(result[i].date, A[i].date);
		strcp(result[i].description, A[i].description);
	}
	for (int j = i, k = 0; j < length; j++, k++)
	{
		result[j].amount = B[k].amount;
		strcp(result[j].date, B[k].date);
		strcp(result[j].description, B[k].description);
	}
	result = SortedArrays(result, length);

	return result;
}