#include<bits/stdc++.h>
using namespace std;
//myau hiiie stalker 
// achaaa haan

void naur(){
    int n;cin>>n;
    string s;cin>>s;
    vector<int> balance(n+1,0);


    for(int i=0;i<n;i++)    balance[i+1]=balance[i]+(s[i]=='a'?1:-1);
    if(balance[n]==0){
        cout<<0<<'\n';
        return;
    }


    int target=balance[n];
    map<int,int> last;


    last[0]=0;
    int minlen=-1; //shouldnt work insahllah or idk


    for(int j=1;j<=n;j++){
        int need=balance[j]-target;
        if(last.count(need)){
            int i=last[need];
            int len=j-i;
        // if(last.count(need)){
        //     int i=last[need];
        //     int len=j-i;


            if(i>0||j<n){
                if(minlen==-1||len<minlen)minlen=len;
            }
        }

        last[balance[j]]=j;
    }
    for(int r=1;r<n;r++){
        if(balance[r]==target){
            if(minlen==-1||r<minlen)    minlen=r;
            break;
        }
    }
    for(int l=n-1;l>0;l--){
        if(balance[l]==0){
            if(minlen==-1||(n-l)<minlen)minlen=n-l;
            break;
        }
    }
    int overall=n;
    last.clear();
    last[0]=0;
    for(int j=1;j<=n;j++){
        int need=balance[j]-target;
        if(last.count(need)){
            int i=last[need];
            overall=min(overall,j-i);
        }
        last[balance[j]]=j;
    }
    if(overall<n)cout<<overall<<'\n';
    else cout<<-1<<'\n'; //hehe
}
int main(){

    int t;cin>>t;
    while(t--)  naur();
}
