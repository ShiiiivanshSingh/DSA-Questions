class Solution {
public:

    int dfs(int i,string cur,vector<string>& arr){

        int ans=cur.size();

        for(int j=i;j<arr.size();j++){

            string t=cur+arr[j];
            vector<int> f(26,0);
            bool ok=true;

            for(char c:t){
                if(++f[c-'a']>1){
                    ok=false;
                    break;
                }
            }

            if(ok)
                ans=max(ans,dfs(j+1,t,arr));
        }

        return ans;
    }

    int maxLength(vector<string>& arr) {
        return dfs(0,"",arr);
    }
};