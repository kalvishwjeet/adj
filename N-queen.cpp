#include <bits/stdc++.h>
using namespace std;

class NQueen
{

public:

    bool isSafe(int row, int col, vector<string> &board,int n)
    {
        int duprow=row;
        int dupcol=col;
        //diagonal left up
        while(row>=0 && col>=0)
        {
            if(board[row][col]=='Q'){
                return false;
            }
            row--;
            col--;
        }

        row=duprow;
        col=dupcol;
        //diagonal left  down
        while(row<n && col>=0)
        {
            if(board[row][col]=='Q'){
                return false;
            }
            row++;
            col--;
        }

        row=duprow;
        col=dupcol;
        //straight line same row left
        while(col>=0)
        {
            if(board[row][col]=='Q'){
                return false;
            }
            col--;
        }


        return true;

    }

    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n)
    {
        if(col==n)
        {
            ans.push_back(board);
            return ;
        }

        for(int row =0 ;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]='Q';

                solve(col+1,board,ans,n);

                board[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNqueen(int n)
    {
        vector<string>board(n);
        vector<vector<string>>ans;

        string s(n,'.');

        for(int i=0;i<n;i++)
        {
            board[i]=s;
        }

        solve(0,board,ans,n);

        return ans;
    }
    
};


int main()
{   
    NQueen obj;
    cout<<"Enter the size of ChessBoard"<<endl;
    int n;
    cin>>n;
    vector<vector<string>>ans=obj.solveNqueen(n);

    for (int i = 0; i < ans.size(); i++) {
    cout << "Arrangement " << i + 1 << "\n";
    for (int j = 0; j < ans[0].size(); j++) {
      cout << ans[i][j];
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}

/*

#include<bits/stdc++.h>
using namespace std;

// leftRow 
// . . . . . . Q

// upperLeftDiagonal
//  .
//    .
//      .
//        .
//          .
//            Q

// lowerRightDiagonal
//            Q
//          .
//        .
//      .
//    .
//  .

void branchAndBound(int col, int n, vector<string>& board, vector<bool>& leftRow, vector<bool>& upperLeftDiagonal, vector<bool>& lowerRightDiagonal, vector<vector<string>>& ds) {
    if(col == n) {
        ds.push_back(board);
        return ;
    }

    for (int row = 0; row < n; row++)
    {
        if(leftRow[row] == 0 and upperLeftDiagonal[(n-1)+(col-row)] == 0 and lowerRightDiagonal[row+col] == 0) {
            leftRow[row] = 1, upperLeftDiagonal[(n-1)+(col-row)] = 1, lowerRightDiagonal[row+col] = 1;
            board[row][col] = 'Q';
            branchAndBound(col+1, n, board, leftRow, upperLeftDiagonal, lowerRightDiagonal, ds);
            leftRow[row] = 0, upperLeftDiagonal[(n-1)+(col-row)] = 0, lowerRightDiagonal[row+col] = 0;
            board[row][col] = '.';
        }
    }
}

int main(){
    int n = 4;
    string str(n, '.');
    vector<string> board(n, str);
    vector<vector<string>> ans;

    vector<bool> uld(2*n-1, 0), lrd(2*n-1, 0), lr(n, 0);
    branchAndBound(0, n, board, lr, uld, lrd, ans);

    cout << "Total possible Boards are : " << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Board " << i+1 << endl;
        for (int j = 0; j < ans[i].size(); j++)
        {
            for (int k = 0; k < ans[i][j].size(); k++)
            {
                cout << ans[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

*/