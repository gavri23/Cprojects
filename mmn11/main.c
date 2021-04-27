
# include <stdio.h>
# include <string.h>
# include <ctype.h>

char c,i = 0;
char string[101];
char decision[25] = "unclassified";

int f_sequence(char s[])
{
	printf("\n please insert letters\n    ");
	scanf("%s",&string);

	while (string[i+1] > 0)
	{
		switch (decision[9]) /*Each series type has an indicative signal*/
		{
		case 'i': /* = "unclassified" */
			{
				if (string[i] < string[i+1])
					strcpy(decision,"a really comes up");
				if (string[i] == string[i+1])
					strcpy(decision,"a comes up");
				if (string[i] > string[i+1])
					strcpy(decision,"a really goes down");
				break;
			}
		case 'c': /* = "a really comes up" */
			{
				if (string[i] == string[i+1])
					strcpy(decision,"a comes up");
				if (string[i] > string[i+1])
					strcpy(decision,"without a regular order");
				break;
			}
		case 'p': /* = "a comes up" */
			if (string[i] > string[i+1])
				strcpy(decision,"without a regular order");
			break;
		case 'g': /* = "a really goes down" */
			{
				if (string[i] == string[i+1])
					strcpy(decision,"a goes down");
				if (string[i] < string[i+1])
					strcpy(decision,"without a regular order");
				break;
			}
		case 'w': /* = "a goes down" */
			if (string[i] < string[i+1])
				strcpy(decision,"without a regular order");
			break;
		}
		i++;
	}
	printf("\n the string \"%s\" is %s series.\n",string,decision);
	return 0;
}

int main()
{
	f_sequence(string);	
	return 0;
}
