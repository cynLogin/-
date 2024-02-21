//大家分别使用getchar、getch、getche、scanf等4个函数，看看有什么区别
#include <stdio.h>
#include <conio.h>		//getch、getche用到此头文件
int main()
{
	char c1,c2;  
	//scanf("%c",&c1);
	//scanf("%c",&c2);
	//c1=getchar();
	//c2=getchar();
	//c1=getch();
	//c2=getch();
	c1=getche();
	//c2=getche();
	printf("[==========================c1=%c]\n",c1);
	printf("[==========================c2=%c]\n",c2);
	printf("[==========================c1=%d]\n",c1);
	printf("[==========================c2=%d]\n",c2);
	return 0;
}
