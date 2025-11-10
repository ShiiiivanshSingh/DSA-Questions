#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int ras = n%3;
        if(ras ==0) cout<<0<<'\n';
        else cout<<   3-ras <<'\n';
    }
}
