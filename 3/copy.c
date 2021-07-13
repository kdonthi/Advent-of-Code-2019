#include <stdio.h>

int atoi(char *string, int index, char seperator)
{
	int number;

	index++; //to start at number
	number = 0;
	while (string[index] != ',' && string[index] != seperator && string[index] != '\0')
	{
		number = (number * 10) + (string[index] - '0');
		index++;
	}
	return (number);
}

int largestdirection(char *string, int index, char seperator)
{	
	int up;
	int down;
	int left;
	int right;
	int largest;

	up = 0;
	down = 0;
	left = 0;
	right = 0;
	while (string[index] != seperator && string[index] != '\0') 
	{
		if (string[index] == 'R')
		{
			right += atoi(string, index, seperator);
			while (string[index] != ',' && string[index] != seperator && string[index] != '\0')
				index++;
			if (string[index] == ',')
				index++;
		}
		if (string[index] == 'L')
                {
                        left += atoi(string, index, seperator);
                        while (string[index] != ',' && string[index] != seperator && string[index] != '\0')
                                index++;
			if (string[index] == ',')
                        	index++;
                }
		if (string[index] == 'U')
                {
                        up += atoi(string, index, seperator);
                        while (string[index] != ',' && string[index] != seperator && string[index] != '\0')
                                index++;
                        if (string[index] == ',')
				index++;
                }
		if (string[index] == 'D')
                {
                        down += atoi(string, index, seperator);
                        while (string[index] != ',' && string[index] != seperator && string[index] != '\0')
                                index++;
                        if (string[index] == ',') 
				index++;
                }
	}
	
	left = (left > right ? left : right);
	up = (up > down ? up : down);
	largest = (up > left ? up : left);
	return (largest);
}

int main (int argc, char *argv[])
{	
	int i;
	int directionw1;
	int directionw2;
	int gridlen;
	char seperator;
	int distance;
	int j;
	int k;
	int end;

	seperator = 'e';
	i = 0;
	directionw1 = largestdirection(argv[1], i, seperator);
	while (argv[1][i] != seperator)
		i++;
	i++;
	directionw2 = largestdirection(argv[1], i, seperator);
	gridlen = (directionw1 > directionw2 ? directionw1 : directionw2);
	int array[gridlen + 10][gridlen + 10];
	int start;
	
	start = (((gridlen * 2) + 5) / 2);
	j = 0;
	while (j < ((gridlen * 2) + 5)) //initializing array to 0
	{
		k = 0;
		while (k < ((gridlen * 2) + 5))
		{
			array[j][k] = 0;
			k++;
		}
		j++;
	}	
	j = 0;
	k = 0;
	i = 0;
	while (argv[1][i] != seperator) //changing values of array to 1 when lines go through
	{
		if (argv[1][i] == 'U')
		{
			end = k + atoi(argv[1], i, seperator);
			while (k <= end)
			{
				array[start + j][start + k] = 1;
				k++;
			}
			while (argv[1][i] != seperator && argv[1][i] != ',')
				i++;
			if (argv[1][i] == ',')
				i++;
		}
		if (argv[1][i] == 'D')
		{
			end = k - atoi(argv[1], i, seperator);
			while (k >= end)
			{
				array[start + j][start + k] = 1;
				k--;
			}
			while (argv[1][i] != seperator && argv[1][i] != ',')
				i++;
			if (argv[1][i] == ',')
				i++;
		}
		if (argv[1][i] == 'R')
		{
			end = j + atoi(argv[1], i, seperator);
			while (j <= end)
			{
				array[start + j][start + k] = 1;
				j++;
			}
			while (argv[1][i] != seperator && argv[1][i] != ',')
				i++;
			if (argv[1][i] == ',')
				i++;
		}
		if (argv[1][i] == 'L')
		{
			end = j - atoi(argv[1], i, seperator);
			while (j >= end)
			{
				array[start + j][start + k] = 1;
				j--;
			}
			while (argv[1][i] != seperator && argv[1][i] != ',')
				i++;
			if (argv[1][i] == ',')
				i++;
		}
	}
	i++; //to move past the newline
	distance = 90000;
	j = 0;
	k = 0;
	while (argv[1][i] != seperator) //changing values of array to 1 when lines go through
	{
		if (argv[1][i] == 'U')
		{
			end = k + atoi(argv[1], i, seperator);
			while (k <= end)
			{
				if (array[start + j][start + k] == 1)
					distance = ((k + j) < distance ? (k + j) : distance);	
				array[start + j][start + k] = 1;
				k++;
			}
			while (argv[1][i] != seperator && argv[1][i] != ',')
				i++;
			if (argv[1][i] == ',')
				i++;
		}
		if (argv[1][i] == 'D')
		{
			end = k - atoi(argv[1], i, seperator);
			while (k >= end)
			{
				if (array[start + j][start + k] == 1)
					distance = ((k + j) < distance ? (k + j) : distance);
				array[start + j][start + k] = 1;
				k--;
			}
			while (argv[1][i] != seperator && argv[1][i] != ',')
				i++;
			if (argv[1][i] == ',')
				i++;
		}
		if (argv[1][i] == 'R')
		{
			end = j + atoi(argv[1], i, seperator);
			while (j <= end)
			{
				if (array[start + j][start + k] == 1)
					distance = ((k + j) < distance ? (k + j) : distance);
				array[start + j][start + k] = 1;
				j++;
			}
			while (argv[1][i] != seperator && argv[1][i] != ',')
				i++;
			if (argv[1][i] == ',')
				i++;
		}
		if (argv[1][i] == 'L')
		{
			end = j - atoi(argv[1], i, seperator);
			while (j >= end)
			{
				if (array[start + j][start + k] == 1)
					distance = ((k + j) < distance ? (k + j) : distance);
				array[start + j][start + k] = 1;
				j--;
			}
			while (argv[1][i] != seperator && argv[1][i] != ',')
				i++;
			if (argv[1][i] == ',')
				i++;
		}
	}
	printf("%i\n", distance);
}
		
		
		
		
		
