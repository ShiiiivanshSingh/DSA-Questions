// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     for (int tt = 0; tt < t; tt++) {

// hiieieee myau myauuu 

#include <bits/stdc++.h>
using namespace std;

long long myau(int n, vector<int>& a, vector<int>& b) {
    vector<int> mino(n+1), maxo(n+1), smin(n+2, INT_MAX), smax(n+2, INT_MIN);




    mino[1]=maxo[1]=a[1];





    for(int i=2;i<=n;i++) mino[i]=min(mino[i-1],a[i]),maxo[i]=max(maxo[i-1],a[i]);


    for(int i=n;i>=1;i--) smin[i]=min(smin[i+1],b[i]),smax[i]=max(smax[i+1],b[i]);


    vector<pair<int,int>> achaaaa_haii;

    for(int i=1;i<=n;i++) achaaaa_haii.push_back({max(maxo[i],smax[i]),min(mino[i],smin[i])});


    sort(achaaaa_haii.begin(),achaaaa_haii.end());




    long long ans=0;int x=0,p=0,m=2*n;

    for(int i=1;i<=m;i++){
        while(p<achaaaa_haii.size()&&achaaaa_haii[p].first<=i)
            x=max(x,achaaaa_haii[p++].second);
        
        
            ans+=min(i,x);
    }

    return ans;
}

int main(){
  

    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        vector<int>a(n+1),b(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];



        cout<<myau(n,a,b)<<'\n';
    }
}





//         }
//         cout << ans << '\n';
//     }
// }

