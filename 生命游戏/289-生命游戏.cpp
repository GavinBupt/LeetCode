#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
    void gameOfLife(vector< vector<int> >& board){
        if(board.size()==0)
            return ;
        if(board[0].size()==0)
            return ;
        row = board[0].size();
        line = board.size();
        tmp.clear();
        for(int i=0;i<line;i++){
            tmp_line.clear();
            for(int j=0;j<row;j++){
                sum =0;
                for(int k=0;k<8;k++){
                    tmpx=i+move[k][0];
                    tmpy=j+move[k][1];

                    if(tmpx<0||tmpy<0||tmpx>=line||tmpy>=row){
                        continue;
                    }else{
                        //cout<<tmpx<<","<<tmpy<<endl;
                        sum+=board[tmpx][tmpy];
                    }
                }
                //cout<<sum<<" ";
                if(sum<2||sum>3){
                    tmp_line.push_back(0);
                }else if(sum==2&&board[i][j]==0){
                    tmp_line.push_back(0);
                }else {
                    tmp_line.push_back(1);
                }
            }
            tmp.push_back(tmp_line);
        }
        //cout<<endl;

        for(int i=0;i<line;i++){
            for(int j=0;j<row;j++){
                board[i][j]=tmp[i][j];
            }
        }
    };
private:
    vector< vector<int> > tmp;
    vector<int> tmp_line;
    int move[8][2]= {
            {-1, -1},
            {0, -1},
            {1, 1},
            {1, 0},
            {1,-1},
            {0, 1},
            {-1, 1},
            {-1, 0}
    };
    int line;//行
    int row; //列
    int sum; //周围8个格子的活着的细胞的总和
    int tmpx;
    int tmpy;
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution solution;
    vector< vector<int> > board;
    vector<int> tmp;
    tmp.push_back(0);
    tmp.push_back(1);
    tmp.push_back(0);
    board.push_back(tmp);
    tmp.clear();
    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(1);
    board.push_back(tmp);
    tmp.clear();
    tmp.push_back(1);
    tmp.push_back(1);
    tmp.push_back(1);
    board.push_back(tmp);
    tmp.clear();
    tmp.push_back(0);
    tmp.push_back(0);
    tmp.push_back(0);
    board.push_back(tmp);
    tmp.clear();
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    solution.gameOfLife(board);
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}