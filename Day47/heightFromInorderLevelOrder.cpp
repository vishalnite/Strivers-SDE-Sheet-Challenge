/*
FInd the height of the binary tree from inorder and level order traversal without constructing the tree.
[Store (height, leftIdx, rightIdx) in a queue]
[When we find the root in inorder -- the left and right subpart will be the left and right subtree]
[Store their index and if they form subtree, update the height]

T.C - O(N)
S.C - O(N)
*/

#include <bits/stdc++.h> 

class Node {
	public:
		int h, li, ri;

		Node(int h, int li, int ri) {
			this->h = h;
			this->li = li;
			this->ri = ri;
		}
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelorder, int n){

	int ans = 0;
	
	Node root(0, 0, n - 1);
	queue<Node> q;
	q.push(root);

	unordered_map<int, int> mp;

	for(int i = 0; i < n; i++) {
		mp[inorder[i]] = i;
	}

	for(int i = 0; i < n; i++) {
		Node node = q.front();
		q.pop();

		ans = max(ans, node.h);

		int li = node.li, ri = node.ri;
		int rootIdx = mp[levelorder[i]];

		if(rootIdx - 1 >= li) {
			Node left(node.h + 1, li, rootIdx - 1);
			q.push(left);
		}

		if(rootIdx + 1 <= ri) {
			Node right(node.h + 1, rootIdx + 1, ri);
			q.push(right);
		}
	}

	return ans;

}