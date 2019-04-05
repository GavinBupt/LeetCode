#include<iostream>
#include<vector>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x),next(NULL){}
	
}; 
int main()
{
	vector<ListNode*> list;
	ListNode ln1(1);
	ListNode ln2(4);
	ListNode ln3(5);
	ln1.next=&ln2;
	ln2.next=&ln3;
	list.push_back(&ln1);
	ListNode ln4(1);
	ListNode ln5(3);
	ListNode ln6(4);
	ln4.next=&ln5;
	ln5.next=&ln6;
	list.push_back(&ln4);
	ListNode ln7(2);
	ListNode ln8(6);
	ln7.next=&ln8;
	list.push_back(&ln7);
	ListNode *l;
	ListNode *k;
	ListNode *Next;
	ListNode *tmp;
	ListNode *init;
	init=list[0];
	l=init;
	Next=l->next;
	//cout<<(l->next->next)->val; 
	//int size=list[0].size();
	for(int i=1;i<list.size();i++)
	{
		l=init;
		Next=l->next;
		k=list[i];
		//int sizetmp=list[i].size();
		while(l!=NULL&&k!=NULL)
		{
			if(k->val>=l->val&&(Next==NULL||k->val<=Next->val))
			{
				//tmp=l->next;
				l->next=k;
				k=k->next;
				l=l->next;
				l->next=Next;
				
			}else if(k->val<l->val){
				int zancun=l->val;
				l->val=k->val;
				k->val=zancun;
				l->next=k;
				k=k->next;
				l=l->next;
				l->next=Next;
			}else{
				l=l->next;
				Next=Next->next;
			}
		}
		
		
		
	}
	l=init;
	while(l!=NULL)
	{
		cout<<l->val<<" ";
		l=l->next;
	}
	//ln.ListNode(1);
	//cout<<ln.val;
	//list.push_back(&ln);
	
	return 0;
}
