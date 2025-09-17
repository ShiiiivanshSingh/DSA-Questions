#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n; //students at da school
    cin >> n;
    vector<int> a,b,c;
    for(int i =1 ;i<=n;i++){
        int x;
        cin >> x;
        if( x ==1) a.push_back(i);
        else if( x ==2) b.push_back(i);
        else c.push_back(i);
    }
    int final = min({a.size(), b.size(), c.size()});
    cout << final <<endl;
    for(int i = 0;i<final; i++){
        cout << a[i] <<  " "  << b[i] << " " << c[i]  << endl;
    }
}