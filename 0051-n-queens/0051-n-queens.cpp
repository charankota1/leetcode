class Solution {
public:
    vector<vector<string>> res;   
    vector<int> board;            

    bool isSafe(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col || abs(row - i) == abs(col - board[i]))
                return false;
        }
        return true;
    }

    vector<string> createBoard(int n) {
        vector<string> temp;
        for (int i = 0; i < n; i++) {
            string row(n, '.');
            row[board[i]] = 'Q';
            temp.push_back(row);
        }
        return temp;
    }

    void solveQueen(int row, int n) {
        if (row == n) {
            res.push_back(createBoard(n)); 
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col)) {
                board[row] = col;         
                solveQueen(row + 1, n);   
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board.resize(n);
        solveQueen(0, n);              
        return res;
    }
};