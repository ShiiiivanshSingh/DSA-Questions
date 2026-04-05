class Solution {
public:
    int mirrorFrequency(string s) {
        int ans =0;
        vector<int> arr(128, 0);
        vector<bool> arr2(128, 0);
        for(char i : s) arr[i]++;

        for(char c: s){
            char a;

            if(arr2[c]) continue;

            if(isalpha(c))  a = 'a' + ('z' - c);
            else    a = '0' + ('9' - c);
            
            ans += abs(arr[c] - arr[a]);
            arr2[c] = arr2[a] = 1;
        }
        return ans;     
    }
};