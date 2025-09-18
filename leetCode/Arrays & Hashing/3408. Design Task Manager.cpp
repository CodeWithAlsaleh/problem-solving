class TaskManager {
    // [taksId , [userId , priority]] key-value pair 
    unordered_map<int,pair<int,int>> tasksGroup;

    // [priority , taskId]
    set<pair<int,int>> st;
public:
    TaskManager(vector<vector<int>>& tasks) {
       for(int i = 0 ; i < tasks.size() ; ++i)
       {
            auto task = tasks[i];

            st.insert(make_pair(task[2] , task[1]));
            tasksGroup[task[1]] = make_pair(task[0] , task[2]);
       }
    }
    
    void add(int userId, int taskId, int priority) {
        st.insert(make_pair(priority , taskId));
        tasksGroup[taskId] = make_pair(userId , priority);
    }
    
    void edit(int taskId, int newPriority) {
        auto p = tasksGroup[taskId];
        rmv(taskId);
        
        st.insert(make_pair(newPriority , taskId));
        tasksGroup[taskId] = make_pair(p.first , newPriority);
    }
    
    void rmv(int taskId) {
        auto p = tasksGroup[taskId];
        tasksGroup.erase(taskId);
        st.erase(make_pair(p.second , taskId));
    }
    
    int execTop() {

        if(st.empty())
         return -1;

        auto p = *st.rbegin();
        int ans = tasksGroup[p.second].first;

        // Remove task
        rmv(p.second);

        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
