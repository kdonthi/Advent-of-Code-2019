#include <stdio.h>

int main (int argc, char *argv[])
{
	int number;
	int array[137];
	int index;
	int i;
	int j;
	int k;
	
	index = 0;
	j = 0;
	k = 0;
	//puts comma seperated values into different array indices
	while (j < 100)
	{
		k = 0;
		while (k < 100)
		{
			index = 0;
			i = 0;
			while (1)
			{
				number = 0;
				while (argv[1][i] != ',' && argv[1][i] != '\0')
				{
					number = (number * 10) + (argv[1][i] - '0');
					i++;
				}
				array[index] = number;
				index++;
				if (argv[1][i] == '\0')
					break;
				i++;
			}
			array[1] = j;
			array[2] = k;
			i = 0;
			while (array[i] != 99)
			{
				if (array[i] == 1)
					array[array[i + 3]] = array[array[i + 1]] + array[array[i + 2]];
				else if (array[i] == 2)
					array[array[i + 3]] = array[array[i + 1]] * array[array[i + 2]];
				else
					return (1);
				printf("%i, %i, %i, %i, %i\n", i, array[i], array[i + 1], array[i + 2], array[i + 3]);
				i += 4;
			}
			if (array[0] == 19690720)
			{
				printf("Answer: %i, Noun: %i, Verb %i\n", 100 * array[1] + array[2], array[1], array[2]);
				return (0);
			}
			k++;
		}
		j++;
	}
}

