#include<iostream>
#include<stack>
#include<string>
#include<stdlib.h>
#include<sstream>
using namespace std;
int main()
{
	string s=" 3+2*2 ";
	stack<string> S;
	int size=s.length();
	string shu=""; 
	int i=0;
	for(int i=0;i<size;i++)
	{
		//cout<<"10";
		if(s[i]==' ')
			continue;
		else if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*')
		{
			string s1="";
			s1=s1+s[i];
			S.push(s1);
		}else{
			if(i<size-1&&s[i+1]>='0'&&s[i+1]<='9')	//当前是数，但是下一个仍然是数 
			{
				shu=shu+s[i];
			}else{		//当前是数，但是下一个不是数 
				shu=shu+s[i];
				if(S.empty())
				{
					S.push(shu);
					shu="";
					continue;
				}
				string c=S.top();
				
				if(c=="*"||c=="/")
				{
					
					int now=atoi(shu.c_str());
					S.pop();
					string cal=S.top();
					S.pop();
					if(c[0]=='*')
					{
						now=now*atoi(cal.c_str());
					}else{
						now=atoi(cal.c_str())/now;
					}
					
					stringstream stream;
					stream<< now;
					shu=stream.str();
				
				 } 
				S.push(shu);
				shu="";
			}
		}
	}
	//
	stack<string> S2;
	while(!S.empty())
	{
		
		S2.push(S.top());
		S.pop();
	}
	int now=0;
	shu=S2.top();
	now=atoi(shu.c_str());
	S2.pop();
	
	while(!S2.empty())
	{
		
		string c=S2.top();
		S2.pop();
		string next=S2.top();
		S2.pop();
		if(c[0]=='+')
		{	
			now=now+atoi(next.c_str());
		}else{
			now=now-atoi(next.c_str());
		}
	}
	cout<<now; 
	return 0;

}
