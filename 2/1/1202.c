#include <stdio.h>

int main (int argc, char *argv[])
{
	int number;
	int array[137];
	int index;
	int i;
	
	index = 0;
	i = 0;
	//puts comma seperated values into different array indices
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
	
	i = 0;
	while (array[i] != 99)
	{
		if (array[i] == 1)
			array[array[i + 3]] = array[array[i + 1]] + array[array[i + 2]];
		else if (array[i] == 2)
			array[array[i + 3]] = array[array[i + 1]] * array[array[i + 2]];
		else
			return (1);
		i += 4;
	}
	printf("%i\n", array[0]);
}

