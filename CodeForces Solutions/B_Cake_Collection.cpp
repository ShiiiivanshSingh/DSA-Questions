#include<bits/stdc++.h>
using namespace std;
int main(){
    int t ; cin >> t;
    while(t--){
        int n; long long m;
    cin >> n >> m;

    long long   ans = 0;

        vector<long long    > cake(n);
        
        for(int i= 0 ; i< n ; i++) cin >> cake[i];
        sort(cake.rbegin(), cake.rend());

        for(int i =0 ; i< n && i < m; i++){
            ans += (m  - i )*cake[i];
        }

        cout << ans << endl;
    }
}