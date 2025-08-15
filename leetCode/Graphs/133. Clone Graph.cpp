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
    Node* cloneGraph(Node* node) {
        if(!node)
         return node;
        
        unordered_map<Node* , Node*> mp;
        mp[node] = new Node(node->val);
        vector<int> vis(101 , 0);
        return dfs(mp , node , vis);
    }

    Node* dfs(unordered_map<Node* , Node*> &mp , Node* node , vector<int> &vis)
    {
        vis[node->val] = 1;
        Node* myNode = mp[node];

        vector<Node*> myNeighbors;

        for(auto &it : node->neighbors) {
         Node* newNode = NULL;
         
         if(mp.find(it) == mp.end())
            newNode = new Node(it->val) , mp[it] = newNode;
         else
            newNode = mp[it];
         
         if(!vis[newNode->val])
          dfs(mp , it , vis);
         
         myNeighbors.push_back(newNode);
        }

        myNode->neighbors = myNeighbors;

        return myNode;
    }
};
