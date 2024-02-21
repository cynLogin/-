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
}person[50]={{},{"22011001","张三",1,{95,43,77}},{"22011005","李四",0,{66,88,93}},{"22011008","王五",1,{75,36,55}}};
void print(Student t,int cnt)
{
	cout<<"序号:"<<cnt<<" "<<"学号:"<<t.num<<" "<<"姓名:"<<t.name<<" ";
	cout<<"性别:";
	if(t.sex==1) cout<<"男 ";
	else cout<<"女 ";
	for(int i=0;i<=2;i++)
	{
		if(i==0) cout<<"语文:";
		if(i==1) cout<<"数学:";
		if(i==2) cout<<"外语:";
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
	if(flag==0) cout<<"搜索失败"<<endl;
}
void fail()
{
	bool flag=0;
	int line;
	cout<<"请输入及格线：";
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
	if(!flag) cout<<"无不及格同学"<<endl; 
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
	cout<<"请输入学号："<<endl;
	cin>>t.num;
	cout<<"请输入姓名："<<endl;
	cin>>t.name;
	cout<<"请输入性别序号（0）女 （1）男："<<endl;
	c=getche();
	t.sex=c-48;
	cout<<endl;
	cout<<"请分别输入语文、数学、外语成绩，以空格间隔"<<endl;
	cin>>t.mark[0]>>t.mark[1]>>t.mark[2];
	person[sum]=t;
	cout<<"新同学信息增添成功"<<endl; 
}
void deleten(int xh)
{
	for(int i=xh;i<=sum;i++)
	{
		person[i]=person[i+1];
	}
	//cout<<"删除成功"<<endl;
}
void change(int xh)
{
	int xgxh;
	char c;
	cout<<"请输入修改内容序号："<<endl;
	cout<<"(1)学号\n(2)姓名\n(3)性别\n(4)语文成绩\n(5)数学成绩\n(6)外语成绩\n";
	c=getche();
	xgxh=c-48;
	cout<<endl;
	switch  (xgxh)
	{
		case 1:{
			cout<<"请输入新学号：" ;
			cin>>person[xh].num;
			break;
		}
		case 2:{
			cout<<"请输入新姓名：";
			cin>>person[xh].name; 
			break;
		}
		case 3:{
			cout<<"请输入新性别（0）女 （1）男：";
			cin>>person[xh].sex; 
			break;
		}
		case 4:{
			cout<<"请输入更改后成绩：";
			cin>>person[xh].mark[0];
			break;
		}
		case 5:{
			cout<<"请输入更改后成绩：";
			cin>>person[xh].mark[1];
			break;
		}
		case 6:{
			cout<<"请输入更改后成绩：";
			cin>>person[xh].mark[2];
			break;
		}
		default:
			break;
	}
	cout<<"修改成功"<<endl; 
}
int main()
{
	char control;
	bool f=1;
	cout<<"请输入序号以完成对应功能"<<endl; 
	cout<<"1.显示所有同学的信息"<<endl;
	cout<<"2.查找指定姓名的信息"<<endl;
	cout<<"3.显示有不及格同学的信息"<<endl;
	cout<<"4.按指定课程排序输出"<<endl;
	cout<<"5.增加一个新同学"<<endl;
	cout<<"6.删除指定姓名的信息"<<endl;
	cout<<"7.修改指定姓名的信息"<<endl;
	cout<<"0.退出"<<endl;
	while(f)
	{
		cout<<"请输入您要执行的数字：";
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
				cout<<"请输入要查找的姓名：";
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
				cout<<"请输入要排序(从高到低)的课程(1.语文 2.数学 3.外语)：";
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
				cout<<"请输入姓名：";
				cin>>temp1; 
				bool flag1=1;
				for(int i=1;i<=sum;i++)
				{
					if(!temp1.compare(person[i].name)) {
						sum--;
						flag1=0;
						deleten(i);
						cout<<"删除成功"<<endl;
						break;
					}
				}
				if(flag1==1) cout<<"未找到该姓名"<<endl;
				flag1=1;
				break;
			}
			case '7':{
				string temp2;
				cout<<"请输入姓名：";
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
				if(flag2==1) cout<<"未找到该姓名"<<endl;
				flag2=1;
				break;
			}
			case '0':{
				f=0;
				break;
			}
			default:
				{
					cout<<"输入有误"<<endl;
					break; 
				}
				

		}
		cout<<endl;
	}
	return 0;
}
