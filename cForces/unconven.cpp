#include <bits/stdc++.h>
using namespace std;

int main(){
    int testcase;
    cin >> testcase;
    
    while(testcase--){
        int n;
        cin >> n;
        vector<long long> a(n);
        
        for(int i = 0; i < n; i++) cin >> a[i];
        
        sort(a.begin(), a.end());
        



        long long meow = 0;
  
        for(int i = 0; i < n; i += 2)    meow = max(meow, a[i + 1] - a[i]);
        
        
        cout << meow << "\n";
    }
    
    return 0;
}