#include <stdio.h>


int atoi(char *string)
{
	int number;
	int i;
	
	number = 0;
	i = 0;
	while (string[i] != '\0')
	{
		number = (number * 10) + (string[i] - '0');
		i++;
	}
	return (number);
}

int totalfuel(int module)
{
	int fuel;

	if (module <= 5)
		return (0);
	else
	{
		fuel = (module/3) - 2;
		return (fuel + totalfuel(fuel));
	}
}
		
		
int main(int argc, char *argv[])
{
	int i;
	int array[101];
	int index;
	int number;
	int num;

	i = 1; 
	while (i < argc)
	{
		array[i - 1] = atoi(argv[i]);
		i++;
	}

	num = 0;
	i = 0;
	while (i < argc - 1)
	{
		num += totalfuel(array[i]);
		i++;
	}
	printf("%i\n", num);
}
	

