#include <stdio.h>
#include <stdlib.h>

void goingback(int *orbits, char *array, char *ftl);

char *firstthreeletters(char *array, int index)
{
	int i;
	char *firstthreeletters;
	
	i = 0;
	firstthreeletters = (char*)malloc(sizeof(char) * 4);
	while (array[index] != ')')
		firstthreeletters[i++] = array[index++];
	firstthreeletters[i] = '\0';
	return (firstthreeletters);
}
char *lastthreeletters(char *array, int index)
{
	int i;
	char *lastthreeletters;

	i = 0;
	lastthreeletters = (char*)malloc(sizeof(char) * 4);
	while (array[index] != ')')
		index++;
	index++;
	while (array[index] != ' ' && array[index] != '\0')
		lastthreeletters[i++] = array[index++];
	lastthreeletters[i] = '\0';
	return (lastthreeletters);
}	

int ft_strcmp(char *comp, char *with, int windex)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (comp[i] == with[windex] && counter < 3)
	{
		i++;
		windex++;
		counter++;
	}
	if (comp[i] == '\0')
		return (0);
	return ((unsigned char)comp[i] - (unsigned char)with[windex]);
}

void furtherorbits(int *orbits, char *array, char *ftl, int distance)
{
	int i;

	i = 0;
	while (array[i] != '\0')
	{
		if (ft_strcmp(ftl, array, i) == 0)
		{
			if (ft_strcmp("SAN", lastthreeletters(array, i), 0) == 0)
			{
				printf("%i\n", distance + *orbits);
				exit (0);
			}
			furtherorbits(orbits, array, lastthreeletters(array, i), distance + 1);
		}
		while (array[i] != ' ' && array[i] != '\0')
			i++;
		if (array[i] == ' ')
			i++;
	}
	if (distance == 0) //to make sure this only happens to the head of the tree we are going to traverse
		goingback(orbits, array, ftl);
}

void goingback(int *orbits, char *array, char *ftl)
{
	int i;

	i = 0;
	while (array[i] != '\0')
	{
		if (ft_strcmp(lastthreeletters(array, i), ftl, 0) == 0)
		{
			(*orbits)++;
			furtherorbits(orbits, array, firstthreeletters(array, i), 0);
		}
		while (array[i] != ' ' && array[i] != '\0')
			i++;
		if (array[i] == ' ')
			i++;
	}
}
int main (int argc, char *argv[])
{
	int i;
	int *orbits;
	int a;
	char *ftl;
	char *ltl;

	i = 0;
	a = 0;
	orbits = &a;
	while (argv[1][i] != '\0')
	{
		ltl = lastthreeletters(argv[1], i);
		if (ft_strcmp("YOU",ltl, 0) == 0)
		{
			ftl = firstthreeletters(argv[1], i);
			furtherorbits(orbits, argv[1], ftl, 0); //do we need the last param?
			break;
		}
		while (argv[1][i] != '\0' && argv[1][i] != ' ')
			i++;
		if (argv[1][i] == ' ')
			i++;
	}
}

		
		
			

