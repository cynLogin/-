#include <stdlib.h>
#include <stdio.h>

int main()
{	FILE *fp_write;   //�ļ�ָ������д��
	int i, num[10]={10,20,30,40,50,60,70,80,255,256};

	//=====================================================================
	//���ļ�1.txt��׼��д
	if ( (fp_write = fopen("1.txt", "wb")) == NULL ) //b��������ơ�ֻ��wb����ʾֻ��д�Ĺ��ܣ����ܶ����ݡ������Ҫ�ȶ���д������wb+��
	{	printf("�޷����ļ�\n");
		exit(0);
	}

	//������numд���ļ�
	for( i=0; i<=9; i++)
	{
		fwrite(&num[i],sizeof(num[i]),1,fp_write);		//������д��
		//fprintf(fp_write,"%d ",num[i]);				//�ı�д��
	}

	fclose(fp_write);  	//�ļ���fopen��������ر�fclose��
}
