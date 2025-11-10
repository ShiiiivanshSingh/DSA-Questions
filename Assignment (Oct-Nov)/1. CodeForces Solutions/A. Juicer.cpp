#include <iostream>
using namespace std;


int main(){
    int n,b,d;
    cin>>n>>b>>d;

    int x,w=0,ans=0;

    for(int i=0;i<n;i++){
        cin>>x;

        if(x<=b){
            w+=x;
            if(w > d){
                ans++;
                w=0;
            }
        }

    }

    cout<<ans;
}
