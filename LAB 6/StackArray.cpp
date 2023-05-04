#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <chrono>

using namespace std;

int top = -1;

void Push(int x ,int S[], int MaxSize){
    if(top >= MaxSize-1){
        cout << "Stack Overflow" << endl;
    }else{
        top++;
        S[top] = x;
    }
}

void Pop(){
    if(top <=-1){
        cout << "Stack Underflow" << endl;
    }else{
        top--;
    }
}

bool isEmpty() {
    return top == -1;
}

bool isFull(int MaxSize) {
    return top == MaxSize - 1;
}

int StackTop(int S[]) {
    if (top == -1) {
        std::cout << "Error: Stack is empty\n";
        return -1;
    } else {
        return S[top];
    }
}

void Display(int S[]) {
    cout << "Stack: ";
    for (int i = 0; i <= top; i++) {
        cout << S[i] << " ";
    }
    cout << endl;
}

int main() {

    int n;
    cout << "Enter the size of stack: ";
    cin >> n;

    int S[n];
  
    double cpu_time_used;
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < n/2; i++){
        int r = rand() % 10001 + 10000;
        Push(r, S, n);
    }

    Display(S);
    cout << "Stack Top : " << StackTop(S) << endl;

    for(int i = 0; i < n/4; i++){
        Pop();
    }

    Display(S);
    cout << "Stack Top : " << StackTop(S) << endl;

    for(int i = 0; i < n/2; i++){
        int r = rand() % 10001 + 10000;
        Push(r, S, n);
    }

    Display(S);
    cout << "Stack Top : " << StackTop(S) << endl;

    for(int i = 0; i < n/4; i++){
        Pop();
    }

    Display(S);
    cout << "Stack Top : " << StackTop(S) << endl;

    for(int i = 0; i < n/2; i++){
        int r = rand() % 10001 + 10000;
        Push(r, S, n);
    }

    Display(S);
    cout << "Stack Top : " << StackTop(S) << endl;
    cout << "is stack full : " << isFull(n) << endl;

    for(int i = 0; i < n; i++){
        Pop();
    }

    Display(S);
    cout << "is stack empty : " << isEmpty() << endl;

    auto end = chrono::high_resolution_clock::now();
    cpu_time_used = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Time taken: " << cpu_time_used << " microseconds" << endl;
    return 0;
}
