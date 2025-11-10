class Solution {
public:
    bool zerohaikya(int num) {
        while (num > 0) {
            if (num % 10 == 0) return true;
            num /= 10;
        }return false;
    }

    vector<int> getNoZeroIntegers(int n) {
        vector<int> nyau;

    for(int mew=1;mew<n;mew++){
        for(int mew2=1;mew2<n;mew2++){
            if(mew + mew2 == n  && !zerohaikya(mew) && !zerohaikya(mew2)) return {mew, mew2};
            }}return {}; }};