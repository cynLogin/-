#include <stdlib.h>
#include <stdio.h>

int main()
{	//���ܣ�
	//��str1��str2�����ַ���д1.txt
	//��ȡ2.txt�������ݣ�����ʾ

	FILE *fp_read, *fp_write;   //�����ļ�ָ��ֱ�ָ�������ļ���һ�����ڶ���һ������д��
	char str1[400] = "123456123456\n";
	char str2[400] = "abcdefg\n";
	int i, num[10]={10,20,30,40,50,60,70,80,90,100};

	//=====================================================================
	//���ļ�1.txt��׼��д
	if ( (fp_write = fopen("1.txt", "w")) == NULL ) //ֻ��w����ʾֻ��д�Ĺ��ܣ����ܶ����ݡ������Ҫ�ȶ���д������w+��
	{	printf("�޷����ļ�\n");
		exit(0);
	}

	//���ַ���str1д���ļ�
	fputs(str1, fp_write);

	//���ַ���str2д���ļ�
	fputs(str2, fp_write);

	//������numд���ļ�
	for( i=0; i<=9; i++)
	{
		fprintf(fp_write,"%d ",num[i]);				
	}

	fclose(fp_write);  	//�ļ���fopen��������ر�fclose��

	//=====================================================================
	//���ļ�2.txt��׼����
	if ( (fp_read = fopen("2.txt", "r")) == NULL )
	{	printf("�޷����ļ�\n");
		exit(0);
	}

	//���ַ���
	while ( !feof(fp_read) )   //��ʾ�ļ�ָ��fp_writeδָ���ļ���β
	{	fgets(str1, 400, fp_read);		//һ��һ�еĶ�������400���ֽ�
		puts(str1);
	}

	fclose(fp_read);	//�ļ���fopen��������ر�fclose��
}
