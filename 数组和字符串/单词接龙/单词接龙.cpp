#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
struct Node{
	string s;
	int t;
};
bool decide(string s1,string s2)
{
	int panduan=0;
	for(int i=0;i<s1.length();i++)
	{
		if(s1[i]!=s2[i])
			panduan++;
	}
	if(panduan==1)
		return true;
	else
		return false;
}

int main()
{
	string beginWord,endWord;
	beginWord="hit";
	endWord="cog";
	vector<string> wordList;
	wordList.push_back("hot");
	wordList.push_back("dot");
	wordList.push_back("dog");
	wordList.push_back("lot");
	wordList.push_back("log");
	wordList.push_back("cog");
	int i=0;
	queue<Node> Q;
	int time=0;
	for(;i<wordList.size();i++)
	{
		if(wordList[i]==endWord)
			break; 
	} 
	if(i==wordList.size())
	{
		
		cout<<0;
		return 0;
	}
	
	int ans=0;
	Node node;
	node.s=beginWord;
	node.t=1;
	Q.push(node);
	bool flag=false;
	while(!Q.empty())
	{
		Node n;
		n=Q.front();
		Q.pop();
		for(int i=0;i<wordList.size();i++)
		{
			if(decide(wordList[i],n.s))	//如果是 
			{
				//cout<<wordList[i]<<endl;
				if(wordList[i]==endWord)
				{
					ans=n.t+1;
					queue<Node> empty;
    				swap(empty, Q);
					break;
				}else{
					Node N;
					N.s=wordList[i];
					N.t=n.t+1;
					Q.push(N);
					wordList.erase(wordList.begin()+i);
					i--;
				}
			}
		}
	}
	cout<<ans;
	
	return 0;
	//现在i的位置即为beginword的位置 
}
