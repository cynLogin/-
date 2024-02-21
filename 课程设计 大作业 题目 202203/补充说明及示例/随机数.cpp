#include <iostream>		//使用rand
#include <stdio.h>
#include<time.h>		//使用time
//#include <math.h>

int main()
{	int a[10],i;

    printf("time(0)=%d\n",time(0)); //time(0)表示当前时间
	srand( (int)time(0) );//以时间【(int)time(0)】作为产生随机数的因子。没有此句，每次产生的数都是一样的。

	for(i=0;i<10;i++)
	{	a[i]=rand();//产生0~32768间的随机数
		printf("%d\n",a[i]);
	}
}
//rand()会返回一随机数值，范围在0至RAND_MAX 间。
//在调用此函数产生随机数前，必须先利用srand()设好随机数种子。
//如果未设随机数种子，rand()在调用时会自动设随机数种子为1。



/*
时间戳是指格林威治时间1970年01月01日00时00分00秒(北京时间1970年01月01日08时00分00秒)起至现在的总秒数

在C语言中可以通过time()函数获取到当前的秒数 参数为0则函数返回值即为结果，若参数不为0则结果保存在参数中

#include <time.h>
time_t time( time_t *time );

[cpp] view plain copy
#include<time.h>  
#include<stdio.h>  
#include<windows.h>  
int main()  
{  
    int h=0,m=0,s=0;  
    int t=0;  
    while(1)  
    {  
        t=time(0);  //获取总秒数    
        s=t%60;  
        m=t%3600/60;    //1h= 3600s不足1h的除60即为分钟    
        h=(t%(24*3600)/3600+8)%24; //1天24h 得到当天小时数+8为东八区区时 避免出现大于24h的情况对24取余   
           
        printf("%02d:%02d:%02d\r",h,m,s); // %02d是将数字按宽度为2，采用右对齐方式输出，若数据位数不到2位，则左边补0 \r到当前行最左   
        //while(t==time(0));   
        Sleep(1000);//程序执行较快 对时间进行控制 执行挂起1s   
    }  
    return 0;  
 }   
 */
