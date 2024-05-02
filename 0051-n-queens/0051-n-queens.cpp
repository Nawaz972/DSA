class Solution {
public:
    
    bool isTrue(int i, int j, int n, vector<string> &board)
    {
        int dupi = i;
        int dupj = j;
        while(i >= 0 && j >= 0)
        {
            if(board[i][j] == 'Q')  return false;
            i--;
            j--;
        }
        i = dupi;
        j = dupj;
        while(i < n && j >= 0)
        {
            if(board[i][j] == 'Q')  return false;
            i++;
            j--;
        }
        i = dupi;
        j = dupj;
        while(j >= 0)
        {
            if(board[i][j] == 'Q')  return false;
            j--;
        }
        return true;
    }
    
    void solve(int j, int n, vector<string> &board, vector<vector<string>> &ans)
    {
        if(j == n)    
        {
            ans.push_back(board);
            return;   
        }
        for(int i = 0; i < n; i++)
        {
            if(isTrue(i, j, n, board))
            {
                board[i][j] = 'Q';
                solve(j + 1, n, board, ans);
                board[i][j] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string str(n, '.');
        for(int i = 0; i < n; i++)
        {
            board[i] = str;
        }
        solve(0, n, board, ans);
        return ans;
    }
};