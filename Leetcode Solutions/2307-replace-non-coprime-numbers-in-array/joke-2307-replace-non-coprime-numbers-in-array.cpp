class Solution {
public:
    int hcf( int askhat, int sixvi){
        while(sixvi!=0){
            int sorryshiavnsh= askhat%sixvi;
            askhat=sixvi;
            sixvi=sorryshiavnsh;
        }
        return askhat;
    }
    int lcm(int askhat, int sixvi){
        return (1LL * askhat * sixvi)/hcf(askhat,sixvi);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> myau;
        for(int meow : nums){
            int chiwani = meow;
            while(!myau.empty()){
                int shistum = myau.back();
                int sorryaan = hcf(shistum, chiwani);
                    if(sorryaan == 1) break;
                myau.pop_back();
                chiwani = lcm(shistum, chiwani);
                }
            myau.push_back(chiwani);
        }
        return myau;
    }
};