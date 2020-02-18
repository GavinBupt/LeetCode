#include<iostream>
#include<string>
#include<map>
#include<deque>
#include<vector>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<=0 || t.length()<=0 || t.length()>s.length())
        	return "";
        int left=0,right=0,min=s.length()+1,head=0;
        string ans=s+"1";
        //bool isVisit[t.length()];
        //memset(isVisit, false, sizeof(bool) * t.length());
        if(t.length()==1 && s[0]==t[0])
        	return t;
        	
		vector<int> record;  
        vector<int> notFound(128,0);
        int count=0;
        for(int i=0;i<t.size();i++)
        {
        	notFound[t[i]]++;
        	count++;
		}
		
		while(right<s.length())
		{
			if(notFound[s[right++]]-->0)
			{
				count--;
				record.push_back(right-1);
			 } 
			while(count==0)
			{
				int length=right-left;
				if(length<min)
				{
					min=length;
					head=left;
				}
				if(notFound[s[left++]]++ == 0)
				{
					count++;
				}
			}
		}
		
		if(min>s.length())
	    	return "";
	    else 
	    	return s.substr(head, min);
    }	
    
};
int main()
{
	Solution S;
	string s="bba";
	string t="ab";
	cout<<S.minWindow(s,t)<<endl;
	return 0;
 } 
 /*之前的垃圾代码
 for(int i=0;i<t.length();i++)
        {
        	it_notFound = notFound.find(t[i]);
        	if(it_notFound==notFound.end())
        	{
        		notFound.insert(pair<char,int>(t[i],1));
			}else{
				it_notFound->second++;
			}
		}
		for(auto &i:notFound)
		{
			threshold.insert(pair<char,int>(i.first,i.second));
			hasFound.insert(pair<char,int>(i.first,0));
		}
 
 
 if(notFound.size()!=0)
			{
				for(;right<s.length();right++)
		        {
		        	if(t.find(s[right])!=t.npos)
		        	{
		        		it_notFound=notFound.find(s[right]);
		        		if(it_notFound!=notFound.end())
			        	{
							if(--it_notFound->second==0)
								notFound.erase(it_notFound);
						}
						
						it_hasFound=hasFound.find(s[right]);
	        			
	        			it_hasFound->second++;
	        				//cout<<s[right]<<" "<<it_hasFound->second<<endl;
							
						
						record.insert(pair<int,char>(right,s[right])); 
					}
					
					//如果子串包含t 
					if(notFound.size()==0)
					{
						string result;
						it_record=record.begin();
						left=it_record->first;
						for(int i=left;i<=right;i++)
							result+=s[i];
						//cout<<result<<endl;
						if(result.length()<ans.length())
							ans=result;
						
						break;
					}
				}
				if(right>=s.length())
					break;
			}
			
			//for(auto &i:record)
			//{
			//	cout<<"("<<i.first<<" "<<i.second<<") ";
			//}
			//cout<<endl;
			//cout<<"right:"<<right<<endl;
			while(!record.empty())
			{
				//it_record=record.begin();
				//left=it_record->first;
				//cout<<"left:"<<left<<endl;
				it_hasFound=hasFound.find(it_record->second);
				it_threshold=threshold.find(it_record->second);
				//cout<<"it_record->second:"<<it_record->second<<endl;
				//cout<<"it_hasFound->second:"<<it_hasFound->second<<endl;
				it_hasFound->second--;
				
				if(it_hasFound->second>=it_threshold->second)
				{
					string result;
					record.erase(it_record);
					it_record=record.begin();
					left=it_record->first;
					for(int i=left;i<=right;i++)
						result+=s[i];
					
					if(result.length()<ans.length())
						ans=result;
					
				}else{
					notFound.insert(pair<char,int>(it_hasFound->first,1));
					record.erase(it_record);
					
					right++;
					break;
				}
			}
			*/ 
