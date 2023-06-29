/*
Implement queue using linked list.
Also write destructor definition while using linked list approach.[Imp]
*/

#include <bits/stdc++.h> 
class Queue {
public:

    class queue {
        public:
            int data;
            queue *next;

            queue() {
                this->data = 0;
                this->next = NULL;
            }
            queue(int x) {
                this->data = x;
                this->next = NULL;
            }
    };

    queue *f;
    queue *r;

    Queue() {
        f = NULL;
        r = NULL;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        if(r == NULL)
            return true;
        return false;
    }

    void enqueue(int data) {
        queue *temp = new queue(data);
        if(f == NULL || r == NULL) {
            f = temp;
            r = temp;
        }
        else {
            r->next = temp;
            r = temp;
        }
    }

    int dequeue() {
        if(f == NULL) 
            return -1;
        
        int elem = f->data;
        if(f == r) {
            delete f;
            f = NULL;
            r = NULL;
        }
        else {
            queue *temp = f;
            f = f->next;
            delete temp;
        }

        return elem;
    }

    int front() {
        if(f == NULL)
            return -1;
        return f->data;
    }
};