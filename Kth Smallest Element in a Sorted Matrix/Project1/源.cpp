#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
	struct Node {
		int x, y, num;
		Node() {};
		Node(int i, int j, int k) :x(i), y(j), num(k) {};
	};
	friend bool operator<(Node a, Node b)
	{
		return a.num > b.num;
	}

	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int i = 0, j = 0;
		int Nan = -100000;
		Node node(i, j, matrix[i][j]);
		matrix[i][j] = Nan;
		priority_queue<Node> Q;
		Q.push(node);
		Node tmp;
		for (int p = 1; p <= k; p++)
		{
			tmp = Q.top();
			Q.pop();
			int tmp_x = tmp.x + 1, tmp_y = tmp.y + 1;
			if (tmp_x < matrix.size() && matrix[tmp_x][tmp.y] != Nan)
			{
				Q.push(Node(tmp_x, tmp.y, matrix[tmp_x][tmp.y]));
				matrix[tmp_x][tmp.y] = Nan;
			}
			if (tmp_y < matrix.size() && matrix[tmp.x][tmp_y] != Nan)
			{
				Q.push(Node(tmp.x, tmp_y, matrix[tmp.x][tmp_y]));
				matrix[tmp.x][tmp_y] = Nan;
			}
				
		}
		return tmp.num;
	}
	
};
int Matrix[][3] = {
	1, 3, 5,
	6, 7, 12,
	11, 14, 14
};
int K = 6;
int main()
{
	vector<vector<int>> matrix;
	for (int i = 0; i < 3; i++)
	{
		vector<int> v;
		for (int j = 0; j < 3; j++)
			v.push_back(Matrix[i][j]);
		matrix.push_back(v);
		v.clear();
	}
	Solution S;
	
	cout << S.kthSmallest(matrix, K);
	system("pause");
}