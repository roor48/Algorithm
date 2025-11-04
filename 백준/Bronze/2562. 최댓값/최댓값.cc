#include <stdio.h>
main()
{
	int a,b,c,d=1;
	for(c=0; d<=9; d++)
	{
		scanf("%d",&a);
		if(a>c) {c=a; b=d;}
	}
	printf("%d\n%d",c,b);
}