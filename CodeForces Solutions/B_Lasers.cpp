#include <bits/stdc++.h>
using namespace std;
int main(){

    int t;cin>>t;
    while(t--){

        int n,m; 
        long long x,y;
        cin>>n>>m>>x>>y;

        vector<long long> arr1(n), arr2(m);

        for(int i=0;i<n;i++) cin>>arr1[i];
        for(int i=0;i<m;i++) cin>>arr2[i];
        int uwu1 = upper_bound(arr1.begin(), arr1.end(), y-1) - arr1.begin();
        int uwu2 = upper_bound(arr2.begin(), arr2.end(), x-1) - arr2.begin();

        
        cout<<uwu1 + uwu2<<"\n";
    }
}