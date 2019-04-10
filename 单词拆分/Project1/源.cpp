#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		int n = s.size();
		int max_length = INT_MIN;
		for (auto w : wordDict)
			max_length = max(max_length,(int)w.length());
		vector<bool> dp(n + 1, false);
		dp[0] = true;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= max_length && i - j >= 0; ++j)
			{
				//substr(pos,len) 在字符位置pos开始，跨越len个字符
				if (dp[i - j] && count(wordDict.begin(), wordDict.end(), s.substr(i - j, j)))
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp[n];
	}
};
int main()
{
	vector<string> wordDict;
	string s = "applepenapple";
	wordDict.push_back("apple");
	wordDict.push_back("pen");
	Solution S;
	if (S.wordBreak(s, wordDict))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	system("pause");
	return 0;
}