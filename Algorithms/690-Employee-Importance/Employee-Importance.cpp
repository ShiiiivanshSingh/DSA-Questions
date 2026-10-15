/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*> mp;
        for (auto e : employees) mp[e->id] = e;
        int total = 0;
        queue<int> q;
        q.push(id);
        
        while (!q.empty()) {
            int cur=q.front();
            q.pop();
            Employee*  e = mp[cur];
            total += e->importance;
            for (int s : e->subordinates) q.push(s);
        }
        return total;
    }
};