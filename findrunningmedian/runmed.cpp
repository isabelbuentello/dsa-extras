#include <vector>
#include <queue>
#include <iomanip>
#include <iostream>

using namespace std;

vector<double> runningMedian(vector<int> a) {
    // Max-heap for lower half
    priority_queue<int> lower;
    
    // Min-heap for upper half
    priority_queue<int, vector<int>, greater<int>> upper;
    
    vector<double> result;
    
    for (int num : a) {
        // Add to appropriate heap
        if (lower.empty() || num <= lower.top()) {
            lower.push(num);
        } else {
            upper.push(num);
        }
        
        // Balance heaps (lower can have at most 1 extra element)
        if (lower.size() > upper.size() + 1) {
            upper.push(lower.top());
            lower.pop();
        } else if (upper.size() > lower.size()) {
            lower.push(upper.top());
            upper.pop();
        }
        
        // Calculate median
        double median;
        if (lower.size() > upper.size()) {
            median = lower.top();
        } else {
            median = (lower.top() + upper.top()) / 2.0;
        }
        
        result.push_back(median);
    }
    
    return result;
}

int main() {
}