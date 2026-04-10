using ll = long long;
// Z-Algorithm less goooo
class Solution {
public:

vector<int> zalgo(string &s){
    int n = s.size();
    vector<int> z(n,0);
    int left=0, right =0;
    for(int i=1;i<n;i++){
        if(i <= right) z[i] = min(right - i + 1, z[i- left]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
//      linear time pattern srching
        
        if(i + z[i] - 1 > right){
            left = i;
            right = i+ z[i] -1;

        }
    }
    return z;
}

    long long sumScores(string s) {
        vector<int> z = zalgo(s);
        int k = z.size();
        ll ans = s.size();
        for(int i = 0 ; i<k;i++)    ans+= z[i];
        
        return ans;
    }
};