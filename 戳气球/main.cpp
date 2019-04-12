#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int length=nums.size();
	nums.insert(nums.begin(),1);
	nums.push_back(1);
	vector< vector<int> > dp(length+2,vector<int> (length+2,0));
	for(int len=1;len<=length;len++)
	  for(int i=1;i<=length-len+1;i++)
	  {
	    int j=i+len-1;
	    for(int k=i;k<=j;k++)
	    {
	      dp[i][j]=max(dp[i][j],nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
	    }
	  }
	  return dp[1][length];
    }
};
int Nums[]={3,1,5,8};
int main()
{
     vector<int> nums;
     for(int i=0;i<4;i++)
     nums.push_back(Nums[i]);
     Solution S;
     cout<<"hello"<<endl;
     std::cout<<S.maxCoins(nums)<<endl;
     //getchar();
     //getchar();
     //system("pause");
     return 0;

}
