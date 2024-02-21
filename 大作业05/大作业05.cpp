#include<iostream>
#include<cstring>
using namespace std;
bool jud(char st,char ex)
{
	if((st=='+'||st=='-')&&(ex=='*'||ex=='/')) return 0;
	else return 1;
}
int main()
{
	char expmid[50];
	char expbeh[50];
	char stack[50];
	float stackn[50];
	float temp=0;
	cout<<"请输入表达式(按回车结束)："<<endl;
	gets(expmid);
	int j=-1;
	int k=-1;
	for(int i=0;expmid[i]!='\0';i++)
	{
		//cout<<expbeh<<endl; 
		if(expmid[i]>='0'&&expmid[i]<='9')
		{
			expbeh[j+1]=expmid[i];
			j++;
		}
		if(expmid[i]=='+'||expmid[i]=='-'||expmid[i]=='*'||expmid[i]=='/')
		{
			expbeh[j+1]=' ';
			j++;
			if(k==-1)
			{
				
				stack[k+1]=expmid[i];
				k++;
			
			} 
			else if(jud(stack[k],expmid[i]))
			{
				while(jud(stack[k],expmid[i]))
				{
					expbeh[j+1]=stack[k];
					j++;
					expbeh[j+1]=' ';
					j++;
					k--;
					if(k==-1) break;
				}
				stack[k+1]=expmid[i];
				k++;
			} 
			else
			{
				stack[k+1]=expmid[i];
				k++;
			}
		}
	}
	while(k!=-1)
	{
		expbeh[j+1]=' ';
		j++;
		expbeh[j+1]=stack[k];
		j++;
		k--;
	}
	expbeh[j+1]='\0';
	//cout<<expbeh<<endl;
	bool flag=0;
	k=-1;
	for(int i=0;expbeh[i]!='\0';i++)
	{
		if(expbeh[i]>='0'&&expbeh[i]<='9')
		{
			flag=1;
			temp*=10;
			temp+=(expbeh[i]-48);
		}
		if(expbeh[i]==' ')
		{
			if(flag==1)
			{
				flag=0;
				stackn[k+1]=temp;
				k++;
				temp=0;
			}			
		}
		//cout<<stackn[k]<<endl;
		if(expbeh[i]=='+'||expbeh[i]=='-'||expbeh[i]=='*'||expbeh[i]=='/')
		{
			if(expbeh[i]=='+')
			{
				stackn[k-1]=stackn[k-1]+stackn[k];
				//cout<<stackn[k-1]<<endl;
				k--;
			}
			if(expbeh[i]=='-')
			{
				stackn[k-1]=stackn[k-1]-stackn[k];
				k--;
			}
			if(expbeh[i]=='*')
			{
				stackn[k-1]=stackn[k-1]*stackn[k];
				k--;
			}
			if(expbeh[i]=='/')
			{
				stackn[k-1]= (stackn[k-1])/stackn[k];
				k--;
			}
			
		}
	}
	cout<<"表达式结果是："<<endl;
	cout<<stackn[k]<<endl;
	return 0;
}
