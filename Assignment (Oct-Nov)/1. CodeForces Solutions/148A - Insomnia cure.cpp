#include <bits/stdc++.h>
using namespace std;

int main(){

    int  pan,tail,heel,mom,dragon;
    cin >> pan >> tail>> heel >> mom >> dragon;

//Every l-th dragon got his tail shut into the balcony door. Every m-th dragon got his paws trampled with sharp heels. Finally, she threatened every n-th dragon to call her mom, and he withdrew in panic.

// fiona hellloo???


    int fiona = 0;


    for(int i = 0; i < dragon; i++){
        if(i % pan == 0 || i % tail == 0 || i % heel == 0 || i % mom == 0) fiona++;
    }

    cout<< fiona;
}
