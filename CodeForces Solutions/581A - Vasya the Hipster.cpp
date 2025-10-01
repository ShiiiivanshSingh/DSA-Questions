    #include <bits/stdc++.h>
    using namespace std;
     
     //sup hippie
     
    int main(){
        int a, b;
        cin >> a >> b;
        int dif = min(a, b);
        int same = abs(a - b) / 2;
        cout << dif<< " " << same;
    }
