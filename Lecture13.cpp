#include<bits/stdc++.h>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }
    void heapifyUp(int i);
    void heapifyDown(int i);

public:
    void insert(int value);
    int getMinimum();
    void extractMinimum();
    void update(int oldValue, int newValue);
    void remove(int value);

    void printHeap();
};

void MinHeap::heapifyUp(int i) {
    while (i > 0 && heap[i] < heap[parent(i)]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::heapifyDown(int i) {
    int left = leftChild(i);
    int right = rightChild(i);
    int smallest = i;

    if (left < heap.size() && heap[left] < heap[smallest]) {
        smallest = left;
    }

    if (right < heap.size() && heap[right] < heap[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapifyDown(smallest);
    }
}

void MinHeap::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int MinHeap::getMinimum() {
    if (heap.empty()) {
        throw out_of_range("Heap is empty");
    }
    return heap[0];
}

void MinHeap::extractMinimum() {
    if (heap.empty()) {
        throw out_of_range("Heap is empty");
    }

    heap[0] = heap.back();
    heap.pop_back();
    heapifyDown(0);
}

void MinHeap::update(int oldValue, int newValue) {
    for (int i = 0; i < heap.size(); i++) {
        if (heap[i] == oldValue) {
            heap[i] = newValue;
            if (newValue < oldValue) {
                heapifyUp(i);
            } else {
                heapifyDown(i);
            }
            return;
        }
    }
}

void MinHeap::remove(int value) {
    for (int i = 0; i < heap.size(); i++) {
        if (heap[i] == value) {
            heap[i] = heap.back();
            heap.pop_back();
            heapifyDown(i);
            return;
        }
    }
}

void MinHeap::printHeap() {
    for (int i = 0; i < heap.size(); i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    MinHeap minHeap;

    minHeap.insert(8);
    minHeap.insert(5);
    minHeap.insert(12);
    minHeap.insert(3);
    minHeap.insert(10);

    int minimum = minHeap.getMinimum();
    minHeap.extractMinimum();
    minHeap.update(8, 2);
    minHeap.remove(12);

    return 0;
}
