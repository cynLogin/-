#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void chara(char t[])
{
	printf("字母出现的频度：\n");
	int cnt[26]={0};
	int i=0;
	char ch;
	while(t[i]!='\0')
	{
		if(t[i]>=65&&t[i]<=90)
		{
			cnt[t[i]-65]++;
		}
		else if(t[i]>=97&&t[i]<=122)
		{
			cnt[t[i]-97]++;
		}
		i++;
	}
	for(int k=1;k<=26;k++)
	{
		ch=k+64;
		printf("%c:%d次  ",ch,cnt[k-1]);
		if(k%3==0) printf("\n");
	}
	printf("\n");
}
void word(char t[])
{
	int cnt=0;
	bool flag=0;
	int i=0;
	while(t[i]!='\0')
	{
		if(t[i]>=65&&t[i]<=90||t[i]>=97&&t[i]<=122)
		{
			if(flag==0)
			{
				flag=1;
				cnt++;
			}
		}
		else
		{
			if(flag==1) flag=0;
		}
		i++;
	}
	printf("共有%d个单词\n",cnt);
}
void longest_word(char t[])
{
	bool flag=0;
	int max1=0;
	int cnt=0;
	char dcmax[500];
	char dc[500];
	int i=0,k=0;
	while(t[i]!='\0')
	{
		if(t[i]>=65&&t[i]<=90||t[i]>=97&&t[i]<=122)
		{
			if(flag==0)
			{
				flag=1;
				cnt++;
				dc[k]=t[i];
				k++;
			}
			else if(flag==1)
			{
				cnt++;
				dc[k]=t[i];
				k++;
			}
		}
		else
		{
			if(flag==1) 
			{
				flag=0;
				//k++;
				dc[k]='\0';
				if(cnt>max1)
				{
					max1=cnt;
					strcpy(dcmax,dc);
				}
				k=0;
				cnt=0;
			}
		}
		i++;
		
	}
	printf("最长的单词是：%s  长度为：%d \n",dcmax,max1);
}
void num(char t[])
{
	int a[500];
	int flag=0;
	int t1;
	int i=0,k=0,cnt=0;
	while(t[i]!='\0')
	{
		if(t[i]>=48&&t[i]<=57)
		{
			if(flag==0)
			{
				flag=1;
				t1=t[i]-48;
				cnt++;
			}
			else
			{
				t1*=10;
				t1+=(t[i]-48);
			}
		}
		else
		{
			if(flag==1)
			{
				flag=0;
				a[k]=t1;
				k++;
				
			}
		}
		i++;
	}
	printf("整数有：");
	for(int j=0;j<cnt;j++)
	{
		printf("%d ",a[j]);
	}
	printf("\n");
}
int main()
{
	FILE * fp;
	char temp[1000];
	int i=0;
	if((fp=fopen("D:\\陈俞宁\\作业\\C程序设计\\大作业03\\1.txt","r"))==NULL)
	{
		printf("无法打开此文件\n");
		exit(0);
	} 
	while(!feof(fp))
	{
	 	temp[i]=fgetc(fp);
	 	i++;
	}
	chara(temp);
	word(temp); 
	longest_word(temp);
	num(temp);
	fclose(fp);
	return 0;
}
