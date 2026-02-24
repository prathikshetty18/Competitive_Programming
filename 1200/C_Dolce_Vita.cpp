#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << "-";
#define mod 1000000007

void solve(vector<ll> &v, ll &n, ll &b){

    sort(all(v));

    for(ll i = 1; i < n; i++){

        v[i] += v[i-1];
    }

    ll tot = 0;

    for(ll i = 0; i < n; i++){
    
        ll diff = 0;
        
        if(b >= v[i]) diff = ((b-v[i])/(i+1)) + 1;
        
        // cout << "b: " << b << " v[i]: " << v[i] << " diff: " << diff << nl;

        if(diff > 0) tot += diff;
    }
    
    cout << tot << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, b;
        
        cin >> n >> b;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, b);
    }
}

