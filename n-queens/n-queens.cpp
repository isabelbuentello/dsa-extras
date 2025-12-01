#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        
        vector<bool> cols(n, false);           // columns with queens
        vector<bool> diag1(2 * n - 1, false);  // main diagonals (row - col + n - 1)
        vector<bool> diag2(2 * n - 1, false);  // anti diagonals (row + col)
        
        backtrack(0, n, board, cols, diag1, diag2, result);
        
        return result;
    }
    
private:
    void backtrack(int row, int n, vector<string>& board,
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2,
                   vector<vector<string>>& result) {
        // all queens placed successfully
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        // try placing queen in each column of current row
        for (int col = 0; col < n; col++) {
            int d1 = row - col + n - 1;  // main diagonal index
            int d2 = row + col;           // anti diagonal index
            
            // check if position safe
            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue;
            }
            
            // place queen
            board[row][col] = 'Q';
            cols[col] = true;
            diag1[d1] = true;
            diag2[d2] = true;
            
            // recurse to next row
            backtrack(row + 1, n, board, cols, diag1, diag2, result);
            
            // Rrmove queen (backtrack)
            board[row][col] = '.';
            cols[col] = false;
            diag1[d1] = false;
            diag2[d2] = false;
        }
    }
};

int main() {

}
