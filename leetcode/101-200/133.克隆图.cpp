#include <bits/stdc++.h>

using namespace std;

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


class Solution {
public:
    unordered_map<Node*, Node*> hash;

    Node* cloneGraph(Node* node) {
        if (!node) return NULL;

        dfs(node);

        for (auto [p, e] : hash) {
            for (auto n : p->neighbors) {
                e->neighbors.push_back(hash[n]);
            }
        }

        return hash[node];
    }

    void dfs(Node* node) {
        hash[node] = new Node(node->val);

        for (auto p : node->neighbors) {
            if (!hash.count(p)) dfs(p);
        }
    }
};