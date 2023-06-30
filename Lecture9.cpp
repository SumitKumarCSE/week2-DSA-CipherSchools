#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Maximum Path Sum from root to leaf
int ans=INT_MIN;
void maxPath(Node* root, int sum){
    if(!root) return ;
    if(!root->left && !root->right){
        sum+=root->data;
        ans=max(ans,sum);
        return ;
    }
    maxPath(root->left, sum+root->data);
    maxPath(root->right, sum+root->data);
}
int maxPathSum(Node* root) {
    int sum=0;
    maxPath(root, sum);
    return ans;
}

// Maximum path sum from leaf to leaf
int maxPathSumHelper(Node* root,int &pathLen) {
    if (!root) return INT_MIN;
    if (root->left == NULL && root->right == NULL) return root->data;
    int l = maxPathSumHelper(root->left,pathLen), r = maxPathSumHelper(root->right,pathLen);
    if (root->left != NULL && root->right != NULL)
        pathLen = max(pathLen,l+r+root->data);

    return max(l,r)+root->data;
}

int maxPathSumLL(Node* root) {
    int pathLen = INT_MIN;
    int temp = maxPathSumHelper(root,pathLen);
    if (root->left == NULL || root->right== NULL)
        return max(temp,pathLen);
        
    return pathLen;
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Maximum Path Sum from root to leaf: "<< maxPathSum(root)<<endl;

    cout << "Maximum Path sum from leaf to leaf: "<<maxPathSumLL(root)<<endl;

    return 0;
}
