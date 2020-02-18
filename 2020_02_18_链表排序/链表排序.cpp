#include<vector>
#include<iostream>
using namespace std;
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        //ListNode *newhead=head->next;
        //cout<<"1"<<endl;
        if(head==NULL)
        	return head;
        if(head->next==NULL)
        	return head;
        ListNode *next=head->next;
        ListNode big(0),small(0);
        ListNode *bignext,*smallnext;
        bignext=&big,smallnext=&small;
        for(;next!=NULL;next=next->next)
        {
        	if(next->val>=head->val)
        	{
        		bignext->next=next;
        		bignext=bignext->next;
			}else if(next->val<head->val)
        	{
        		smallnext->next=next;
        		smallnext=smallnext->next;
			}
			//cout<<".."<<endl;
		}
		bignext->next=NULL;
		smallnext->next=NULL;
		bignext=big.next;
		smallnext=small.next;
		if(bignext!=NULL&&bignext->next!=NULL)
		{
			big.next=sortList(bignext);
		}
		if(smallnext!=NULL&&smallnext->next!=NULL)
		{
			small.next=sortList(smallnext);
		}
		smallnext=&small;
		for(;smallnext->next!=NULL;smallnext=smallnext->next);
		smallnext->next=head;
		head->next=big.next;
		/*
		for(smallnext=small.next;smallnext!=NULL;smallnext=smallnext->next)
		{
			cout<<smallnext->val<<" ";
		}
		cout<<endl;*/
        //cout<<head->val<<endl;
        return small.next;
    }
};
int main()
{
	ListNode head(-1),n(5),m(3),q(4),p(0);
	ListNode *Head;
	head.next=&n;
	n.next=&m;
	m.next=&q;
	q.next=&p;
	p.next=NULL;
	Solution S;
	Head = S.sortList(&head);
	for(;Head!=NULL;Head=Head->next)
	{
		cout<<Head->val<<" ";
	}
	return 0;
 } 
