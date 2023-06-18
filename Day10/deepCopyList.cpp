/*
Given a linked list with each node having two pointers - next and random.
Deep copy this list.

[Brute force -- using hashmap]
[Three steps -- create copy nodes in after every node -- Assign random pointers -- Extract the copied list]
T.C - O(N) + O(N) + O(N) = O(3N)
S.C - O(1)
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *iter = head;
        Node *front = head;
        while(iter) {
            front = iter->next;
            Node *temp = new Node(iter->val);
            iter->next = temp;
            temp->next = front;
            iter = front;
        }

        iter = head;
        while(iter) {
            if(iter->random != NULL)
                iter->next->random = iter->random->next;
            iter = iter->next->next;
        }

        iter = head;
        Node *copyHead = new Node(0);
        Node *copy = copyHead;

        while(iter) {
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = front;
        } 

        return copyHead->next;
    }
};

