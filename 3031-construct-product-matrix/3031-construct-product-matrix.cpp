class Solution {
public:
using ll = long long;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m));

        vector<int> arr(n * m);
        for(int i=0;i<n;i++)
           for(int j=0;j<m;j++)
             arr[i*m + j]= grid[i][j];

        vector<int> res = productExceptSelf(arr);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans[i][j] = res[i * m + j] % 12345;

        return ans;
    }


    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix =1, suffix =1;
        vector<int> ans(n,0), pref(n,1), suff(n,1);
 
        for(int i=1;i<n;i++)
            pref[i] = (1LL * pref[i-1] * nums[i-1]) % 12345;
   
        for(int i=n-2;i>=0;i--)
            suff[i] = (1LL * suff[i+1] * nums[i+1]) % 12345;
     
        for(int i=0;i<n;i++)
            ans[i] = (1LL * suff[i] * pref[i]) % 12345;
        
        return ans;
    }

};