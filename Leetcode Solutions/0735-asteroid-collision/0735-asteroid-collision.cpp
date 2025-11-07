class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       int n  =  asteroids.size();
       stack<int> st;
       vector<int> ans;

    for(int i   = 0 ; i< n ; i++){

        bool not_break =1;

       while(!st.empty()  && st.top()> 0 &&  asteroids[i]< 0 ){ 
            if(abs(st.top()) < abs(asteroids[i])){
                st.pop();
                continue;
            }
            else if ( abs(st.top()) ==  abs(asteroids[i]) ){
                st.pop();
            }
            not_break = 0;
            break;
        }
        if(not_break)  st.push(asteroids[i]);

 } 
        // bool baas = samesign(st.top(), asteroids[i]); 
        // if( st.top() + asteroids[i] == 0 )   st.pop();

        while(!st.empty() ){
            ans.push_back(st.top());
            st.pop();
        }
         reverse(ans.begin() , ans.end());
    return ans;
    }
    // bool samesign(int a , int b){
    //     bool diff = (a ^ b) < 0;
    //     if(diff ) return 0;
    //     else return 1;
    // }
};