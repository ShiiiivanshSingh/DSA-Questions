class Solution {
public:
    bool isprime(int n){
    if(n<2) return 0;
    for(int i=2; i * i<= n;i++) if(n%i==0) return 0;
    return 1;
    }

    vector<int> factors(int x) {
        vector<int> f;
        for (int p = 2; p * p <= x; p++) {
            if (x % p == 0) {
                f.push_back(p);
                while (x % p == 0) x /= p;
                
            }
        }

        if (x > 1) 
            f.push_back(x);
        return f;
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, vector<int>> mp;
        queue<int> q;
        vector<int> vis(n);

        q.push(0);
        vis[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int p : factors(nums[i]))  mp[p].push_back(i);
            

        }


        int step = 0;

        while (!q.empty()) {
            int tgt = q.size();

            while (tgt--) {
                int i = q.front();
                q.pop();

                if (i == n - 1) return step;

                if (i > 0 && !vis[i - 1]) {
                    vis[i - 1] = 1;
                    q.push(i - 1);
                }

                if (i + 1 < n && !vis[i + 1]) {
                    vis[i + 1] = 1;
                    q.push(i + 1);
                }

                if (mp.count(nums[i])) {
                    for (int j : mp[nums[i]]) {
                        if (!vis[j]) {
                            vis[j] = 1;
                            q.push(j);
                        }
                    }

                    mp.erase(nums[i]);
                }
            }

            step++;
        }

        return -1;
    }
};