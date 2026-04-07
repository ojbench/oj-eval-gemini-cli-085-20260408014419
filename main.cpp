#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool end_of_input = false;

TreeNode* buildTree() {
    if (end_of_input) return nullptr;
    int val;
    if (!(cin >> val)) return nullptr;
    if (val == -2) {
        end_of_input = true;
        return nullptr;
    }
    if (val == -1) return nullptr;
    
    TreeNode* root = new TreeNode(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

bool pruneTree(TreeNode*& node) {
    if (node == nullptr) return true;
    
    bool leftPruned = pruneTree(node->left);
    bool rightPruned = pruneTree(node->right);
    
    if (node->val == 0 && leftPruned && rightPruned) {
        delete node;
        node = nullptr;
        return true;
    }
    
    return false;
}

bool first = true;
void printTree(TreeNode* node) {
    if (!first) cout << " ";
    first = false;
    
    if (node == nullptr) {
        cout << "-1";
        return;
    }
    
    cout << node->val;
    printTree(node->left);
    printTree(node->right);
}

void deleteTree(TreeNode* node) {
    if (node == nullptr) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

int main() {
    // Optimize input/output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    TreeNode* root = buildTree();
    pruneTree(root);
    printTree(root);
    cout << "\n";
    
    deleteTree(root);
    
    return 0;
}
