#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;
class Solution {
public:
	void DFS(string s, char ch, int last)
	{
		for (int i = 0, cnt = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == ')')
			{
				if (s[i] == ch)
					cnt++;
				else
					cnt--;
			}
			if (cnt <= 0)
				continue;
			for (int j = last; j <= i; j++)
			{
				if (s[j] == ch && (j == last || s[j - 1] != ch) )
				{
					//cout << "j: " << j << " s.substr(j+1): " << s.substr(j + 1) << endl;
					//substr(x)如果没有指定length参数，则子字符串将延续到字符串的结尾。
					DFS(s.substr(0, j) + s.substr(j + 1), ch, j); 
				}
			}
			return;
		}
		reverse(s.begin(), s.end());
		if (ch == ')')
			return DFS(s, '(', 0);
		res.push_back(s);
	}
	vector<string> removeInvalidParentheses(string s) {
		DFS(s, ')', 0);
		return res;
	}
private:
	vector<string> res;
};
int main()
{
	//string s = "(a)())()";
	string s = "((a)))";
	Solution S;
	vector<string> ans = S.removeInvalidParentheses(s);
	for (auto p : ans)
	{
		cout << p << endl;
	}
	system("pause");
	return 0;
}