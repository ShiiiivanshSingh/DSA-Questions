class Solution {
public:

    bool ok(string s){
        int f[26]={0};

        for(char c:s){
            f[c-'a']++;
            if(f[c-'a']>1) return false;
        }

        return true;
    }

    int maxLength(vector<string>& arr) {

        int n=arr.size();
        int ans=0;

        for(int m=0;   m<(1<<n)  ;m++){

            string s="";

            for(int i=0;i<n;i++){
                if(m   & (1<<i)){
                    s +=arr[i];
                }
            }

            if(ok(s)){
                ans=max (ans,  ( int)s.size()  );
            }
        }

        return ans;
    }
};