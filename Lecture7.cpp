#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Level Order Traversal
void levelOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        cout << current->val << " ";

        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }
}

// Dfs traversal of tree
void dfs(TreeNode* node, int depth, vector<vector<int>>& result) {
    if (node == nullptr) {
        return;
    }

    if (depth >= result.size()) {
        result.push_back({});
    }

    result[depth].push_back(node->val);
    dfs(node->left, depth + 1, result);
    dfs(node->right, depth + 1, result);
}
vector<vector<int>> levelOrderTraversaldfs(TreeNode* root) {
    vector<vector<int>> result;
    dfs(root, 0, result);
    return result;
}

// Diameter of tree
int height(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    int leftDiameter = diameterOfBinaryTree(root->left);
    int rightDiameter = diameterOfBinaryTree(root->right);
    
    return max({leftDiameter, rightDiameter, leftHeight + rightHeight});
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(9);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(7);

    vector<vector<int>> traversal = levelOrderTraversaldfs(root);

    cout << "Level Order Traversal: " << endl;
    for (const auto& level : traversal) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    cout<<"Diameter of tree: ";
    cout<<diameterOfBinaryTree(root)<<endl;

    return 0;
}
