// beekarr sawaal ewwwwww
//ewwww ewww stinlky uess

#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    if(!(cin>>t)) return 0;
    
    
    
    
    while(t--){
        
        
        int n; cin>>n;
        if(n==1){ 
          cout<<1<<"\n"; continue;
        }
      
        vector<int> p(n+1);

    //psg vs abrca 2nite ucl clash
      //i hope barca wins tongiht amennn
        if(n%2==1){
          
            for(int i=1;i<=n;i++){
                int x = (2*i) % n;
                if(x==0) x = n;
                p[i] = x;
            }
          
        } else {
            int m = n/2;
            for(int i=1;i<=m;i++) p[i] = 2*i;
            for(int k=1;k<=m;k++) p[m+k] = 2*k - 1;
        }

//saolutione
      
        for(int i=1;i<=n;i++){
            cout<<p[i];
            if(i<n) cout<<' ';
        } cout<<"\n";
        
    }
    return 0;
}
