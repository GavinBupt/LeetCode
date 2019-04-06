#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int MAX = 100000;
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		if (nums1.empty())	//�����һ������Ϊ��
		{
			if (n % 2 != 0)
				return 1.0*nums2[n / 2];
			return (nums2[n / 2] + nums2[n / 2 - 1]) / 2.0;
		}
		if (nums2.empty())	//�����һ������Ϊ��
		{
			if (m % 2 != 0)
				return 1.0*nums1[m / 2];
			return (nums1[m / 2] + nums1[m / 2 - 1]) / 2.0;
		}
		int mid_left = (m + n + 1) / 2;
		int mid_right = (m + n + 2) / 2;
		double a = findKth(nums1, 0, nums2, 0, mid_left);
		double b = findKth(nums1, 0, nums2, 0, mid_right);
		return ( a + b ) / 2;
	}
	double findKth(vector<int> &a, int a_left, vector<int> &b, int b_left, int k)
	{
		//cout << a_left << endl;
		for (int i = a_left; i < a.size(); i++)
			cout << a[i] << " ";
		cout << "|| ";
		for (int i = b_left; i < b.size(); i++)
			cout << b[i] << " ";
		cout << endl;
		if (a_left >= a.size())	//�������a����ָ�볬����a�����鳤�ȣ���ô��λ��������b����
			return b[b_left + k - 1];
		if (b_left >= b.size())	//�������b����ָ�볬����b�����鳤�ȣ���ô��λ��������a����
			return a[a_left + k - 1];
		if (k == 1) return min(a[a_left], b[b_left]);
		int mid_a = (a_left + k / 2 - 1 < a.size()) ? a[a_left + k / 2 - 1] : MAX; //��һ����Ϊ�������������ʼλ���Ǵ�0��ʼ��
		int mid_b = (b_left + k / 2 - 1 < b.size()) ? b[b_left + k / 2 - 1] : MAX;
		if (mid_a < mid_b)	//�������a����λ��С������b����λ������ô������̭a��ǰK/2����
		{
			return findKth(a, a_left + k / 2, b, b_left, k - k / 2);
		}
		else {
			return findKth(a, a_left, b, b_left + k / 2, k - k / 2);
		}
		//else
		//	return mid_a;
	}
};
int Nums1[] = { 1,2,3,4,5,6,7 };
int Nums2[] = { 1,2,3,4,5,6,7 };
int main()
{
	vector<int> nums1, nums2;
	for (int i = 0; i < 7; i++)
		nums1.push_back(Nums1[i]);
	for (int i = 0; i < 7; i++)
		nums2.push_back(Nums2[i]);
	Solution S;
	cout << S.findMedianSortedArrays(nums1, nums2);
	system("pause");
}