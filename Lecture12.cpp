#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// construct tree from preorder
Node* construct(int &idx, int bound, vector<int> &pre){
    if(idx==pre.size()||pre[idx]>bound) return NULL;
    Node* root=new Node(pre[idx]);
    idx++;
    root->left=construct(idx,root->data,pre);
    root->right=construct(idx,bound,pre);
    return root;
}
Node* bstFromPreorder(vector<int>& pre) {
    int idx=0;
    return construct(idx,INT_MAX,pre);
}

// Check bst is Balanced or not
int maxDepth(Node* root) {
    if(root==NULL)
        return 0;
    int l=maxDepth(root->left);
    int r=maxDepth(root->right);
    return max(l,r)+1;
}
bool isBalanced(Node* root) {
    if(root==NULL)
        return true;
    int leftheight=maxDepth(root->left);
    int rightheight=maxDepth(root->right);
    int diff=abs(leftheight-rightheight);

    bool ans=(diff<=1);
    bool leftans=isBalanced(root->left);
    bool rightans=isBalanced(root->right);
    return (ans&&leftans&&rightans);
}

// Unique BST count
int solve(int n, vector<int>& dp) {
    if(n <= 1) {
        return 1;
    }
    if(dp[n] != -1) {
        return dp[n];
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) 
        ans += solve(i-1, dp) * solve(n-i, dp);
        
    return dp[n] = ans;
}
int numTrees(int n) {
    vector<int> dp(n+1, -1);
    return solve(n, dp);
}

void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

int main() {
    Node* root = new Node(90);
    root->left = new Node(70);
    root->left->right = new Node(80);
    root->left->left = new Node(50);
    root->left->left->right = new Node(60);
    root->right = new Node(30);
    root->right->left = new Node(20);
    root->right->left->left = new Node(10);
    root->right->right = new Node(50);

    vector<int> pre;
    preorderTraversal(root, pre);
    cout<<"Construct bst from Preorder: ";
    root = bstFromPreorder(pre);
    printTree(root);
    cout<<endl;

    cout<<"Is Balanced bst: "<<isBalanced(root)<< endl;

    cout<<"Unique bst count: "<< numTrees(4)<<endl;

    return 0;
}
