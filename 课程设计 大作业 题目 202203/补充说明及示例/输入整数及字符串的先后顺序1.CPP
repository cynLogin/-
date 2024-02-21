//准备输入n=10,str1="abc"，然后显示.
#include <stdio.h>
void main()
{	char str1[20];
	int n,x,i;
	printf("n=");
	scanf("%d",&n);
	printf("str1=");
	gets(str1);			//scanf("%d",&x);
	//for(i=0;i<9;i++)
	//	printf("%d ",str1[10]);
	
	/*
	在上面的scanf中，输入了10和回车，回车不是数，scanf取走10，而把回车留在内存中。
	紧跟的语句：
	1、如果是gets，因为回车可以表示空字符串，所有不再提示输入，直接把这个剩下的回车给了str1。str1显示就为空。
	2、如果是scanf("%d",&x)，回车显然不是数，所以VC会继续要求输入一个数。
	*/
	printf("n=%d\n",n);
	printf("str1=%s\n",str1);

}

/*

//解决方法一：再加一条gets(str1)，为的是把剩下的回车读走
#include <stdio.h>
void main()
{	char str1[20];
	int n;
	printf("n=");
	scanf("%d",&n);
	printf("str1=");
	gets(str1);	
	gets(str1);	
	
	printf("n=%d\n",n);
	printf("str1=%s\n",str1);

}
*/


/*
//解决方法二：先读字符串，再读整数或浮点数
#include <stdio.h>
void main()
{	char str1[20];
	int n;
	printf("str1=");
	gets(str1);	
	printf("n=");
	scanf("%d",&n);
	
	printf("n=%d\n",n);
	printf("str1=%s\n",str1);

}
*/