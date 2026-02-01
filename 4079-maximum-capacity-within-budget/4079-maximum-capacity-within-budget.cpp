class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        vector<pair<int,int>> machines;
        int ans = 0;
        int n =capacity.size();
        for (int i = 0; i < n; i++) {
            machines.push_back({costs[i], capacity[i]});
        }
        sort(machines.begin(), machines.end());
        vector<int> prefMax(n);
        prefMax[0] = machines[0].second;
        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], machines[i].second);
        }
        for (int i = 0; i < n; i++) {
            if (machines[i].first < budget) {
                ans = max(ans, machines[i].second);
            }
        }
        for (int i = 0; i < n; i++) {
            int curr_cost = machines[i].first;
            int curr_capacity  = machines[i].second;

            if (curr_cost >= budget) continue;
            int cuur_cost = budget - curr_cost - 1;
            if (cuur_cost < 0) continue;


            int l = 0, h = i - 1;
            int idx = -1;

            while (l <= h) {
                int mid = l + (h - l) / 2;
                if (machines[mid].first <= cuur_cost) {
                    idx = mid;
                    l = mid + 1;
                } else {
                    h = mid - 1;
                }
            }

            if (idx != -1) {
                ans = max(ans, curr_capacity + prefMax[idx]);
            }
        }
        return ans;
    }
};