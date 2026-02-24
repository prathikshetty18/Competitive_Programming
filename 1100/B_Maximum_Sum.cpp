#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(vector<ll> &v, ll &n, ll &k){

    sort(v.begin(), v.end());

    vector<ll> pre (n+1);

    pre[0] = 0;

    // cout << pre[0] << sp;

    for(ll i = 1; i <= n; i++){

        pre[i] = v[i-1] + pre[i-1];
    }

    ll maxi = LLONG_MIN;

    for(ll m = 0; m <= k; m++){     // perform m minimum removals

        ll l = 2*m;
        ll r = n - (k-m);

        // cout << "m: " << m << " l: " << pre[l] << " r: " << pre[r] << nl;

        maxi = max(maxi, pre[r]-pre[l]);
    }

    cout << maxi << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, k;
        
        cin >> n >> k;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, k);

        t--;
    }
}

