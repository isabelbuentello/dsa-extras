#include <string>
#include <sstream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root) {
            return "null";
        }
        
        return to_string(root->val) + "," 
             + serialize(root->left) + "," 
             + serialize(root->right);
    }

    TreeNode* deserialize(string data) {
        queue<string> nodes;
        stringstream ss(data);
        string token;
        
        while (getline(ss, token, ',')) {
            nodes.push(token);
        }
        
        return buildTree(nodes);
    }
    
private:
    TreeNode* buildTree(queue<string>& nodes) {
        if (nodes.empty()) {
            return nullptr;
        }
        
        string val = nodes.front();
        nodes.pop();
        
        if (val == "null") {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(stoi(val));
        node->left = buildTree(nodes);
        node->right = buildTree(nodes);
        
        return node;
    }
};

int main() {
}