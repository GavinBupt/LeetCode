#include<iostream>
#include<vector>
using namespace std;
struct Node{
	int Max;
	int size;
};
int main()
{
	vector<int> nums;
	int k=3;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(-1);
	nums.push_back(-3);
	nums.push_back(5);
	nums.push_back(3);
	nums.push_back(6);
	nums.push_back(7);
	vector<int> MAX;
	Node node;
	node.Max=-100000;
	node.size=0;
	for(int i=0;i<k;i++)
	{
		if(nums[i]>node.Max)
		{
			node.Max=nums[i];
			node.size=1;
		}else if(nums[i]==node.Max)
		{
			node.size++;
		}
	}
	//cout<<node.Max<<endl;
	MAX.push_back(node.Max);
	for(int i=1;i+k<=nums.size();i++)
	{
		if(nums[i-1]==node.Max)
		{
			//cout<<"yes"<<endl;
			if(node.size==1)
			{
				node.Max=-100000;
				node.size=0;
				for(int j=i;j<i+k;j++)
				{
					if(nums[j]>node.Max)
					{
						node.Max=nums[j];
						node.size=1;
					}else if(nums[j]==node.Max)
					{
						node.size++;
					}
				}
				
			}else{
				node.size--;
			}
		}else{
			if(nums[i+k-1]>node.Max)
			{
				node.Max=nums[i+k-1];
				node.size=1;
			}else if(nums[i+k-1]==node.Max)
			{
				node.size++;
			}
		}
		MAX.push_back(node.Max);
	}
	for(int i=0;i<MAX.size();i++)
		cout<<MAX[i]<<" ";
	return 0;
	
}
