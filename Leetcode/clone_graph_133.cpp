/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*, Node*> &hashmap) {
        if(hashmap.find(node) != hashmap.end()) {
            //already exists
            return hashmap[node];
        }
        hashmap[node] = new Node(node->val);
        for(auto neighbor : node->neighbors) {
            hashmap[node]->neighbors.push_back(dfs(neighbor, hashmap));
        }
        return hashmap[node];
    }
    Node* cloneGraph(Node* node) {
        
        if(node == NULL) 
            return node;
        unordered_map<Node*, Node*> hashmap;
        return dfs(node, hashmap);
    }
};