#include <stdlib.h>
#include <stdio.h>

int main()
{	FILE *fp_write;   //文件指针用于写。
	int i, num[10]={10,20,30,40,50,60,70,80,255,256};

	//=====================================================================
	//打开文件1.txt，准备写
	if ( (fp_write = fopen("1.txt", "wb")) == NULL ) //b代码二进制。只用wb，表示只有写的功能，不能读数据。如果需要既读又写，就是wb+。
	{	printf("无法打开文件\n");
		exit(0);
	}

	//把数组num写入文件
	for( i=0; i<=9; i++)
	{
		fwrite(&num[i],sizeof(num[i]),1,fp_write);		//二进制写入
		//fprintf(fp_write,"%d ",num[i]);				//文本写入
	}

	fclose(fp_write);  	//文件打开fopen，最后必须关闭fclose。
}
