#include<iostream>
#include<string>
#include<vector>


using namespace std;
#define MAX 10000000

vector<int> find_char(string str,char c)
{
	vector<int> v;
	for(int i=0;i<str.size();i++)
	{
		if(str[i]==c)
			v.push_back(i); 
	}
	return v;
}
bool find_nums(vector<int> nums,int k)
{
	for(int i=0;i<nums.size();i++)
	{
		if(nums[i]==k)
			return false;
	}
	return true;
}
int main()
{
	string s;
	string t;
	//="adobecodebanc";
	//="abcda";

	s="BbabBbbaab";
	t="Baa";
	//t="baba";
		
	//s="acbbaca";
	//t="aba";
	bool flag=false;
	string ans="";
	vector< vector<int> > Vec;
	Vec.resize(t.size());
	//string tmpstring="";
	for(int i=0;i<t.size();i++)
	{
		//if(tmpstring.find(t[i])!=-1)
		//	continue;
		//tmpstring=tmpstring+t[i];	
		Vec[i]=find_char(s,t[i]);
		if(Vec.size()==0)
		{
			flag=true;
			break;
		}
	}
	//cout<<tmpstring;
	int Min_differ=100000000;
	vector<int> tmp;
	string result;
	for(int i=0;i<Vec[0].size();i++)
	{
		cout<<"i:"<<Vec[0][i]<<endl;
		int left,right;
		tmp.push_back(Vec[0][i]);
		left=Vec[0][i];
		right=Vec[0][i];
		for(int j=1;j<Vec.size();j++)
		{
			int differ=MAX;
			int differ_tmp=0;
			int k=0;
			char ctmp='c';
			for(;k<Vec[j].size();k++)
			{
				if(!find_nums(tmp,Vec[j][k]))	//如果有重复的数值，则退出 
				{
					if(ctmp=='c')
						ctmp='p';
					continue; 
				}
				if(Vec[j][k]>left&&Vec[j][k]<right)
				{
					differ_tmp=Vec[j][k];
					ctmp='q';
					break;
				}else{
					if(Vec[j][k]<left)
					{
						if(left-Vec[j][k]<differ)
						{
							ctmp='L';
							//left=Vec[j][k];
							differ=left-Vec[j][k];
							differ_tmp=Vec[j][k];
						}
						
					}else if(Vec[j][k]>right){	//t[j][k]>right
						if(Vec[j][k]-right<differ)
						{
							ctmp='r';
							//right=Vec[j][k];
							differ=Vec[j][k]-right;
							differ_tmp=Vec[j][k];
						}
					}
				}
			}
			//cout<<ctmp<<endl;
			if(ctmp=='L')
				left=differ_tmp;
			else if(ctmp=='r')
				right=differ_tmp;
			cout<<"differ_tmp:"<<differ_tmp<<endl;
			cout<<"left:"<<left<<" right:"<<right<<endl;
			if(ctmp!='p')
				tmp.push_back(differ_tmp);
		}
		//cout<<tmp.size();
		//for(int i=0;i<tmp.size();i++)
		//	cout<<tmp[i]<<" ";
		if(right-left<Min_differ&&tmp.size()==t.length())
		{
			//cout<<"left:"<<left<<" right:"<<right<<endl;
			ans=s.substr(left,right-left+1);
			//cout<<result<<endl;
			Min_differ=right-left+1;
		}
		tmp.clear();
	}
	
	cout<<ans;
	return 0;
}
