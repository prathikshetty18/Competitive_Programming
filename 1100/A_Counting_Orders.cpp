#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

ll mod = 1e9+7;

void solve(vector<ll> &a, vector<ll> &b, ll &n){

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ll ans = 1;

    for(ll i = n-1; i >= 0; i--){

        ll len = i + 1 - (upper_bound(a.begin(), a.end(), b[i]) - a.begin());

        ans = (ans*len) % mod;
    }

    cout << ans << nl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        vector<ll> a (n), b (n);

        for(ll i = 0; i < n; i++) cin >> a[i]; 
        for(ll i = 0; i < n; i++) cin >> b[i]; 

        solve(a, b, n);

        t--;
    }
}

