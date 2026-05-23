using ll = long long;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> a(k,0) , b (k,0);
        for(int i=0;i<n;i++){
            int z = nums[i ] % k;
            for(int j=0;j<k;j++){
                int t1 = (z - j + k) %k;
                int t2 = (j - z + k) %k;
                int c = min(t1, t2);
                if(i % 2 == 0) a[j] = a[j] + c;
                else b[j] += c;
                
                
            }
        }

        ll ans = LLONG_MAX, x = LLONG_MAX, y = LLONG_MAX;
        int move =-1;
        for(int i=0;i<k;i++){
            if(b[i] < x){
                y = x;
                x = b[i];
                move = i;
                
            } else if ( b[i] < y) y = b[i];
            
            }

            for(int i=0;i<k;i++){
                ll maxi = 0;
                if(move != i) maxi = x;
                else maxi = y;
                ans = min(ans , a[i] + maxi);
            }
        
    
        return (int)ans;
        
        
    }
};