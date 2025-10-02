#include <bits/stdc++.h>
using namespace std;

int main(){

    int a; long long b;
    cin>>a>>b;

    vector<long long>meow(a);
    for(int i=0;i<a;i++) cin>>meow[i];

    sort(meow.begin(),meow.end());

    int w=0;
    int use=0;
    for(int i=a-1;i>=0;i--){
        long long need = b/meow[i]+1;
        if(use+need<=a){
            w++;
            use+=need;
        }else break;
    }
    cout<<w;
}
