class TaskManager {
public:
    map<int, int> taskuserRelation;
    map<int, int> taskpriorRelation;
    set<pair<int, int>> s;
    TaskManager(vector<vector<int>>& tasks) {
        for (auto it : tasks) {
            int task = it[1];
            int user = it[0];
            int prior = it[2];
            taskuserRelation[task] = user;
            taskpriorRelation[task] = prior;
            s.insert({prior, task});
        }
    }

    void add(int userId, int taskId, int priority) {
        s.insert({priority, taskId});
        taskuserRelation[taskId] = userId;
        taskpriorRelation[taskId] = priority;
    }

    void edit(int taskId, int newPriority) {
        int oldPrior = taskpriorRelation[taskId];
        s.erase({oldPrior, taskId});
        s.insert({newPriority, taskId});
        taskpriorRelation[taskId]=newPriority;
    }

    void rmv(int taskId) {
        int oldPrior = taskpriorRelation[taskId];
        s.erase({oldPrior, taskId});
        taskpriorRelation.erase(taskId);
        taskuserRelation.erase(taskId);
    }

    int execTop() {
        if (s.empty())
            return -1;
        auto it = prev(s.end());
        int taskId = it->second;
        int prior = it->first;
        int userId = taskuserRelation[taskId];
        s.erase(it);
        return userId;
    }
};
