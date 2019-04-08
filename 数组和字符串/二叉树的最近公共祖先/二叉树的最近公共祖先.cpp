#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int main()
{
	TreeNode *root;
	TreeNode *p;
	TreeNode *q;
	TreeNode l1(3);
	TreeNode l2(5);
	TreeNode l3(1);
	TreeNode l4(6);
	TreeNode l5(2);
	TreeNode l6(0);
	TreeNode l7(8);
	TreeNode l8(7);
	TreeNode l9(4);
	l1.left=&l2;
	l1.right=&l3;
	l2.left=&l4;
	l2.right=&l5;
	l3.left=&l6;
	l3.right=&l7;
	l4.left=NULL;
	l4.right=NULL;
	l5.left=&l8;
	l5.right=&l9;
	l6.left=NULL;
	l6.right=NULL;
	l7.left=NULL;
	l7.right=NULL;
	l8.left=NULL;
	l8.right=NULL;
	l9.left=NULL;
	l9.right=NULL;
	p=&l2;
	q=&l9;
	root=&l1;
	map<int,TreeNode*> M;
	queue<TreeNode*> Q;
	Q.push(root);
	int num=1;
	int p1,q1;
	while(!Q.empty())
	{
		TreeNode *now;
		TreeNode *left;
		TreeNode *right;
		now=Q.front();
		Q.pop();
		if(now!=NULL)
		{
			//cout<<now->val;
			if(now==p)
			{
				p1=num;
			}
			if(now==q)
			{
				q1=num;
			}
			left=now->left;
			right=now->right;
			M[num++]=now;
			Q.push(left);
			Q.push(right);
		}else{
			M[num++]=now;
		}
	}
	while(p1!=q1)
	{
		if(p1<q1)
			q1=q1/2;
		else if(p1>q1)
			p1=p1/2;
	}
	cout<<(M[p1]->val);
	return 0;
 } 
