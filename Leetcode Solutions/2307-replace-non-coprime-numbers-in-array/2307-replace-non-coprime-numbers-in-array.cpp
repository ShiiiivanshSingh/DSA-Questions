class Solution {
public:
    int hcf( int a, int b){
        while(b!=0){
            int temp= a%b;
            a=b;
            b=temp;
        }
        return a;
    }
    int lcm(int a, int b){
        return (1LL *a*b)/hcf(a,b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> myau;
        for(int meow : nums){
            int current = meow;
            while(!myau.empty()){
                int top = myau.back();
                int hc = hcf(top, current);
                    if(hc == 1) break;
                myau.pop_back();
                current = lcm(top, current);
                }
            myau.push_back(current);
        }
        return myau;
    }
};