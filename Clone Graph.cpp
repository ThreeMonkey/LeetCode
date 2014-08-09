/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.


As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle

解题思路：
　　递归求解，采用unoreded_map来记录新生成的节点。
*/
#include <unordered_map>
using namespace std;

/**
* Definition for undirected graph.
*/
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};


class Solution {
public:
	unordered_map<int, UndirectedGraphNode*> dict;
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL || dict.count(node->label)) return NULL;

		UndirectedGraphNode * new_node = new UndirectedGraphNode(node->label);
		dict[node->label] = new_node;

		for (int i = 0; i < (node->neighbors).size(); i++) {
			cloneGraph((node->neighbors)[i]);
			new_node->neighbors.push_back(dict[(node->neighbors)[i]->label]);
		}

		return new_node;
	}
};