// topological sort, build the graph using adjacent table(linked list), for each pair<a, b>, make a edge from b to a, 
// compute the indegree for each node. during topological sort, each time find a node j with indegree being 0, and decrease the indegree
// of nodes that j points to, if there is no j, which indicates there is a cycle, then return {}
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<list<int>> graph = makeGraph(numCourses, prerequisites);
        vector<int> indegree = computeIndegree(graph, numCourses);
        vector<int> res;
        for (int i = 0; i < numCourses; i++) { // find node one by one
            int j = 0;
            for (; j < numCourses; j++)
                if (indegree[j] == 0) break; 
            if (j == numCourses) return {};  // there is a cycle
            indegree[j]--;  // ATTENTION
            res.push_back(j);  
            for (int end : graph[j]) indegree[end]--; 
        }
        return res;
    }
private:
    vector<list<int>> makeGraph(int n, vector<pair<int, int>> &prerequisites) {
        vector<list<int>> graph(n);
        for (auto p : prerequisites) graph[p.second].push_back(p.first);
        return graph;
    }
    vector<int> computeIndegree(vector<list<int>> &graph, int n) {
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (int end : graph[i]) indegree[end]++;
        }
        return indegree;
    }
}; 


// use dfs to do topological sort, maintain two bool vectors, visited and onpath, the former is to record whether a node is visited during
// the whole process, the latter is to record whether a node is visited during the traversal from a node, these two vector is really magic
// the other important things is that only when all children nodes have been visited, the node will be pushed into the stack to make sure that
// the node is in front of its children nodes(the topological sort definition)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<list<int>> graph = makeGraph(numCourses, prerequisites);
        stack<int> s;  // vector<int> res;
        vector<bool> visited(numCourses, false);
        vector<bool> onpath(numCourses, false);
        
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (findCircle(graph, visited, onpath, s, i)) return {};
            }
        }
        vector<int> res;  // reverse(res.begin(), res.end())
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
    }
private:
    vector<list<int>> makeGraph(int n, vector<pair<int, int>> &prerequisites) {
        vector<list<int>> graph(n);
        for (auto p : prerequisites) graph[p.second].push_back(p.first);
        return graph;
    }
    bool findCircle(vector<list<int>> &graph, vector<bool> &visited, vector<bool> &onpath, stack<int> &s, int i) {
        if (visited[i]) return false;
        visited[i] = true;
        onpath[i] = true;
        for (int end : graph[i]) {
            if (onpath[end] || findCircle(graph, visited, onpath, s, end)) return true;
        }
        s.push(i);  // res.push_back(i);
        onpath[i] = false;
        return false;
    }
};



// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/17276/20-lines-c-bfs-dfs-solutions 
// same as the first solution, but use queue to store the nodes with indegree being 0
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<list<int>> graph = makeGraph(numCourses, prerequisites);
        vector<int> indegree = computeIndegree(graph, numCourses);
        vector<int> res;
        queue<int> q_zero;
        for (int i = 0; i < numCourses; i++) if (!indegree[i]) q_zero.push(i);
        
        for (int i = 0; i < numCourses; i++) { // find node one by one
            if (q_zero.empty()) return {};
            int zero = q_zero.front();
            q_zero.pop();
            res.push_back(zero);  
            for (int end : graph[zero]) {
                if (!--indegree[end]) q_zero.push(end);
            }
        }
        return res;
    }
private:
    vector<list<int>> makeGraph(int n, vector<pair<int, int>> &prerequisites) {
        vector<list<int>> graph(n);
        for (auto p : prerequisites) graph[p.second].push_back(p.first);
        return graph;
    }
    vector<int> computeIndegree(vector<list<int>> &graph, int n) {
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (int end : graph[i]) indegree[end]++;
        }
        return indegree;
    }
};