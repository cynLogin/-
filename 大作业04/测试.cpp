#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	//char name[16];
	//scanf("%s",name);
	//printf("%s",name);
	cout<<"1 "<<"2333 "<<"3 "<<"4 "<<endl;
	cout<<"1\t"<<"2333\t"<<"3\t"<<"4\t"<<endl;
	string n,m;
	cin>>n>>m;
	cout<<n.compare(m);
	if(!n.compare(m)) cout<<"**************";
//	cout<<n.size();
	return 0;
}
