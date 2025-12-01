#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;  // stores indices
        int maxArea = 0;
        int n = heights.size();
        
        for (int i = 0; i <= n; i++) {
            // Use 0 as height for the "virtual" bar at the end
            int currentHeight = (i == n) ? 0 : heights[i];
            
            // While current bar is shorter than the bar at stack top,
            // calculate area with stack top as the smallest bar
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                
                // Width = distance between current index and the new top
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            
            st.push(i);
        }
        
        return maxArea;
    }
};

int main() {
}