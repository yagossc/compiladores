#include <stdio.h>
#include <stdlib.h>

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
	return 0;
}
