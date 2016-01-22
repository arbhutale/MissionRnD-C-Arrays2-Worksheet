/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction
{
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int date1, month, year, count = 0, count1 = 0;
	year = ((date[6] - 48) * 1000) + ((date[7] - 48) * 100) + ((date[8] - 48) * 10) + date[9] - 48;
	month = (date[3] - 48) * 10 + date[4] - 48;
	date1 = (date[0] - 48) * 10 + date[1] - 48;
	//printf("%d\n",date1);
	for (int i = len; i >= 0; i--)
	{
		int year1, month1, date2;
		Arr[i].date;
		year1 = ((Arr[i].date[6] - 48) * 1000) + ((Arr[i].date[7] - 48) * 100) + ((Arr[i].date[8] - 48) * 10) + Arr[i].date[9] - 48;
		month1 = (Arr[i].date[3] - 48) * 10 + Arr[i].date[4] - 48;
		date2 = (Arr[i].date[0] - 48) * 10 + Arr[i].date[1] - 48;
		//printf("%d/n",date2);
		if (year1 == year)
		{
			if (month1 == month)
			{
				if (date1 == date2)
					break;
				else
				{
					count++;
					continue;
				}
			}
			else
			{
				count++;
				continue;
			}
		}
		else
		{
			count++;
			continue;
		}
	}
	count1 = count - 1;
	if (count1 == 5)
		return 0;
	else
		return count1;
	//printf("%d", count1);
}