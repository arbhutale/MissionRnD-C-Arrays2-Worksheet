/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
int findSingleOccurenceNumber(int *A, int len)
{
	if (A == 0 || len == 0)
		return -1;
	int a[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int i = 0, j = 0;
	for (i = 0; i < len; i++)
	{
		a[A[i]]++;
	}
	for (j = 0; j <13; j++)
	{
		if (a[j] == 1)
			break;

	}
	return j;
}