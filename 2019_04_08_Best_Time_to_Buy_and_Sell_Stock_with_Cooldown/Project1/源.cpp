#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
			return 0;
		int S0, S1, S2, S0_pre, S1_pre, S2_pre;
		S0_pre = 0;
		S1_pre = - prices[0];
		S2_pre = INT_MIN;
		for (int i = 1; i < prices.size(); i++)
		{
			S0 = max(S0_pre, S2_pre);
			S1 = max(S1_pre, S0_pre - prices[i]);
			S2 = S1_pre + prices[i];
			S0_pre = S0;
			S1_pre = S1;
			S2_pre = S2;
		}
		return max(S0, S2);
	}
};
int Prices[] = { 2,6,7,1,16,8,4,5,3,10,12,2,6,7,1,16,8,4,5,3,10,12 };
int main()
{
	vector<int> prices;
	for (int i = 0; i < 22; i++)
		prices.push_back(Prices[i]);
	Solution S;
	cout<<S.maxProfit(prices);
	system("pause");
}