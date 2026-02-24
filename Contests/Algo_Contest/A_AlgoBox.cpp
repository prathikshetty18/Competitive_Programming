#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(vector<ll> &v, ll &n){

    sort(v.begin(), v.end());

    ll l = min(v[0], v[1]);
    ll b = min(v[2], v[3]);

    cout << l * b << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n = 4;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;
    }
}

