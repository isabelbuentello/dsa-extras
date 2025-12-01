#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> balloons(n + 2);
        balloons[0] = 1;
        balloons[n + 1] = 1;
        for (int i = 0; i < n; i++) {
            balloons[i + 1] = nums[i];
        }
        
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        
        for (int len = 1; len <= n; len++) {
            for (int left = 0; left + len + 1 <= n + 1; left++) {
                int right = left + len + 1;
                
                for (int k = left + 1; k < right; k++) {
                    int coins = balloons[left] * balloons[k] * balloons[right];
                    coins += dp[left][k] + dp[k][right];
                    dp[left][right] = max(dp[left][right], coins);
                }
            }
        }
        
        return dp[0][n + 1];
    }
};

int main() {

}
