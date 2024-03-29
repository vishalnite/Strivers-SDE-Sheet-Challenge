/*
Linked List Hard problem.
Given a linked list and an array containing groups. We need to reverse linked list according to the given groups.

T.C - O(N)
S.C - O(1)
*/

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

vector<Node*> reverseList(Node *head, int blockSize) {
	Node *prev = NULL;
	Node *curr = head;
	Node *next = NULL;
	while(curr != NULL && blockSize--) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	
	return {prev, curr};
}

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	if(head == NULL)
		return head;

	Node *curr = head;
	Node *newHead = NULL;
	Node *tail = curr;
	int i = 0;
	bool flag = false;

	while(i < n && curr) {
		if(b[i] != 0) {
			flag = true;
			vector<Node*> pointers = reverseList(curr, b[i]);
			if(i == 0) {
				newHead = pointers[0];
			}
			else {
				tail->next = pointers[0];
				tail = curr;
			} 
			curr = pointers[1];
		}
		i++;
	}
	
	if(flag)
		tail->next = curr;

	if(newHead == NULL)
		return head;
	return newHead;
}

/******************************* Type 2 -- Leetcode *********************************/
ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) 
            return head;
        
        int count = 0;
        ListNode *ptr = head;
        while(ptr) {
            count++;
            ptr = ptr->next;
        }

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode *pre = dummy, *cur = dummy, *nex = dummy;
        while(count >= k) {
            cur = pre->next;
            nex = cur->next;
            for(int i = 1; i < k; i++) {
                cur->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = cur->next;
            }
            pre = cur;
            count -= k;
        }

        return dummy->next;
    }