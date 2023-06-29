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

// Vertical Order Traversal
void verticalOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    map<int, vector<int>> verticalLines;
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int line = q.front().second;
        q.pop();
    
        verticalLines[line].push_back(node->val);
        if (node->left) {
            q.push(make_pair(node->left, line - 1));
        }
        if (node->right) {
            q.push(make_pair(node->right, line + 1));
        }
    }
    
    for (const auto& line : verticalLines) {
        cout << "Line " << line.first << ": ";
        for (int val : line.second) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Top view of a tree
void topView(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    
    map<int, int> verticalLines;
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));
    
    while (!q.empty()) {
        TreeNode* node = q.front().first;
        int line = q.front().second;
        q.pop();
        
        if (verticalLines.find(line) == verticalLines.end()) {
            verticalLines[line] = node->val;
        }
        if (node->left) {
            q.push(make_pair(node->left, line - 1));
        }
        if (node->right) {
            q.push(make_pair(node->right, line + 1));
        }
    }
    
    for (const auto& line : verticalLines) {
        cout << line.second << " ";
    }
}

// Left view of a tree
void leftView(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        cout << q.front()->val << " ";

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }
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

    cout<<"Vertical Order Traversal: "<<endl;
    verticalOrderTraversal(root);

    cout<<"Top view of a tree: ";
    topView(root);

    cout<<"Left view of a tree: ";
    leftView(root);

    return 0;
}
