#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a,b,c;
        cin >> a >> b >> c;

        long long A = 0, B = 0, C = 0;

        if(a <= max(b,c)) A = max(b,c) - a + 1;
        if(b <= max(a,c)) B = max(a,c) - b + 1;
        if(c <= max(a,b)) C = max(a,b) - c + 1;

        cout << A << " " << B << " " << C << "\n";
    }
}
