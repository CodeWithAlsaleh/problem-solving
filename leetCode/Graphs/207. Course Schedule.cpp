// Detect cycles in a Directed Graph
class Solution {
    bool dfs(int node, vector<vector<int>> &graph, vector<int> &curVis, vector<int> &vis) {
        vis[node] = 1;
        curVis[node] = 1;

        for(auto &it : graph[node]) {
            if(curVis[it])
             return true;
            
            if(!vis[it] and dfs(it, graph, curVis, vis))
             return true;
        }

        // U have to do this in order to remove the finshed node from the current stack
        curVis[node] = 0;
    
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> curVis(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for(auto &it : prerequisites)
            graph[it[1]].push_back(it[0]);

        for(int i = 0; i < numCourses; ++i) {
            if(!vis[i] and dfs(i, graph, curVis, vis))
              return false;
        }

        return true;
    }
};
