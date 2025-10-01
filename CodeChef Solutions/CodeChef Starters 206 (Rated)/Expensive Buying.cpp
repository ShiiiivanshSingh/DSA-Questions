#include <bits/stdc++.h>
#include<vector>
using namespace std;

int main() {
	// your code goes hereint 
	int t;
	cin>>t;
	while(t--){
    
	    int n,k;
	    cin >> n>>k;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++) cin>> arr[i];
	
	    sort(arr.begin(), arr.end(), greater<int>()); //rever saart
	    int sum = 0;
	    for(int i = 0;i<k;i++){
	        sum  +=arr[i];
	    }
	    cout << sum << endl;
	    
	}
	return 0;
}
