#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//mw reference less go
 
int main(){
    int t; cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<" "<<0<<"\n";
            continue;
        } //fin


        long long val = llabs(a-b);
        long long rem = a % val;
        long long move = min(rem, val - rem);

        
        cout<<val <<" "<< move<<"\n";
    }
    return 0;
}