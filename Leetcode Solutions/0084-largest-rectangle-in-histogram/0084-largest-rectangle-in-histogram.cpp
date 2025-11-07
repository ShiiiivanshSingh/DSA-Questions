class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // vector<int> test = heights;
        // int uw = test.size();
        // sort(test.begin() , test.end());

        int n  = heights.size();
        stack<int> st;
        int maxarea = 0 ;
        if( n == 1 ) return heights[0];
    
    
    
    
        for(int i = 0  ; i<= n ; i++){
 
        int h;
        if( i == n) h = 0 ;
        else h   = heights[i];


          while(!st.empty() && h < heights[st.top()]){
            int hi = heights[st.top()];
            st.pop();
            int wi;
                if(st.empty()) wi = i;
                else wi = i - st.top() - 1;


            maxarea = max(maxarea , hi * wi);
            // st.pop();
            
          }
          st.push(i);
         }

return maxarea;
    }
};





        // for(int i = n -1 ; i>0 ; i--){
        //     int ans = test[n-1];
        //     maxarea = max(maxarea , ans);
        //     if(heights[i] <= heights[ i -1 ]){
        //         ans   = 2 * heights[ i];
        //         maxarea = max(maxarea , ans);
        //     }
        // }