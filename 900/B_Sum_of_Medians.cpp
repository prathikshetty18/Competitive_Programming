#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<ll> &v, ll n, ll k){

    // k arrays of size n

    ll ind = n/2 + (n%2 != 0) - 1;

    // cout << "ind: " << ind << endl;

    ll ans = 0;

    ll skip = (n*k - k * ind)/k;

    for(int i = k * ind; i < n * k; i = i + skip){

        ans += v[i];
    }

    cout << ans << endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, k;
        
        cin >> n >> k;

        vector<ll> v (n*k);

        for(int i = 0; i < n*k; i++) cin >> v[i]; 

        solve(v, n, k);

        t--;
    }
}

