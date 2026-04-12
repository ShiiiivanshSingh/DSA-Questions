class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int ans =0;
        for(int x: nums){
            if(x == 0 && digit == 0)
                ans++;
             
            while(x>0){
                if(x%10 == digit) ans++;
                x /=10;
            }
        }
        return ans;
    }
};
        

    //    map<int, int> mp;
    //    int ans =0;
    //    for(auto i : nums){
    //     if(i==0) mp[0]++;
    //     while(i >0){
    //         mp[i % 10]++;
    //         i /=10;
    //     }
    //    }
    //    return mp[digit]; 
