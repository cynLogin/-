#include <stdio.h>
#include <string.h>


void ReadStrUnit(char * str,char *temp_str,int idx,int len)  // ��ĸ���л�ȡ���Ӵ�������ȵ���ʱ�Ӵ�
{   int index = 0;
    for(index; index < len; index++)
    {	temp_str[index] = str[idx+index];
    }
    temp_str[index] = '\0';
}

int GetSubStrPos(char *str1,char *str2)
{	char temp_str[30];    // ��ʱ�Ӵ�
	int idx = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if( len1 < len2)
    {   printf("error 1 \n"); // �Ӵ���ĸ����
        return -1;
    }

    while(1)
    {   ReadStrUnit(str1,temp_str,idx,len2);    // ���ϻ�ȡ�Ĵ� ĸ���� idx λ�ô�������ʱ�Ӵ�
        if(strcmp(str2,temp_str)==0)
			break;      // ����ʱ�Ӵ����Ӵ�һ�£�����ѭ��
        idx++;                                  // �ı��ĸ����ȡ��ʱ�Ӵ���λ��
        if(idx>=len1)
			return -1;                 // �� idx �Ѿ�����ĸ�����ȣ�˵��ĸ�����������Ӵ�
    }

    return idx;    // �����Ӵ���һ���ַ���ĸ���е�λ��
}

int main()
{
    char *str1 = "abcdefghijk";
    char *str2 = "def";
    int i = 0;
    i = GetSubStrPos(str1,str2);
    if( i<0 )
    {   printf("not found\n");
    }
    else
    {   printf("i = %d\n",i);
    }

    return 0;
}
