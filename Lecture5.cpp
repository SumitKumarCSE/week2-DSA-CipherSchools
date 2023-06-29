#include<bits/stdc++.h>
using namespace std;

// Insert at bottom
stack<int> pushAtBottom(stack<int>& myStack, int x) {
    stack<int> s;
    while(!myStack.empty()) {
        s.push(myStack.top());
        myStack.pop();
    }
    myStack.push(x);
    while(!s.empty()) {
        myStack.push(s.top());
        s.pop();
    }
    return myStack;
}

// LRU cache
struct Node {
    int key;
    int value;
    Node* prev;
    Node* next;
    Node(int key1, int value1) {
        key = key1;
        value = value1;
    }
};

class LRUCache {
    private:
        Node* head = new Node(0,0);
        Node* tail = new Node(0,0);   
        unordered_map<int,Node*> map1;
        int capacity;

    public:
        LRUCache(int cap) {
            capacity = cap;
            head->next = tail;
            tail->prev = head;
        }
            
        int get(int key) {
            if(map1.find(key) != map1.end()) {
                Node* existingNode = map1[key];
                int value = existingNode->value;
                deleteNode(existingNode);
                addNode(key,value);
                map1.erase(key);
                map1[key] = head->next;
                return value;
            }
            return -1;
        }
            
        void set(int key, int value) {
            if(map1.find(key) != map1.end()) {
                Node* existingNode = map1[key];
                map1.erase(key);
                deleteNode(existingNode);
            }
            
            if(map1.size() == capacity) {
                map1.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            addNode(key,value);
            map1[key]=head->next;
        }
        
        void addNode(int key,int value) {
            Node* createNode = new Node(key,value);
            createNode->next = head->next;
            head->next->prev = createNode;
            head->next = createNode;
            createNode->prev=head;
        }
        
        void deleteNode(Node* deletedNode) {
            deletedNode->prev->next = deletedNode->next;
            deletedNode->next->prev = deletedNode->prev;
            delete deletedNode;
        }
};

int main() {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    s = pushAtBottom(s, 5);
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;

    LRUCache l(2);
    l.set(1,2);
    l.set(2,3);
    l.set(1,5);
    cout<<l.get(2)<<endl;
    l.set(4,5);
    l.set(6,7);
    cout<<l.get(4)<<endl;
    l.set(1,2);
    cout<<l.get(3)<<endl;

}
