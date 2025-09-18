class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin() , events.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0, n = events.size(), solution = 0;

        int day = 1, maxDay  =0;
        for(auto &j : events)   maxDay = max(maxDay , j[1]);

            for(day = 1 ; day <= maxDay; day++){
                while(i<n && events[i][0] == day) {
                    pq.push(events[i][1]); i++;
                }
                while(!pq.empty() && pq.top() < day) pq.pop();
                    if(!pq.empty()){
                        pq.pop();
                        solution++;
                    }  
            }
         return solution;
    }
};