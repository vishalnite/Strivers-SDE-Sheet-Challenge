/*
Implement a queue using stacks.

The below implementation amortized solution.

Solution:
-- S1 -> S2
-- Add to S2
-- S2 -> S1

Amortized(pop & peek):
-- Two stacks input & output
-- If output not empty
    op.pop
-- Else 
    input -> output
    op.pop
*/

#include<bits/stdc++.h>

class Queue {
    
    stack<int> ip, op;
    int size;
    public:
    Queue() {
        size = 0;
    }

    void enQueue(int val) {
        size++;
        ip.push(val);
    }

    int deQueue() {
        if(size == 0)
            return -1;
        size--;
        if(op.size() == 0) {
            while(ip.size() > 0) {
                op.push(ip.top());
                ip.pop();
            }
        }
        int elem = op.top();
        op.pop();
        return elem;
    }

    int peek() {
        if(size == 0)
            return -1;
        if(op.size() == 0) {
            while(ip.size() > 0) {
                op.push(ip.top());
                ip.pop();
            }
        }
        return op.top();
    }

    bool isEmpty() {
        if(size == 0)
            return true;
        return false;
    }
};