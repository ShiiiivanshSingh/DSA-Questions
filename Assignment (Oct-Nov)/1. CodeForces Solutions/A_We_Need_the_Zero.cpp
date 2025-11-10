#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//mw reference less go
 
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        int x=0;
        for(int i=0;i<n;i++){

             cin>> arr[i];
             x ^= arr[i];
        }
        if(n%2 == 0){
            if(x == 0) cout << 0 << "\n";
            else cout << -1 << "\n";
        } else {
            cout << x << "\n";
        }

    }
    return 0;
}