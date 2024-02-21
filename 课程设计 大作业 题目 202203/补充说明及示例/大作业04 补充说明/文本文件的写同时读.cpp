#include<stdlib.h>
#include<stdio.h>
void main()
{

	FILE *fp;
	char str[20]="123456";
	//if ( (fp=fopen("1.txt","w"))==NULL )	//只用w，表示只有写的功能，不能读数据。既要读又要写，需要w+。
	if ( (fp=fopen("1.txt","w+"))==NULL )
	{
		printf("无法打开文件\n");
		exit(0);
	}

	if( fputs(str,fp)!=0 )				//用来判断写是否成功
	{
		printf("不能写文件\n");
		exit(0);
	}

	rewind(fp);			//把光标返回文件头，才能读到前面写入文件的数据

	fgets(str,20,fp);

	puts(str);

	fclose(fp);
}
