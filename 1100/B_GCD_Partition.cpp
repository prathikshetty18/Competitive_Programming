#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;


void solve(vector<ll> &v, ll &n){

    ll ans = LLONG_MIN;

    vector<ll> pre (n+1);

    pre[0] = 0;

    for(ll i = 0; i < n; i++){

        pre[i+1] = v[i] + pre[i];
    }

    ll maxi = LLONG_MIN;

    for(ll i = 0; i < n-1; i++){

        // cout << "pre[i+1]: " << pre[i+1] << " rest: " << pre[n] - pre[i+1] << " maxi: " << maxi << nl;

        maxi = max(maxi, gcd(pre[i+1], pre[n] - pre[i+1]));
    }

    cout << maxi << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;
    }
}

