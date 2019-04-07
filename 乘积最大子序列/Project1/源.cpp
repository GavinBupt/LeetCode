#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProduct(vector<int>& nums) {
		int now_max = nums[0];
		int Pos_max = nums[0];//最大的正数
		int Neg_max = nums[0];//最小的复数（绝对值最大）
		for (int i = 1; i < nums.size(); i++)
		{
			int Temp_Pos_max = Pos_max;
			int Temp_Neg_max = Neg_max;
			Pos_max = max(nums[i], max(Temp_Pos_max*nums[i], Neg_max*nums[i]));
			Neg_max = min(nums[i], min(Temp_Pos_max*nums[i], Neg_max*nums[i]));
			now_max = max(Pos_max, now_max);
		}
		return now_max;
	}
};
int Nums[] = { 2, 3,-1,4 };
int main()
{
	vector<int> nums;
	for (int i = 0; i < 4; i++)
		nums.push_back(Nums[i]);
	Solution S;
	cout<<S.maxProduct(nums);
	system("pause");
	return 0;
}