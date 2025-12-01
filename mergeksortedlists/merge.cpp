#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> minHeap(compare);
        
        for (ListNode* list : lists) {
            if (list) {
                minHeap.push(list);
            }
        }
        
        ListNode dummy(0);
        ListNode* current = &dummy;
        
        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();
            
            current->next = node;
            current = current->next;
            
            if (node->next) {
                minHeap.push(node->next);
            }
        }
        
        return dummy.next;
    }
};

ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (int i = 1; i < vals.size(); i++) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    
    // Example 1: [[1,4,5],[1,3,4],[2,6]]
    vector<ListNode*> lists = {
        createList({1, 4, 5}),
        createList({1, 3, 4}),
        createList({2, 6})
    };
    
    ListNode* result = solution.mergeKLists(lists);
    
    cout << "Merged list: ";
    printList(result);  // Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4 -> 5 -> 6
    
    return 0;
}