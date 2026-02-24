#include <bits/stdc++.h>
using namespace std;

void solve(int n, int k){

    if(n % k != 0 || k > n){

        cout << 1 << endl << n << endl;
    }
    else{

        cout << 2 << endl << 1 << " " << n-1 << endl;
    }

}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        int x, k;

        cin >> x >> k;

        solve(x, k);

        t--;
    }
}