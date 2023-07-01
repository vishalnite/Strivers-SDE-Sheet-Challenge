/*
Sort a stack using recursion.

T.C - O(N^2)
S.C - O(N)
*/

#include <bits/stdc++.h> 

void sortedInsert(stack<int> &stack, int num) {

	//Base condition
	if(stack.empty() || (!stack.empty() && num > stack.top())) {
		stack.push(num);
		return;
	}

	//Keep aside the top element
	int elem = stack.top();
	stack.pop();

	//Recursively call to insert at correct position
	sortedInsert(stack, num);

	//while returning put the element back
	stack.push(elem);
}

void sortStack(stack<int> &stack)
{
	//Base condition
	if(stack.empty())
		return;

	//Keep aside the top element
	int num = stack.top();
	stack.pop();

	//Keep calling recursively
	sortStack(stack);

	//while returning put the element at the correct position
	sortedInsert(stack, num);
}