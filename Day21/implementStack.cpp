/*
Implement stack using arrays.
*/

#include <bits/stdc++.h> 
// Stack class.
class Stack {
    int size;
    int *st;
    int t;
public:

    Stack(int capacity) {
        size = capacity;
        st = new int[size];
        t = -1;
    }

    void push(int num) {
        if(t < size - 1)
            st[++t] = num;
    }

    int pop() {
        if(t == -1)
            return -1;
        return st[t--];
    }
    
    int top() {
        if(t == -1)
            return -1;
        return st[t];
    }
    
    int isEmpty() {
        if(t == -1)
            return 1;
        return 0;
    }
    
    int isFull() {
        if(t == size - 1)
            return 1;
        return 0;
    }
    
};