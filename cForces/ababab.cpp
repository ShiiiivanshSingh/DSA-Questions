// https://codeforces.com/contest/2149/problem/D

#include <bits/stdc++.h>
using namespace std;
//myau this question  is D. A n B

static long long meow(const string &s, char c){

    vector<int> buh;


    buh.reserve(s.size());
    for(int i = 0; i < (int)s.size(); i++) if(s[i] == c) buh.push_back(i);
    int k = (int)buh.size();


    if(k <= 1) return 0;

    vector<long long> shift(k);

    for(int i = 0; i < k; i++) shift[i] = (long long)buh[i] - i;


    nth_element(shift.begin(), shift.begin() + k/2, shift.end());


    long long midd = shift[k/2];
    long long sol = 0;


    for(int i = 0; i < k; i++) sol += llabs(shift[i] - midd);
    return sol;
}








int main(){

    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        int n;
        string s;
        cin >> n;
        cin >> s;



        long long sol = min(meow(s, 'a'), meow(s, 'b'));


        cout << sol << "\n";
    }
    return 0;

}
