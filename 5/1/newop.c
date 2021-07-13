#include <stdio.h>

int main (int argc, char *argv[])
{
	int number;
	int array[680];
	int index;
	int i;
	int neg;
	
	index = 0;
	i = 0;
	//puts comma seperated values into different array indices
	while (1)
	{
		number = 0;
		neg = 1;
		while (argv[1][i] != ',' && argv[1][i] != '\0')
		{
			if (argv[1][i] == '-')
				neg = -1;
			else
				number = (number * 10) + (argv[1][i] - '0');
			i++;
		}
		array[index] = neg * number;
		index++;
		if (argv[1][i] == '\0')
			break;
		i++;
	}
	
	i = 0;
	int firstnumber;
	int secondnumber;
	int instruction;
	int integer;
	while (array[i] != 99)
	{
		firstnumber = array[i] / 1000;
		secondnumber = (array[i] - (firstnumber * 1000)) / 100;
		instruction = array[i] - (firstnumber * 1000) - (secondnumber * 100);
		if (instruction == 1)
		{
			array[array[i + 3]] = array[(secondnumber == 0 ? array[i + 1] : i + 1)] + array[(firstnumber == 0 ? array[i + 2] : i + 2)];
			i += 4;
		}
		else if (instruction == 2)
		{
			array[array[i + 3]] = array[(secondnumber == 0 ? array[i + 1] : i + 1)] * array[(firstnumber == 0 ? array[i + 2] : i + 2)];
			i += 4;
		}
		else if (instruction == 3)
		{
			scanf("%i", &integer);
			array[array[i + 1]] = integer;
			i += 2;
		}
		else if (instruction == 4)
		{
			printf("%i\n", array[(secondnumber == 0 ? array[i + 1] : i + 1)]);
			i += 2;
		}
		else
		{
			printf("Weird Instruction: %i", instruction);
			return (0);
		}
	}
}

