#include<iostream>
#include<cstdio>
#define SPn 10
using namespace std;
int m=5093;
struct stru_sp{
	string s;
	int mark;
}sp[15]={ {},{"李宁双肩包",8200},
{"新款毛巾",678},
{"金吉星软包抽纸",1040},
{"2018洗车大毛巾",1250},
{"小米 移动电源2",7900},
{"不锈钢保温杯",8690},
{"滋润型护肤脂",710},
{"真好芦荟胶",1900},
{"维达 手帕纸",2090},
{"佳洁士巨人专用",395}};
struct ANSWER{
	int sum;
	int gs[15];
}ans[7]={{0,{0}}};
int jf_min=0;
int jf_min_tag=1;
ANSWER temp;
void collect()
{
	temp.sum=0;
	for(int i=1;i<=SPn;i++)
	{
		temp.sum+=sp[i].mark*temp.gs[i];
	}
	//cout<<temp.sum<<endl;
	//cout<<temp.sum<<endl;
	if(temp.sum<=m)
	{
		
		if(temp.sum>jf_min)
		{
			//cout<<jf_min_tag<<endl;
			//cout<<temp.sum<<endl;
			//cout<<jf_min<<endl;
			ans[jf_min_tag]=temp;
			int min_temp=ans[1].sum;
			jf_min_tag=1;
			for(int i=1;i<=5;i++)
			{
				if(ans[i].sum<min_temp)
				{
					min_temp=ans[i].sum;
					jf_min_tag=i;
				}
			}
			jf_min=min_temp;
		}
	}
}
void deal(int tag)
{
	//cout<<tag<<endl;
	if(tag<=SPn)
	{
		for(int i=0;i<=m/sp[tag].mark;i++)
		{
			temp.gs[tag]=i;
			deal(tag+1);
		}
	}
	else
	{
		collect();
	}
	return;
}
int main()
{
	int tag=1;
	deal(tag);
	ANSWER tt; 
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5-i;j++)
		{
			if(ans[j].sum<ans[j+1].sum)
			{
				tt=ans[j+1];
				ans[j+1]=ans[j];
				ans[j]=tt; 
			}
		} 
	}
	cout<<"用户积分:"<<m<<endl;
	cout<<"=================================="<<endl;
	for(int i=1;i<=5;i++)
	{
		cout<<"---------------第"<<i<<"种选择--------------"<<endl;
		cout<<"消耗积分:"<<ans[i].sum<<endl<<endl;
		cout<<"商品名称\t需积分\t换购数"<<endl;
		cout<<"--------------------------------------"<<endl;
		for(int j=1;j<=10;j++)
		{
			cout<<sp[j].s<<"\t"<<sp[j].mark<<"\t"<<ans[i].gs[j]<<endl;
		}
		cout<<"==================================="<<endl<<endl;
	}
	return 0;
}
