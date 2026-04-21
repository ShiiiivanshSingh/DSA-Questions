class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> arr;
        vector<int> fact(n+1,1);
        for(int i=1;i<=n;i++) arr.push_back(i);
        for(int i=1;i<=n;i++) fact[i]=fact[i-1] * i;

        k--;
        string ans = ""; 

    for(int i=n;i>0;i--){
        int index = k / fact[i-1];
        ans += to_string(arr[index]);
        arr.erase(arr.begin() + index);
        k = k % fact[i-1];
    }
    return ans;
    }
};