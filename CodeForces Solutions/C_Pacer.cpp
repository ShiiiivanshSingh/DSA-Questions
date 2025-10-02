#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--){
        int n; long long m; cin>>n>>m;
        vector<long long> arr1(n+1), arr2(n+1);
        for(int i=0;i<n;i++) cin>>arr1[i]>>arr2[i];

        arr1[n] = m;
        arr2[n] = arr2[n-1];
        long long prev = 0, side = 0, ans = 0;
        for(int i=0;i<=n;i++){
            long long a1 = arr1[i] - prev;
            long long a2 = abs(arr2[i] - side);

            ans += (a1 + a2)/2;
            prev = arr1[i];
            side = arr2[i];
        }
        ans += m - prev;
        cout<<ans<<"\n";
    }
}



