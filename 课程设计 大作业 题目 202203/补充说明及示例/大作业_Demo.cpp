/*
灵活运用：
1、PRINTF大法
2、注释大法
*/

//大作业一：设计整数处理程序
#include <stdio.h>
int Jie_Cheng(int n)	//函数名称要好理解
{	//函数功能：求n!
	//参数：需要求的n
	//返回值：阶乘结果
	if (n == 1)
		return 1;
	else
		return fun1(n - 1) * n;
}

int f2(int m, int sum)	//名称不好理解
{	int i, j, k;
	for (i = 0; i <= 10; i++)
	{	for (j = 0; j <= 10; j++)
		{
		}
	}
}



int main()
{	int m, n, x;
	m = 2;
	n = 3;
	x = m + 3;		//变量名命名也要好读，此行改成sum=m+n，更好一点。
}
