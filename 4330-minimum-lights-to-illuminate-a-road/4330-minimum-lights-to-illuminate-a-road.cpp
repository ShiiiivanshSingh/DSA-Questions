class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
                    int ans =0, pos =0;

        vector<int> reach(n , -1);
        for(int i=0;i<n; i++){
            if(lights[i] > 0){

                    reach[max(0,i-lights[i])] = max(reach[max(0,i-lights[i])], min(n-1,i+lights[i]));
                }}
        
        for(int i = 1; i < n; i++)
    if(reach[i-1] >= i) reach[i] = max(reach[i], reach[i-1]);
                    while(pos<n){
                        if(reach[pos] >= pos) pos = reach[pos] + 1;
                        else  {
                            ans++;
                            pos+=3;
                        }
            
        }
        return ans;
    }
};
        // while(i < n) {
            
        //     if(lights[i] > 0) i += lights[i] + 1;
        //     else if(i+2 < n && lights[i + 2] >= 2){
        //         i += lights[i + 2] + 3;
        //     }
        //     else if(i+1 < n && lights[i + 1] >= 1){
        //         i += lights[i + 1] + 2;
        //     }
        //     else {  
        //         extra++;
        //         i = i + 3;
                
        //     }
        // }
        //     return extra;