using ll = long long;
ll mod = 7 + 1e9;
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
       int n = nums.size();
       ll sum =0;
       sort(nums.begin() , nums.end()); 
        vector<ll> power(n);
        power[0] = 1;
        for(int i = 1; i < n; i++) power[i] = (power[i-1] * 2) % mod;
        for(int i=0;i<n;i++){
            ll a = power[i]; // min
            ll b = power[n - i -1]; // max power
            sum += nums[i]* (a - b);
            sum = sum % mod;
        }
    return (sum + mod) % mod;
    }
};

// using ll = long long;
// class Solution {
// public:
// ll mod = 1e9 + 7;
//     int sumSubseqWidths(vector<int>& nums) {
//         ll n = nums.size();
//         if(n ==1 ) return 0;
//         ll sum =0;
//         ll ans =0;
//         vector<ll> power(n);
//         power[0] = 1;
//         for(int i = 1; i < n; i++)
//             power[i] = (power[i-1] * 2) % mod;
//         //vector<ll> sums;
//         // vector<ll> temp = nums;
//         sort(nums.begin(), nums.end());
//         // arr of size n will hive 2^n -1 non empty subsequences myau
//         for(int i=0;i<n;i++){
//             ll a = power[i]; // min
//             ll b = power[n - i -1]; // max power
//             sum += nums[i]* (a - b);
//             sum =ans % mod;
//         }
//         // ll n = arr.size();
//         // for(ll i=0;i<n;i++){
//         //     for(ll j=i;j<n; j++){
//         //         sum += (nums[j] - nums[i]) * pow(2, j - i -1);
//         //     }
//         // }
//         return (sum + mod) % mod;

//         // for (ll mask = 0; mask < (1 << n); mask++) {
//         //     for (ll i = 0; i < n; i++) {
//         //         if (mask & (1 << i))
//         //             cout << nums[i] << " ";
//         //     }
//         //     cout << endl << endl;
//         // }
        
        
//     }
// };