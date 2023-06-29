#include<bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;

// Implementing stack using array
class Stack {
    private:
        vector<int> arr;
        int top;

    public:
        Stack() {
            top = -1;
        }

        bool isEmpty() {
            return (top == -1);
        }

        int size() {
            return top + 1;
        }

        void push(int value) {
            arr.push_back(value);
            top++;
        }

        int pop() {
            if(isEmpty()) {
                cout<<"Stack Underflow" << endl;
                return -1;
            }
            int ele = arr[top--];
            cout<<"Popped Element: "<< ele << endl;
            return ele;
        }

        int peek() {
            if(isEmpty()) {
                cout<<"Stack is empty"<< endl;
                return -1;
            }
            return arr[top];
        }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    int topEle = stack.peek();
    cout<<"Top Element: "<< topEle << endl;

    stack.pop();
    // stack.pop();

    if(stack.isEmpty()) {
        cout<<"Stack is Empty."<< endl;
    } else {
        cout<<"Stack is not empty." << endl;
    }

    cout<<stack.size()<< endl;

    return 0;
}


// Implementing stack using linked list
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        Node* current = top;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed element " << value << " onto the stack" << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop element from an empty stack" << endl;
            return;
        }
        int poppedElement = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Popped element " << poppedElement << " from the stack" << endl;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout << "Top element of the stack: " << stack.peek() << endl;

    stack.pop();
    stack.pop();

    cout << "Top element of the stack: " << stack.peek() << endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}

// Implement queue using array

class Queue {
private:
    vector<int> arr;
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    void enqueue(int value) {
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        arr.push_back(value);
        cout << "Enqueued element " << value << " to the queue" << endl;
    }

    // Remove the element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot dequeue element from an empty queue" << endl;
            return;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        cout << "Dequeued element from the queue" << endl;
    }

    // Get the element at the front of the queue
    int frontElement() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get the element at the rear of the queue
    int rearElement() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
};

int main() {
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    cout << "Front element of the queue: " << queue.frontElement() << endl;
    cout << "Rear element of the queue: " << queue.rearElement() << endl;
    queue.dequeue();
    queue.dequeue();

    cout << "Front element of the queue: " << queue.frontElement() << endl;
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}

// Valid Parentheses
bool isValid(string s) {
    stack<char> st;
    for(char ch : s) {
        if(ch == '(' || ch == '[' || ch == '{') {
            st.push(ch);
        } else if(st.size()>0 && ((ch ==')' && st.top()=='(') || (ch==']' && st.top()=='[') || (ch=='}' && st.top()=='{'))) {
            st.pop();
        } else {
            return false;
        }
    }
    if(st.size()!=0) {
        return false;
    }
    return true;
}

// Minimum number of swaps to make the string balanced
int minSwaps(string s) {
    stack<char> st;
    for(char &ch:s){
        if(ch=='[')  st.push(ch);
        else if(!st.empty()) st.pop();
    }
    return (st.size()+1)/2;
}

int main() {
    cout<<isValid("()[]{{}}")<< endl;
    cout<<isValid("([)]{}")<< endl;

    cout<<minSwaps("][][")<< endl;
    cout<<minSwaps("]]][[[")<< endl;
}
