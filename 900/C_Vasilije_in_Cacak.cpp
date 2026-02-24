#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll n, ll k , ll x){


    ll mini = k * (k+1)/2;
    ll maxi = n * (n+1)/2 - (n-k) * (n-k+1)/2;

    if((x >= mini) && (x <= maxi)) cout << "YES\n";
    else cout << "NO\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, k, x;
        
        cin >> n >> k >> x;        

        solve(n, k, x);

        t--;
    }
}

