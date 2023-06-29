// Copy Random Pointer
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> m;
    Node* cursor = head;
    while (cursor) {
        Node* temp = new Node(cursor->val);
        m[cursor] = temp;
        cursor = cursor->next;
    }
    cursor = head;
    while (cursor) {
        if (cursor->next != NULL)
            m[cursor]->next = m[cursor->next];
        if (cursor->random != NULL)
            m[cursor]->random = m[cursor->random];
        cursor = cursor->next;
    }
    return m[head];
}

int main() {
    Node* head = new Node(7);
    Node* node2 = new Node(13);
    Node* node3 = new Node(11);
    Node* node4 = new Node(10);
    Node* node5 = new Node(1);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node2->random = head;
    node3->random = node5;
    node4->random = node3;
    node5->random = head;

    Node* copyHead = copyRandomList(head);

    Node* copyCursor = copyHead;
    while (copyCursor) {
        cout << "Value: " << copyCursor->val;
        if (copyCursor->random)
            cout << ", Random: " << copyCursor->random->val;
        cout << endl;
        copyCursor = copyCursor->next;
    }

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    while (copyHead) {
        Node* temp = copyHead;
        copyHead = copyHead->next;
        delete temp;
    }

    return 0;
}

// Clone Graph
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

unordered_map<Node*, Node*> copies;
Node* cloneGraph(Node* node) {
    if (!node) {
        return NULL;
    }
    if (copies.find(node) == copies.end()) {
        copies[node] = new Node(node -> val, {});
        for (Node* neighbor : node -> neighbors) {
            copies[node] -> neighbors.push_back(cloneGraph(neighbor));
        }
    }
    return copies[node];
}