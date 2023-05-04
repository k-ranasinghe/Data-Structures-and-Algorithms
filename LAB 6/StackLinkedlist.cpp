#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void Push(Node*& top, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void Pop(Node*& top) {
    if (top == nullptr) {
        cout << "Stack Underflow" << endl;
    }
    Node* temp = top;
    top = top->next;
    delete temp;
}

bool isEmpty(Node* top) {
    return top == nullptr;
}

int StackTop(Node* top) {
    if (top == nullptr) {
        cout << "Stack Underflow" << endl;
        return -1; 
    }
    return top->data;
}

void Display(Node* top) {
    cout << "Stack: ";
    while (top != nullptr) {
        cout << top->data << " ";
        top = top->next;
    }
    cout << endl;
}

int main() {

    int n;
    cout << "Enter the size of stack: ";
    cin >> n;

    double cpu_time_used;
    auto start = chrono::high_resolution_clock::now();

    Node* top = nullptr;

    for(int i = 0; i < n/2; i++){
        int r = rand() % 10001 + 10000;
        Push(top,r);
    }

    Display(top);
    cout << "Stack Top : " << StackTop(top) << endl;

    for(int i = 0; i < n/4; i++){
        Pop(top);
    }

    Display(top);
    cout << "Stack Top : " << StackTop(top) << endl;

    for(int i = 0; i < n/2; i++){
        int r = rand() % 10001 + 10000;
        Push(top,r);
    }

    Display(top);
    cout << "Stack Top : " << StackTop(top) << endl;

    for(int i = 0; i < n/4; i++){
        Pop(top);
    }

    Display(top);
    cout << "Stack Top : " << StackTop(top) << endl;

    for(int i = 0; i < n/2; i++){
        int r = rand() % 10001 + 10000;
        Push(top,r);
    }

    Display(top);
    cout << "Stack Top : " << StackTop(top) << endl;

    for(int i = 0; i < n; i++){
        Pop(top);
    }

    Display(top);
    cout << "is stack empty : " << isEmpty(top) << endl;

    auto end = chrono::high_resolution_clock::now();
    cpu_time_used = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time taken: " << cpu_time_used << " microseconds" << endl;
    return 0;
}
