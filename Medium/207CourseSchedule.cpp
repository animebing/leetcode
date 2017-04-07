// make a directed graph about courses, if there is a circle, then it is impossible to finish the course 
// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/17273/18-22-lines-c-bfs-dfs-solutions
// dfs solution. ATTENTION: the graph is possible to be unconnected
// we should maintain two bool vectors, "visited" to record which nodes have been visited until now. "onpath" to record which nodes have been
// visited in current search path, so every time when we begin searching from a new node, we need to reset "onpath"
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph = makeGraph(numCourses, prerequisites);
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && findCircle(graph, i, visited, onpath)) return false; 
        }
        return true;
    }
private:
    vector<vector<int>> makeGraph(int n, vector<pair<int, int>> &pre) {
        vector<vector<int>> graph(n);
        for (auto p : pre) graph[p.second].push_back(p.first);   // ---- graph[p.first].push_back(p.second) is also okay
        return graph;
    }
    bool findCircle(vector<vector<int>> &graph, int i, vector<bool> &visited, vector<bool> &onpath) {
        if (visited[i]) return false;
        visited[i] = true;
        onpath[i] = true;
        for (int next : graph[i]) 
            if (onpath[next] || findCircle(graph, next, visited, onpath)) return true;
        
        onpath[i] = false;
        return false;
    } 
};



// based on the solution of jianchao.li.fighter, https://discuss.leetcode.com/topic/17273/18-22-lines-c-bfs-dfs-solutions
// bfs solution
// compute the indegree for each node in the graph, then find node whose indegree is 0, if we can't find one, then there must be a circle
// if find one, discard the node and all edges starting from this node, which is equivalent to decrease the indegree of nodes who starting 
// from this node
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph = makeGraph(numCourses, prerequisites);
        vector<int> indegree = computeIndegree(graph, numCourses);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) 
                if (!indegree[j]) break;
            if (j == numCourses) return false;
            indegree[j] = -1;
            for (int next : graph[j]) indegree[next]--;
        }
        return true;
    }
private:
    vector<vector<int>> makeGraph(int n, vector<pair<int, int>> &pre) {
        vector<vector<int>> graph(n);
        for (auto p : pre) graph[p.second].push_back(p.first);
        return graph;
    }
    vector<int> computeIndegree(vector<vector<int>> &graph, int n) {
        vector<int> res(n, 0);
        for (auto edges : graph) 
            for (auto end : edges) res[end]++; 
        return res;
    }
};