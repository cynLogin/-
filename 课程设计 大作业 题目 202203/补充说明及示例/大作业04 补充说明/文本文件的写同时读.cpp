#include<stdlib.h>
#include<stdio.h>
void main()
{

	FILE *fp;
	char str[20]="123456";
	//if ( (fp=fopen("1.txt","w"))==NULL )	//ֻ��w����ʾֻ��д�Ĺ��ܣ����ܶ����ݡ���Ҫ����Ҫд����Ҫw+��
	if ( (fp=fopen("1.txt","w+"))==NULL )
	{
		printf("�޷����ļ�\n");
		exit(0);
	}

	if( fputs(str,fp)!=0 )				//�����ж�д�Ƿ�ɹ�
	{
		printf("����д�ļ�\n");
		exit(0);
	}

	rewind(fp);			//�ѹ�귵���ļ�ͷ�����ܶ���ǰ��д���ļ�������

	fgets(str,20,fp);

	puts(str);

	fclose(fp);
}
