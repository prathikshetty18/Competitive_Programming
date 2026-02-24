#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll n, ll k){

    if(n % 2 == 0) cout << "YES\n";
    else if(k % 2 == 0) cout << "NO\n";
    else cout << "YES\n";
}

int main(){

    int t;
    cin >> t;

    while(t > 0){

        ll n, k;

        cin >> n >> k;

        solve(n, k);

        t--;
    }
}