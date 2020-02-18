#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	void wiggleSort(vector<int>& nums) {
		/*
		int * temp_nums = new int[nums.size()];
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			int a = 1;
		}
		*/
		int n = nums.size();
		auto midptr = nums.begin() + n / 2;
		nth_element(nums.begin(), midptr, nums.end());
		int mid = *midptr;
		#define A(x) nums[(1+2*(x))%(n|1)]
		int i = 0, j = 0, k = n - 1;
		while (j <= k)
		{
			if (A(j) > mid)
				swap(A(i++), A(j++));
			else if (A(j) < mid)
				swap(A(j), A(k--));
			else
				j++;
			
		}
	}
};
int Nums[] = { 1, 5, 1, 1, 6, 4 };
int main()
{
	vector<int> input;
	for (int i = 0; i < 6; i++)
		input.push_back(Nums[i]);
	Solution S;
	S.wiggleSort(input);
	for (int i = 0; i < 6; i++)
		cout << input[i] << " ";
	getchar();
	getchar();
	return 0;
}