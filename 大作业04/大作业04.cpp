#include<cstdio>
#include<iostream>
#include<cstring> 
#include<conio.h>
using namespace std;
int sum=3;
struct Student{
	string num;
	string name;
	bool sex;
	int mark[3];
}person[50]={{},{"22011001","����",1,{95,43,77}},{"22011005","����",0,{66,88,93}},{"22011008","����",1,{75,36,55}}};
void print(Student t,int cnt)
{
	cout<<"���:"<<cnt<<" "<<"ѧ��:"<<t.num<<" "<<"����:"<<t.name<<" ";
	cout<<"�Ա�:";
	if(t.sex==1) cout<<"�� ";
	else cout<<"Ů ";
	for(int i=0;i<=2;i++)
	{
		if(i==0) cout<<"����:";
		if(i==1) cout<<"��ѧ:";
		if(i==2) cout<<"����:";
		cout<<t.mark[i]<<" ";
	}
	cout<<endl;
}
void search(string target)
{
	int tag=0;
	bool flag=0;
	for(int i=1;i<=sum;i++)
	{
		tag=0;
		for(int j=0;j<target.size();j+=2)
		{
			for(int k=0;k<person[i].name.size();k+=2)
			{
				if(target[j]==person[i].name[k]&&target[j+1]==person[i].name[k+1])
				{
					tag++;
					break;
				}
			}
		}
		if(tag==target.size()/2) {
			print(person[i],i);
			flag=1;
		}
	}
	if(flag==0) cout<<"����ʧ��"<<endl;
}
void fail()
{
	bool flag=0;
	int line;
	cout<<"�����뼰���ߣ�";
	cin>>line;
	for(int i=1;i<=sum;i++)
	{
		for(int j=0;j<=2;j++)
		{
			if(person[i].mark[j]<line) {
				print(person[i],i);
				flag=1;
				break;
			}
		}
	}
	if(!flag) cout<<"�޲�����ͬѧ"<<endl; 
}
void sortn(int kcxh)
{
	Student t[sum];
	Student temp;
	for(int i=1;i<=sum;i++)
	{
		t[i-1]=person[i];
	}
	for(int i=0;i<sum-1;i++)
	{
		for(int j=0;j<sum-1-i;j++)
		{
			if(t[j].mark[kcxh]<t[j+1].mark[kcxh])
			{
				temp=t[j];
				t[j]=t[j+1];
				t[j+1]=temp;
			}
		}
	}
	for(int i=0;i<sum;i++)
	{	
		print(t[i],i+1);
	}
}
void newn()
{
	Student t;
	char c;
	cout<<"������ѧ�ţ�"<<endl;
	cin>>t.num;
	cout<<"������������"<<endl;
	cin>>t.name;
	cout<<"�������Ա���ţ�0��Ů ��1���У�"<<endl;
	c=getche();
	t.sex=c-48;
	cout<<endl;
	cout<<"��ֱ��������ġ���ѧ������ɼ����Կո���"<<endl;
	cin>>t.mark[0]>>t.mark[1]>>t.mark[2];
	person[sum]=t;
	cout<<"��ͬѧ��Ϣ����ɹ�"<<endl; 
}
void deleten(int xh)
{
	for(int i=xh;i<=sum;i++)
	{
		person[i]=person[i+1];
	}
	//cout<<"ɾ���ɹ�"<<endl;
}
void change(int xh)
{
	int xgxh;
	char c;
	cout<<"�������޸�������ţ�"<<endl;
	cout<<"(1)ѧ��\n(2)����\n(3)�Ա�\n(4)���ĳɼ�\n(5)��ѧ�ɼ�\n(6)����ɼ�\n";
	c=getche();
	xgxh=c-48;
	cout<<endl;
	switch  (xgxh)
	{
		case 1:{
			cout<<"��������ѧ�ţ�" ;
			cin>>person[xh].num;
			break;
		}
		case 2:{
			cout<<"��������������";
			cin>>person[xh].name; 
			break;
		}
		case 3:{
			cout<<"���������Ա�0��Ů ��1���У�";
			cin>>person[xh].sex; 
			break;
		}
		case 4:{
			cout<<"��������ĺ�ɼ���";
			cin>>person[xh].mark[0];
			break;
		}
		case 5:{
			cout<<"��������ĺ�ɼ���";
			cin>>person[xh].mark[1];
			break;
		}
		case 6:{
			cout<<"��������ĺ�ɼ���";
			cin>>person[xh].mark[2];
			break;
		}
		default:
			break;
	}
	cout<<"�޸ĳɹ�"<<endl; 
}
int main()
{
	char control;
	bool f=1;
	cout<<"�������������ɶ�Ӧ����"<<endl; 
	cout<<"1.��ʾ����ͬѧ����Ϣ"<<endl;
	cout<<"2.����ָ����������Ϣ"<<endl;
	cout<<"3.��ʾ�в�����ͬѧ����Ϣ"<<endl;
	cout<<"4.��ָ���γ��������"<<endl;
	cout<<"5.����һ����ͬѧ"<<endl;
	cout<<"6.ɾ��ָ����������Ϣ"<<endl;
	cout<<"7.�޸�ָ����������Ϣ"<<endl;
	cout<<"0.�˳�"<<endl;
	while(f)
	{
		cout<<"��������Ҫִ�е����֣�";
		control=getche();
		cout<<endl;
		switch (control)
		{
			case '1':{
				for(int i=1;i<=sum;i++)
				{
					print(person[i],i);
				}
				break;
			}
			case '2':{
				string t;
				cout<<"������Ҫ���ҵ�������";
				cin>>t;
				search(t);
				break;
			}
			case '3':{
				fail();
				break;
			}
			case '4':{
				int kcxh;
				char c;
				cout<<"������Ҫ����(�Ӹߵ���)�Ŀγ�(1.���� 2.��ѧ 3.����)��";
				c=getche();
				cout<<endl;
				kcxh=c-49;
				sortn(kcxh);
				break;
			}
			case '5':{
				sum++;
				newn();
				break;
			}
			case '6':{
				string temp1;
				cout<<"������������";
				cin>>temp1; 
				bool flag1=1;
				for(int i=1;i<=sum;i++)
				{
					if(!temp1.compare(person[i].name)) {
						sum--;
						flag1=0;
						deleten(i);
						cout<<"ɾ���ɹ�"<<endl;
						break;
					}
				}
				if(flag1==1) cout<<"δ�ҵ�������"<<endl;
				flag1=1;
				break;
			}
			case '7':{
				string temp2;
				cout<<"������������";
				cin>>temp2; 
				bool flag2=1;
				for(int i=1;i<=sum;i++)
				{
					if(!temp2.compare(person[i].name)) {
						change(i);
						flag2=0;
						break;
					}
				}
				if(flag2==1) cout<<"δ�ҵ�������"<<endl;
				flag2=1;
				break;
			}
			case '0':{
				f=0;
				break;
			}
			default:
				{
					cout<<"��������"<<endl;
					break; 
				}
				

		}
		cout<<endl;
	}
	return 0;
}
