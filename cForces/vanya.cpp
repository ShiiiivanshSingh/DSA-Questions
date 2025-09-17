#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int total = 0, i = 1;

    while(1){
        int op = i * (i+1) / 2;
        if(total + op > n) break;
        total += op;
        i++;
    }
    cout << i -1 << endl;
    return 0;
}