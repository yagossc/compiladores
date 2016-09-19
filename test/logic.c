#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int logic = 17;
	int ilogic = 0;

	if(logic)
		printf("Not logic.\n");
	if(!ilogic)
		printf("Not Ilogic.\n");
	switch(logic)
	{
		case 17:
			printf("WORKS!.\n");
			break;
		default:
			break;
	}

	char *str = "zzzzzzzzzzz";

	int k = 0;
	for(int i = 0; i < strlen(str); i++)
		k += (int)str[i];
	printf("%d\n", k);

	int h = 0;
	for(int i = 0; i < strlen(str) || i < 8; i++)
	{
		h = (13*h + (int)str[i])%70;
	}
	printf("%d\n", h);
	return 0;
}
