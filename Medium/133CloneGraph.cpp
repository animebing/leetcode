/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
// DFS, use a visited map to recorded which nodes we have created, then we just need to return the pointers of that node
// visited MUST BE reference 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
        auto res = helper(node, visited);
        return res;
    }
private:
    UndirectedGraphNode *helper(UndirectedGraphNode * node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &visited) {
        if (visited[node] != NULL) return visited[node];
        auto new_node = new UndirectedGraphNode(node->label);
        visited[node] = new_node;
        for (int i = 0; i < node->neighbors.size(); i++) {
            new_node->neighbors.push_back(helper(node->neighbors[i], visited));
        }
        return new_node;
    }
};

// same as above, but more concise and define the map as a private member
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNodee *node) {
        if (!node) return NULL;
        if (visited[node] == NULL) {
            visited[node] = new UndirectedGraphNode(node->label);
            for (auto n:node->neighbors) visited[node]->neighbors.push_back(cloneGraph(n));
        }
        return visited[node];
    }
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
};

// BFS solution, based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/16957/7-17-lines-c-bfs-dfs-solutions
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
        visited[node] = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode *> q;
        q.push(node);
        while (!q.empty()) {
            auto tmp = q.front();
            q.pop();
            for (auto n:tmp->neighbors) {
                if (visited[n] == NULL) {
                    visited[n] = new UndirectedGraphNode(n->label);
                    q.push(n);
                }
                visited[tmp]->neighbors.push_back(visited[n]);
            }
        }
        return visited[node];
    }
};


