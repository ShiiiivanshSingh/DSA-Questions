class Solution {
public:
    bool isFascinating(int n) {
        //ez sol1-> 
        // return n == 192 || n == 219 || n == 273 || n == 327; 
        set<char> st;      
        string s1 =to_string(n);
        string s2 =to_string(n * 2);
        string s3 =to_string(n * 3);

        string final = s1 + s2 + s3;
        // sol2->
        // for(auto &i : final){
        //     if(st.count(i) || i == '0') return 0;
        //     st.insert(i);
        // }
        // if(st.size() == 9) return 1;
        // else return 0;

        // sol3->
        sort(final.begin(),final.end());
        if(final =="123456789" )return 1;
        else return 0;
    }
};