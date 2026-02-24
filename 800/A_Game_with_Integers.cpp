#include <bits/stdc++.h>
using namespace std;

void solve(int n){

    if(n % 3 == 0) cout << "Second\n";
    else cout << "First\n";
}

int main(){

    int t;
    cin >> t;

    while(t > 0){

       int n;
       cin >> n;

       solve(n);

        t--;
    }
}

// if n is not divisible by 3 - vanya wins as by adding or subbing 1 you can always get a number div by 3
// if n is divisible by 3 - vova wins as whatever change vanya makes, vova can reverse it to make it div by 3 again before vanya's turn
