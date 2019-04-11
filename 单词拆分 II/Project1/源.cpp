#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
class Solution {
public:
	struct Node {
		int now;
		string str;
	};
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		int n = s.length();
		int max_length = INT_MIN;
		vector<string> re;
		
		for (auto p : wordDict)
		{
			max_length = max(max_length,(int) p.length());
		}
		vector<vector<int>> result(n + 1);
		vector<bool> dp(n + 1, false);
		dp[0] = true;
		
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= max_length&&i >= j; j++)
			{
				if (dp[i - j] && count(wordDict.begin(), wordDict.end(), s.substr(i - j, j)))
				{
					result[i].push_back(i - j);
					dp[i] = true;
				}
			}
		}
		if (dp[n] == false)
			return re;
		queue<Node> N;

		for (int i =0; i < result[n].size(); i++)
		{
			Node node;
			node.now = result[n][i];
			if (node.now == 0)
			{
				node.str = s.substr(node.now, n - node.now);
				re.push_back(node.str);
			}
			else
			{
				node.str = s.substr(node.now, n - node.now);
				
				N.push(node);
			}
		}
		while (!N.empty())
		{
			Node n = N.front();
			N.pop();
			for (int i = 0; i < result[n.now].size(); i++)
			{
				Node node;
				node.now = result[n.now][i];
				if (node.now == 0)
				{
					node.str = s.substr(node.now, n.now - node.now) + " " + n.str;
					re.push_back(node.str);
				}
				else
				{
					node.str = s.substr(node.now, n.now - node.now) + " " + n.str;
					N.push(node);
				}
					
			}
		}
		return re;
	}
};
int main()
{
	vector<string> wordDict;
	wordDict.push_back("apple");
	wordDict.push_back("pen");
	wordDict.push_back("applepen");
	wordDict.push_back("pine");
	wordDict.push_back("pineapple");
	wordDict.push_back("pineapplepenapple");
	string s = "pineapplepenapple";
	Solution S;
	vector<string> result = S.wordBreak(s, wordDict);
	for (auto p : result)
		cout << p << endl;
	system("pause");
	return 0;
}