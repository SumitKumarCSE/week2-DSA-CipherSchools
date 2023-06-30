#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* convertToBST(vector<int>& nums, int low, int high) {
    if(low>high) return NULL;
    int mid=low+(high-low)/2;
    Node* head = new Node(nums[mid]);
    head->left = convertToBST(nums, low, mid-1);
    head->right = convertToBST(nums, mid+1,high);
    return head;
}
Node* sortedArrayToBST(vector<int>& nums) {
    int n=nums.size();
    return convertToBST(nums, 0, n-1);
}

// Kth smallest element in bst
int ans;
void inorder(Node* root, int& k) {
    if (!root) return;
    inorder(root->left, k);
    if (--k == 0){
        ans = root->data;
        return;
    } 
    inorder(root->right, k);
}
int kthSmallest(Node* root, int k) {
    inorder(root, k);
    return ans;
}

void inorder(Node*root,vector<Node*>&v){
    if(root==NULL)
    return;
        
    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}
Node* inOrderSuccessor(Node *root, Node *x) {
    vector<Node*>v;

    inorder(root,v);
    for(int i=0;i<v.size()-1;i++) {
        if(v[i]==x)
            return v[i+1];    
    }
    return NULL;
}

void inorderTraversal(Node* root, vector<int> &in) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left, in);
    in.push_back(root->data);
    inorderTraversal(root->right, in);
}

void preorderTraversal(Node* root, vector<int> &pre) {
    if (root == nullptr) {
        return;
    }
    pre.push_back(root->data);
    preorderTraversal(root->left, pre);
    preorderTraversal(root->right, pre);
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
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    cout<<"Sorted array to bst: ";
    Node* root = sortedArrayToBST(arr);
    printTree(root);
    cout<<endl;

    cout<<"Kth smallest element of bst: ";
    kthSmallest(root, 3);
    cout<<endl;

    cout<<"Inorder Successor: ";
    cout<<inOrderSuccessor(root, root->left->right)->data<<endl;

    return 0;
}
