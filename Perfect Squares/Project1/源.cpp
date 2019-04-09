#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int numSquares(int n) {		//��ƽ���Ͷ���Ľⷨ
		while (n % 4 == 0)
			n = n / 4;
		if (n % 8 == 7)
			return 4;
		for(int a = 0; a*a <= n; a++)
		{
			int b = sqrt(n - a*a);
			if (a*a + b*b == n)
				return !!a + !!b;
		}
		return 3;
	}
	int numSquares2(int n){
		vector<int> dp(n + 1, INT_MAX);	//��̬�滮�Ľⷨ
		dp[0] = 0;
		for(int i=0;i<=n;i++)
			for (int j = 1; i + j*j <= n; j++)
			{
				dp[i + j*j] = min(dp[i + j*j], dp[i] + 1);
			}
		return dp.back();
	}
};
int main()
{
	Solution S;
	cout << S.numSquares(13);
	cout << S.numSquares2(12);
	system("pause");
	return 0;
}