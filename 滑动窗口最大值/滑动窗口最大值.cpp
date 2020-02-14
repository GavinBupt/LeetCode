#include<iostream>
#include<deque>
#include<vector>
using namespace std;

class Solution
{
	public:
	vector<int> maxSlidingWindow(vector<int>&nums,int k)
	{
		deque< pair<int,int> > ksize;
		vector<int> result;
		if(k<=0||k>nums.size())
		{
			return result;
		}else if(k==1)
		{
			for(int i=0;i<nums.size();i++)
				result.push_back(nums[i]);
		}else if(k==nums.size())
		{
			int max=nums[0];
			for(int i=1;i<nums.size();i++)
				if(nums[i]>max)
					max=nums[i];
			result.push_back(max);
		}else{
			ksize.push_back(make_pair(0,nums[0]));
			for(int i=1;i<k;i++)
			{
				for(int p=ksize.size()-1;p>=0;p--)
				{
					if(nums[i]>ksize[p].second)
					{
						ksize.pop_back();
					}
				}	
				ksize.push_back(make_pair(i,nums[i]));
			}
			
			/*
			for(auto &item : ksize)
			 {
			 	cout<<item.first<<" "<<item.second<<";";
			 }
			cout<<endl;
			*/
			result.push_back(ksize[0].second);
		
			for(int i=1;i<=nums.size()-k;i++)
			{
				if(ksize[0].first<i)
					ksize.pop_front();
				if(nums[i+k-1]>ksize[0].second)
				{
					ksize.clear();
					ksize.push_back(make_pair(i+k-1,nums[i+k-1]));
				 } else 
				 {
				 	int p=ksize.size()-1;
				 	for(;p>=0;p--)
					{
						if(nums[i+k-1]>ksize[p].second)
						{
							ksize.pop_back();
						}
					}	
					ksize.push_back(make_pair(i+k-1,nums[i+k-1]));
				 }
				 
				result.push_back(ksize[0].second);
			}				
		}
		
		return result;
	 } 
};
int main()
{
	Solution S;
	int num[8]={1,3,-1,-3,5,3,6,7};
	vector<int> nums(num,num+8);
	vector<int> result = S.maxSlidingWindow(nums,3);
	cout<<"!!"<<endl;
	for(auto &item : result)
		cout<<item<<endl;
	return 0;
 } 
