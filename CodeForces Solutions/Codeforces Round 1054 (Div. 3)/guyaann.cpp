#include <bits/stdc++.h>

using namespace std;
//achaaa

//myau

// hiiee




static long long mewo(const vector<long long> &arr, int maxDistinct, int maxLen){
    if(maxLen <= 0 || maxDistinct <= 0) return 0; //invliad


    const int n = (int)arr.size();


    unordered_map<long long, int> freq;
    freq.reserve(   (size_t)min(n, maxDistinct * 4) );


    int count = 0;
    long long answer = 0;
    int left = 0;
    for(int right = 0; right < n; right++){
        if(++freq[arr[right]] == 1) count++;
        while(count > maxDistinct){


            if( --freq[arr[left]] == 0){
                freq.erase(arr[left]);
                count--;
            }
            left++;


        }
        int len_left = right - maxLen + 1;
        int left_end = max(left, max(0, len_left));

        if(left_end <= right) answer += (   right - left_end + 1);
                }
    return answer;


}













int main(){

    int t; 
    if(!(cin >> t)) return 0;
    while(t--){
        int n, k, l, r; 
        cin >> n >> k >> l >> r;
        vector<long long> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];


        long long buh = mewo(a, k, r);
        long long guh = mewo(a, k, l - 1); //soory was wird names myua
        long long duh = mewo(a, k - 1, r); //who cares
        long long buhh = mewo(a, k - 1, l - 1); //who cares , me
        long long sol = (buh - guh) - (duh - buhh);
        cout << sol << "\n";
    }
    return 0;
} 