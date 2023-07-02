/*
Implement LFU (Least Frequently Used) cache.
[Remember LRU cache and exend from that concept]

T.C - O(1)
S.C - O(1)
*/

#include <bits/stdc++.h> 

class Node {
    public:
        int key, value, cnt;
        Node *next;
        Node *prev;
        Node(int k, int v) {
            key = k;
            value = v;
            cnt = 1;
        }
};

class List {
    public:
        int size;
        Node *head, *tail;
        List() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addNode(Node *newNode) {
            Node *temp = head->next;
            newNode->next = temp;
            newNode->prev = head;
            head->next = newNode;
            temp->prev = newNode;
            size++;
        }

        void removeNode(Node *delNode) {
            Node *delNext = delNode->next;
            Node *delPrev = delNode->prev;
            delPrev->next = delNext;
            delNext->prev = delPrev;
            size--;
        }
};

class LFUCache
{
public:

    map<int, Node*> keyNode;
    map<int, List*> freqListMap;
    int maxSize;
    int minFreq;
    int curSize;

    LFUCache(int capacity)
    {
        maxSize = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqList(Node *node) {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);

        if(node->cnt == minFreq && freqListMap[node->cnt]->size == 0) {
            minFreq++;
        }

        List *nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()) {
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }

        node->cnt += 1;
        nextHigherFreqList->addNode(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if(keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqList(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(maxSize == 0)
            return;

        if(keyNode.find(key) != keyNode.end()) {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        }
        else {
            if(curSize == maxSize) {
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->removeNode(list->tail->prev);
                curSize--;
            }
            curSize++;
            minFreq = 1;

            List *listFreq = new List();
            if(freqListMap.find(minFreq) != freqListMap.end()) {
                listFreq = freqListMap[minFreq];
            }

            Node *node = new Node(key, value);
            listFreq->addNode(node);
            keyNode[key] = node;
            freqListMap[minFreq] = listFreq;
        }
    }
};
