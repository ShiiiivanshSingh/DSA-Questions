class Solution {
public:
    int n;
    
    bool isValid(long long x, vector<long long> power, int r, long long k) {
        vector<long long> diff(n + 1, 0);

        for(int i = 0; i < n; i++) {
            if(i > 0) diff[i] += diff[i - 1];
            
            power[i] += diff[i];

            if(power[i] < x) {
                long long need = x - power[i];
                if(need > k) return false;

                k -= need;

                int right = min(n, i + 2*r + 1);
                diff[i] += need;
                diff[right] -= need;
            }
        }

        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        n = stations.size();
        vector<long long> power(n + 1, 0);

        long long low = LLONG_MAX, high = LLONG_MIN;

        for(int i = 0; i < n; i++) {
            int left = max(0, i - r);
            int right = min(n, i + r + 1);
            power[left] += stations[i];
            power[right] -= stations[i];
        }

        for(int i = 1; i < n; i++)
            power[i] += power[i - 1];

        long long maxPowerVal = 0;
        for(long long val : power)
            maxPowerVal = max(maxPowerVal, val);

        low = 0;
        high = maxPowerVal + k;
        long long ans = 0;

        while(low <= high) {
            long long mid = (low + high) / 2;
            if(isValid(mid, power, r, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
