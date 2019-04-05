#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> nums;
	
	nums.push_back(3);
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(2);
	
	//nums.push_back(1);
	//nums.push_back(1);
	int size=nums.size();
	int left=1;//最小的数应该为1
	int right=size;//最大的数应该为size 
	while(left<=right)
	{
		int middle=left+(right-left)/2;
		int small=0;
		for(int i=0;i<size;i++)
		{
			if(nums[i]<=middle&&nums[i]>=left)
			{
				small++;
			}
		}
		if(left==right)
		{
			if(small>1)
			{
				//cout<<left;
				break;
				//return left;
			}else{
				break;
			}
		}
		if(small>middle-left+1)	//说明右半部分的数多
		{
			right=middle;
		}	
		else
			left=middle+1;
			
	}
	cout<<left;
	return 0;
 } 
