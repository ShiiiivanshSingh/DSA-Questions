#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 
int main(){
    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> a(n); //freid id
        vector<int> b(m); //cost
        for(int i=0;i<n;i++) cin>> a[i];
        for(int i=0;i<m;i++) cin>> b[i];
        
        sort(a.rbegin(), a.rend());
        long long ans =0;
        int k=0;
        for(int i=0;i<n;i++){
            int index = a[i] - 1;

            if(k<m && b[k] < b[index]) ans += b[k++];
            else ans += b[index];
        }
        cout << ans << "\n";
    }
}