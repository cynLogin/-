#include <stdlib.h>
#include <stdio.h>

int main()
{	//功能：
	//把str1、str2两个字符串写1.txt
	//读取2.txt所有内容，并显示

	FILE *fp_read, *fp_write;   //两个文件指针分别指向两个文件：一个用于读、一个用于写。
	char str1[400] = "123456123456\n";
	char str2[400] = "abcdefg\n";
	int i, num[10]={10,20,30,40,50,60,70,80,90,100};

	//=====================================================================
	//打开文件1.txt，准备写
	if ( (fp_write = fopen("1.txt", "w")) == NULL ) //只用w，表示只有写的功能，不能读数据。如果需要既读又写，就是w+。
	{	printf("无法打开文件\n");
		exit(0);
	}

	//把字符串str1写入文件
	fputs(str1, fp_write);

	//把字符串str2写入文件
	fputs(str2, fp_write);

	//把数组num写入文件
	for( i=0; i<=9; i++)
	{
		fprintf(fp_write,"%d ",num[i]);				
	}

	fclose(fp_write);  	//文件打开fopen，最后必须关闭fclose。

	//=====================================================================
	//打开文件2.txt，准备读
	if ( (fp_read = fopen("2.txt", "r")) == NULL )
	{	printf("无法打开文件\n");
		exit(0);
	}

	//读字符串
	while ( !feof(fp_read) )   //表示文件指针fp_write未指向文件结尾
	{	fgets(str1, 400, fp_read);		//一行一行的读，最多读400个字节
		puts(str1);
	}

	fclose(fp_read);	//文件打开fopen，最后必须关闭fclose。
}
