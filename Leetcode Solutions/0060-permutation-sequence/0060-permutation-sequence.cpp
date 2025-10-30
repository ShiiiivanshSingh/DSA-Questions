class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> uga;
        vector<int> fact(n+1,1);
        for(int i=1;i<=n;i++) uga.push_back(i);
        for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i;

        k=k-1; //:(
        string myau = ""; 

    for(int i=n;i>0;i--){
        int index = k/fact[i-1];
        myau = myau + to_string(uga[index]);
        uga.erase(uga.begin() + index);
        k=k%fact[i-1];
        }
        return myau;
    }
};