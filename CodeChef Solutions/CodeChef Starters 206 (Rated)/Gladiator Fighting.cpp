#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;cin >> t;
    while(t--){
        int n;
        cin >> n;


        if(n==2){
            cout << 0 << " " << 0 << endl;


        } else {
            int min = n-2;
            int max = (n-1)*(n-2)/2;

          
            cout << min << " " << max << endl;
        }
    }
    return 0;
}
