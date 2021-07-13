#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int number)
{
	if (number >= 10)
		ft_putnbr(number / 10);
	ft_putchar((number % 10) + '0');
}

int atoi(char *string)
{
	int i;
	int number;

	i = 0;
	number = 0;
	while (string[i] != '\0')
	{
		number = (number * 10) + (string[i] - '0');
		i++;
	}
	return (number);
}

int pwten (int power)
{
	int i;
	int number;

	i = 0;
	number = 1;
	while (i < power)
	{
		number *= 10;
		i++;
	}
	return (number);
}


int main (int argc, char *argv[])
{
	int num1;
	int num2;
	int counter;
	int i;
	int adjacentdigits;
	int increase;
	int numb1;
	int matches;
	int match;
	int leastnumberofmatches;

	if (argc != 3)
	{
		ft_putchar('\n');
		return (1);
	}
	numb1 = atoi(argv[1]);
	num2 = atoi(argv[2]);
	counter = 0;
	
	while (numb1 <= num2)
	{
		num1 = numb1;	
		i = 5;
		adjacentdigits = 0;
		increase = 1;
		matches = 0;
		leastnumberofmatches = 7;
		match = 10;
		while (i >= 0)
		{
			if (match == (num1 / pwten(i)))
				matches++;
			if ((match != (num1 / pwten(i)) || i == 0) && matches >= 1)
				leastnumberofmatches = (matches < leastnumberofmatches ? matches : leastnumberofmatches);
			if (match != (num1 / pwten(i)))
				matches = 0;
			if (((num1 / pwten(i)) > ((num1 - ((num1 / pwten(i)) * pwten(i))) / pwten(i - 1))) && i >= 1)
			{
				increase = 0;
				break;
			}
			match = num1 / pwten(i);
			num1 = (num1 - ((num1 / pwten(i)) * pwten(i)));
			i--;
		}
		if (increase == 1 && leastnumberofmatches == 1)
			counter++;
		numb1++;
	}
	ft_putnbr(counter);
	ft_putchar('\n');
}
		

		
	

