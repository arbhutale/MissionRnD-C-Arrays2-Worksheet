/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction
{
	int amount;
	char date[11];
	char description[20];
};
bool checkForEqual(char* Date1, char* Date2)
{
	int i = 0;
	int flag = 0;
	while (Date1[i] != '\0')
	{
		if (Date1[i] == Date2[i])
			i++;
		else
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		return false;
	else
		return true;

}
void strcp(char *result, char *A)
{

	int i = 0;;
	for (i = 0; A[i] != '\0'; i++)
	{
		result[i] = A[i];
	}
	result[i] = '\0';

}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen)
{
	int len = 0;
	int count = 0;
	int j = 0;
	if (A == NULL || B == NULL)
		return NULL;
	if (ALen < BLen)
		len = BLen;
	else
		len = ALen;
	struct transaction *result = (transaction*)malloc(sizeof(transaction) * 5);

	for (int i = 0; i < len; i++)
	{
		if (A[i].amount == B[i].amount)
		{
			if (checkForEqual(A[i].date, B[i].date))
			{
				if (checkForEqual(A[i].description, B[i].description))
				{
					//result[j].date = (char *)malloc(sizeof(char) * 20);

					count++;
					result[j].amount = A[i].amount;
					strcp(result[j].date, A[i].date);
					//printf("%d", result[0].amount);
					strcp(result[j].description, A[i].description);
					j++;
				}
				else
					continue;
			}
			else
				continue;
		}
		else
			continue;
	}
	if (count == 0)
		return NULL;
	//printf("%s", result[0].date);
	return result;
}