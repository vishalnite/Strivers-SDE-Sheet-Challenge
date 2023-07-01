/*
Implement LRU(Least Recently Used) cache.
[use hashmap and DLL]

T.C - O(1)
S.C - O(2N)
*/

#include<bits/stdc++.h>

class LRUCache
{
public:
    class node {
        public:
            int key;
            int value;
            node *next;
            node *prev;

            node(int k, int v) {
                key = k;
                value = v;
                next = NULL;
                prev = NULL;
            }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);
    unordered_map<int, node*> mp;
    int size;

    LRUCache(int capacity)
    {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(node *newNode) {
        node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        temp->prev = newNode;
        head->next = newNode;
    }

    void deleteNode(node *delNode) {
        node *delPrev = delNode->prev;
        node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key)
    {
        if(mp.find(key) != mp.end()) {
            node *resNode = mp[key];
            int res = resNode->value;
            mp.erase(key);
            deleteNode(resNode);
            addNode(resNode);
            mp[key] = head->next;

            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(mp.find(key) != mp.end()) {
            node *existingNode = mp[key];
            mp.erase(key);
            deleteNode(existingNode);
        }
        
        if(mp.size() == size) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        addNode(new node(key, value));
        mp[key] = head->next;
    }
};
