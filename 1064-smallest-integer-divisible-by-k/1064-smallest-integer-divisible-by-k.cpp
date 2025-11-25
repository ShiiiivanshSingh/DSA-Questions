// my 400th question
// yippie
// ヾ(＠⌒ー⌒＠)ノ

using ll = long long;
class Solution {
public:
    int cd(int n) {
    return to_string(abs(n)).size();
    }

    int smallestRepunitDivByK(int k) {
              
       if(k % 2 == 0 || k % 5 == 0) return -1;
       int rem = 0;
    //    int k_count = cd(k);
    //    cout <<  k_count;
       for(int i = 0 ;i< k ; i++){
            rem = (rem * 10 + 1) % k;
            // cout << i+1 <<" gives rem -> " <<  rem<< endl;
            if(rem  == 0) return i + 1;
       }
 
        return -1;

    }
};