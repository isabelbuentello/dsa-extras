#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        
        // If endWord not in dictionary, no solution
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        
        int length = 1;
        
        while (!q.empty()) {
            int levelSize = q.size();
            
            // Process all words at current level
            for (int i = 0; i < levelSize; i++) {
                string word = q.front();
                q.pop();
                
                // Try changing each character
                for (int j = 0; j < word.length(); j++) {
                    char original = word[j];
                    
                    // Try all 26 letters
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) continue;
                        
                        word[j] = c;
                        
                        // Found the endWord
                        if (word == endWord) {
                            return length + 1;
                        }
                        
                        // If valid word, add to queue and remove from set
                        if (wordSet.find(word) != wordSet.end()) {
                            q.push(word);
                            wordSet.erase(word);
                        }
                    }
                    
                    word[j] = original;  // Restore
                }
            }
            
            length++;
        }
        
        return 0;  // No path found
    }
};

int main() {
}
