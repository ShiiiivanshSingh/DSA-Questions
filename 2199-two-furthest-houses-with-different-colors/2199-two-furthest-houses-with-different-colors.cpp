class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int ans =0 ;
        int n=colors.size();
        // if ( colors.size() == 0)  return 0;


        for(int i = n-1; i>0 ; i--){
            if(colors[0] != colors[i]){ 
                ans = max(ans , i   );
                cout << " start se -> " << ans <<" -> " << n << " with "<<  n-i-1 << endl;
                break;
            }
        }

        for(int i = 0;i<n-1 ; i++){
            if(colors[n-1] != colors[i]){ 
                ans = max(ans , n-i - 1);
                cout << " last se -> " << ans <<" -> "<< n << " with "<<  n-1 << endl;
                break;
            }
        }
        return ans;
    }
};