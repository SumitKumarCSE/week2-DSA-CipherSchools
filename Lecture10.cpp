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

// Build Tree from Inorder and Preorder
set<Node*> s;
stack<Node*> st;
Node* buildTree(vector<int> &in,vector<int> &pre, int n) {
    Node* root = NULL;
    for(int p=0,i=0;p<n;) {
        Node* node = NULL;
        do {
            node = new Node(pre[p]);
            if(!root) root=node;
            if(st.size()>0) {
                if(s.find(st.top())!=s.end()) {
                    s.erase(st.top());
                    st.top()->right=node;
                    st.pop();
                } else {
                    st.top()->left=node;
                }
            }
            st.push(node);
        } while(pre[p++]!=in[i] && p<n);
        node=NULL;
        while(st.size()>0 && i<n && st.top()->data==in[i]) {
            node = st.top();
            st.pop();
            i++;
        }
        if(node!=NULL) {
            s.insert(node);
            st.push(node);
        }
    }
    return root;
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

// Serailize and Deserialize
string serialize(Node* root) {
    if(!root) return "";
    string s="";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node==NULL) s.append("#,");
        else s.append(to_string(node->data)+',');
        if(node!=NULL){
            q.push(node->left);
            q.push(node->right);
        }
    }
    return s;
}

Node* deserialize(string data) {
    if(data.size()==0) return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    Node* root=new Node(stoi(str));
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        getline(s,str,',');
        if(str=="#"){
            node->left=NULL;
        } else {
            Node* left=new Node(stoi(str));
            node->left=left;
            q.push(left);
        }
        getline(s,str,',');
        if(str=="#"){
            node->right=NULL;
        } else {
            Node* right=new Node(stoi(str));
            node->right=right;
            q.push(right);
        }
    }
    return root;
}

// LCA of tree
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(!root) return nullptr;
    if(root->data==p->data or root->data==q->data) return root;
    Node* left=lowestCommonAncestor(root->left,p,q);
    Node* right=lowestCommonAncestor(root->right,p,q);
    Node* ans = left and right ? root : (left?left:right);
    return ans;
}

void printTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Maximum Path Sum from root to leaf: "<< maxPathSum(root)<<endl;

    cout << "Maximum Path sum from leaf to leaf: "<<maxPathSumLL(root)<<endl;

    vector<int> in, pre;
    inorderTraversal(root, in);
    preorderTraversal(root, pre);
    cout<<"Build Tree from inorder and preorder: ";
    printTree(buildTree(in, pre, in.size()));
    cout<< endl;

    cout<<"Serialize and Deserialize: ";
    string s = serialize(root);
    printTree(deserialize(s));
    cout<< endl;

    cout<<"Lowest Common Ancestor of tree: "<<lowestCommonAncestor(root, root->left->left, root->left->right->left)->data<<endl;


    return 0;
}
