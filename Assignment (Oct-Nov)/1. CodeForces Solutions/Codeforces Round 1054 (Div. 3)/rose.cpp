#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        vector<int> cnt(n + 1, 0);
        for(int x : a) {
            cnt[x]++;
        }
        
        int need = 0;
        for(int i = 0; i < k; i++) {
            if(cnt[i] == 0) need++;
        }
        
        int bad = cnt[k];
        
        cout << max(need, bad) << "\n";
    }
    
    return 0;
}