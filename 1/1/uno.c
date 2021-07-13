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
		num += ((array[i]/3) - 2);
		i++;
	}
	printf("%i\n", num);
}
	

