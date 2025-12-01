#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        deque<int> dq;  // stores indices, front = max element's index
        
        for (int i = 0; i < nums.size(); i++) {
            // Remove indices outside the window
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            
            // Remove indices of elements smaller than current
            // they can never be the max while current element exists
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            // Start adding to result once we have a full window
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        
        return result;
    }
};

int main() {
}