#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int Move[][2]={
		0,1,//向右移
		0,-1,//向左移
		1,0,//向下移
		-1,0//向上移 
	};
struct Node{
	int x;
	int y;
};
int main()
{
	vector< vector<char> > board;
	board.resize(3);
	board[0].push_back('O');
	board[0].push_back('X');
	board[0].push_back('O');
	//board[0].push_back('X');
	board[1].push_back('X');
	board[1].push_back('O');
	board[1].push_back('X');
	//board[1].push_back('X');
	board[2].push_back('O');
	board[2].push_back('X');
	board[2].push_back('O');
	//board[2].push_back('X');
	//board[3].push_back('X');
	//board[3].push_back('O');
	//board[3].push_back('X');
	//board[3].push_back('X');
	
	if(board.size()==0)
        return 0;
    int n=board.size();
    int m=board[0].size();

    vector< vector<char> > flag;
    flag.resize(n);
    for(int i=0;i<n;i++)
        flag[i].resize(m);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            flag[i][j]='N';

    queue<Node> Q;
    queue<Node> tmp;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='O'&&flag[i][j]=='N')
            {
                flag[i][j]='Y';
                bool result=false;
                Node node;
                node.x=i;
                node.y=j;
                Q.push(node);
                tmp.push(node);
                while(!Q.empty())
                {
                    Node no;
                    no=Q.front();
                    Q.pop();
                    int tmpx,tmpy;
                    for(int k=0;k<4;k++)
                    {
                        tmpx=no.x+Move[k][0];
                        tmpy=no.y+Move[k][1];
                        if(tmpx>=n||tmpx<0||tmpy>=m||tmpy<0)
                        {
                            result=true;
                            queue<Node> p;
                            swap(p,Q);
                            break;
                        }else if(board[tmpx][tmpy]=='O'&&flag[tmpx][tmpy]=='I')
                        {
                        	result=true;
                            queue<Node> p;
                            swap(p,Q);
                            break;
						}
						else if(board[tmpx][tmpy]=='O'&&flag[tmpx][tmpy]=='N'){
                            flag[tmpx][tmpy]='Y';
                            Node tmpnode;
                            tmpnode.x=tmpx;
                            tmpnode.y=tmpy;
                            Q.push(tmpnode);
                            tmp.push(tmpnode);
                        }
                    }
                }
                if(result)
                {
                	while(!tmp.empty())
                    {
                        Node N;
                        N=tmp.front();
                        flag[N.x][N.y]='I';	//'I'表示不可能的 
                        tmp.pop();
                    }
                	continue;
				}
                else{
                    while(!tmp.empty())
                    {
                        Node N;
                        N=tmp.front();
                        board[N.x][N.y]='X';
                        tmp.pop();
                    }
                }
            }
        }
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<board[i][j];
		cout<<endl;
	}
		
}
