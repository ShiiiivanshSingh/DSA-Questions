// Last updated: 10/15/2026, 12:41:05 PM
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        
        vector<string> ans(m, string(n, '#'));
        int i=0,j =0;
        ans[i][j] = '.'; //trav


        
        while(i<m-1 || j<n-1){
            if(j<n-1 && (i == m-1 || (i+j) % 2 ==0)) j++;
            else i++;
           ans[i][j] = '.'; 
        }

        
        return ans;
        
    }
};