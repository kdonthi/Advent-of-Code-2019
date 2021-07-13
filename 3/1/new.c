#include <stdio.h>
#include <stdlib.h>
// gives us number starting from first digit of number
int ft_atoi(char *string, int index, char seperator)
{
	int number;

	number = 0;
	while (string[index] != seperator && string[index] != ',')
	{
		number = (number * 10) + (string[index] - '0');
		index++;
	}
	return (number);
}

void addtonumber(char *argv, int *index, char seperator, int *direction)
{
	*direction += ft_atoi(argv, (*index + 1), seperator);
	while (argv[*index] != ',' && argv[*index] != seperator)
		(*index)++;
	if (argv[*index] == ',')
		(*index)++;
}		

int largestdirection(char *argv, int *index, char seperator)
{
	int *up;
	int *down;
	int *left;
	int *right;
	int a;
	int b;
	int c;
	int d;
	
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	up = &a;
	down = &b;
	left = &c;
	right = &d;
	while (argv[*index] != seperator)
	{
		if (argv[*index] == 'U')
			addtonumber(argv, index, seperator, up);
		if (argv[*index] == 'D')
			addtonumber(argv, index, seperator, down);
		if (argv[*index] == 'L')
			addtonumber(argv, index, seperator, left);
		if (argv[*index] == 'R')
			addtonumber(argv, index, seperator, right);
	}
	(*index)++;
	*left = (*left > *right ? *left : *right);
	*up = (*up > *down ? *up : *down);
	*up = (*up > *left ? *up : *left);
	return (*up);
}

void visualizearray(int gridlen, int **array)
{
	int i;
	int j;

	while (i < gridlen)
	{
		j = 0;
		while (j < gridlen)
		{
			printf("%i", array[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

int abs (int i)
{
	if (i >= 0)
		return (i);
	else
		return (i * -1);
}

int abssum (int x, int y)
{
	return (abs(x) + abs(y)) ;
}

int main (int argc, char *argv[])
{
	int ld;
	int *index;
	char seperator;
	int a;
	int ldir1;
	int ldir2;
	int gridlen;
	int **array;

	a = 0;
	index = &a;
	seperator = 'e';
	ldir1 = largestdirection(argv[1], index, seperator);
	printf("Index: %i", *index);
	ldir2 = largestdirection(argv[1], index, seperator);
	ldir1 = (ldir1 > ldir2 ? ldir1 : ldir2);
	printf("Index: %i, Largest direction: %i", *index, ldir1);

	//Making array that can handle largest direction of the two wires
	gridlen = (ldir1 * 2) + 5;
	array = (int**) malloc(sizeof(char*) * gridlen);
	int i;
	i = 0;
	while (i < gridlen)
		array[i++] = malloc(sizeof(char) * gridlen);
	/*while (i < gridlen)
	{	
		j = 0;
		while (j < gridlen)
		{
			array[i][j] = 0;
			j++;
		}
		i++;
	}*/
	//printf("Array[0][0]: %i, Array[gridlen - 1][gridlen - 1]: %i", array[0][0], array[gridlen - 1][gridlen - 1]);

	//Insert into the the array a 1 whereever the first wire goes
	int x;
	int y;
	int n;
	int o;
	int counter;
	x = gridlen/2;
	y = gridlen/2;
	i = 0;
	counter = 0;
	while (argv[1][i] != seperator)
	{
		n = 0;
		if (argv[1][i] == 'U')
		{
			while (n++ <= ft_atoi(argv[1], i + 1, seperator))
				array[x][y++] = counter++;
			y -= 1;
			counter -= 1;
			while (argv[1][i] != ',' && argv[1][i] != seperator)
				i++;
			if (argv[1][i] == ',')
				i++;
		}
		else if (argv[1][i] == 'D')
		{
			while (n++ <= ft_atoi(argv[1], i + 1, seperator))
				array[x][y--] = counter++;
			y += 1;
			counter -= 1;
			while (argv[1][i] != ',' && argv[1][i] != seperator)
				i++;
			if (argv[1][i] == ',')
				i++;
		}
		else if (argv[1][i] == 'R')
		{
			while (n++ <= ft_atoi(argv[1], i + 1, seperator))
				array[x++][y] = counter++;
			x -= 1;
			counter -= 1;
			while (argv[1][i] != ',' && argv[1][i] != seperator)
				i++;
			if (argv[1][i] == ',')
				i++;
		}
		else if (argv[1][i] == 'L')
		{
			while (n++ <= ft_atoi(argv[1], i + 1, seperator))
				array[x--][y] = counter++;
			x += 1;
			counter -= 1;
			while (argv[1][i] != ',' && argv[1][i] != seperator)
				i++;
			if (argv[1][i] == ',')
				i++;
		}
		else
			return (1);
	}
	i++;
	int distance = 900000;
	int xi = gridlen / 2;
	x = gridlen / 2;
	int yi = gridlen / 2;
	y = gridlen / 2;
	counter = 0;
	while (argv[1][i] != seperator)
	{
		n = 0;
		if (argv[1][i] == 'U')
		{
			while (n++ <= ft_atoi(argv[1], i + 1, seperator))
			{
				if (array[x][y] > 0 && x != xi && y != yi)
					distance = (abssum(array[x][y], counter) < distance ? abssum(array[x][y], counter) : distance); 
				array[x][y++] = counter--;
			}
			y -= 1;
			counter++;
			while (argv[1][i] != ',' && argv[1][i] != seperator)
				i++;
			if (argv[1][i] == ',')
				i++;
		}
		else if (argv[1][i] == 'D')
		{
			while (n++ <= ft_atoi(argv[1], i + 1, seperator))
			{
				if (array[x][y] == 1 && x != xi && y != yi)
					distance = (abssum(array[x][y], counter) < distance ? abssum(array[x][y], counter) : distance);
				array[x][y--] = counter--;
			}
			y += 1;
			counter++;
			while (argv[1][i] != ',' && argv[1][i] != seperator)
				i++;
			if (argv[1][i] == ',')
				i++;
		}
		else if (argv[1][i] == 'R')
		{
			while (n++ <= ft_atoi(argv[1], i + 1, seperator))
			{
				if (array[x][y] == 1 && x != xi && y != yi)
					distance = (abssum(array[x][y], counter) < distance ? abssum(array[x][y], counter) : distance);
				array[x++][y] = counter--;;
			}
			x -= 1;
			counter++;
			while (argv[1][i] != ',' && argv[1][i] != seperator)
				i++;
			if (argv[1][i] == ',')
				i++;
		}
		else if (argv[1][i] == 'L')
		{
			while (n++ <= ft_atoi(argv[1], i + 1, seperator))
			{
				if (array[x][y] == 1 && x != xi && y != yi)
					distance = (abssum(array[x][y], counter) < distance ? abssum(array[x][y], counter) : distance);;
				array[x--][y] = counter--;
			}
			x += 1;
			counter++;
			while (argv[1][i] != ',' && argv[1][i] != seperator)
				i++;
			if (argv[1][i] == ',')
				i++;
		}
		else
			return (1);
	}
	printf("\n%i\n", distance);
}
			


