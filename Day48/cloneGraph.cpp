/*
Given a reference of a graph node. You need to clone the graph i.e, make a deep copy.
[DFS or BFS]
[Maintain a map(node -> new Node) -- recursively traverse to each graph node -- If it is present then return the node and if not make a new node]

T.C - O(V + E)
S.C - O(N)
*/

#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode *clone(graphNode *node, unordered_map<graphNode*, graphNode*> &vis) {
	if(vis.find(node) != vis.end()) {
		return vis[node];
	}

	graphNode *copy = new graphNode(node->data);
	vis[node] = copy;

	for(auto neighbour : node->neighbours) {
		copy->neighbours.push_back(clone(neighbour, vis));
	}

	return copy;
}

graphNode *cloneGraph(graphNode *node)
{	
	if(node == NULL)
		return NULL;

    unordered_map<graphNode*, graphNode*> vis;
	return clone(node, vis);
}