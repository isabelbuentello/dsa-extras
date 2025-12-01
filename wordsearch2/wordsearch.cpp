#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* children[26] = {};
        string* word = nullptr;  
    };
    
    TrieNode* root;
    vector<string> result;
    int m, n;
    
    void insertWord(string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->word = &word;
    }
    
    void dfs(vector<vector<char>>& board, int row, int col, TrieNode* node) {
        if (row < 0 || row >= m || col < 0 || col >= n) {
            return;
        }
        
        char c = board[row][col];
        
        if (c == '#' || !node->children[c - 'a']) {
            return;
        }
        
        node = node->children[c - 'a'];
        
        // Found a word
        if (node->word) {
            result.push_back(*node->word);
            node->word = nullptr;  
        }
        
        board[row][col] = '#';
        
        dfs(board, row + 1, col, node);
        dfs(board, row - 1, col, node);
        dfs(board, row, col + 1, node);
        dfs(board, row, col - 1, node);
        
        board[row][col] = c;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        root = new TrieNode();
        result.clear();
        
        for (string& word : words) {
            insertWord(word);
        }
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }
        
        return result;
    }
};

int main() {
}