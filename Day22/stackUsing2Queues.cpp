/*
Implement stack using two queues.

2Queues 
-- Add n to Q2
-- Q1 to Q2 -- Element by Element
-- swap(Q1, Q2)

1Queue
-- Add to Q
-- Push element till size-1 to Q again and pop element
*/

#include <bits/stdc++.h> 
class Stack {
	
    queue<int> q1;
    queue<int> q2;
    int size;
   public:
    Stack() {
        size = 0;
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return size;
    }

    bool isEmpty() {
        if(size == 0)
            return true;
        return false;
    }

    void push(int element) {
        size++;
        q2.push(element);
        while(q1.size() > 0) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        if(isEmpty())
            return -1;
        size--;
        int elem = q1.front();
        q1.pop();
        return elem;
    }

    int top() {
        if(isEmpty())
            return -1;
        return q1.front();
    }
};
