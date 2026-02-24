#include <bits/stdc++.h>
using namespace std;

#define ll int
#define sp " "
#define nl "\n"
#define pb push_back
#define sz size
#define ff first
#define ss second
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(vll &v, ll &n, ll &m){

    vvll dp(n+1, vll (m+2, 0));

    for(ll end = 1; end <= m; end++){
    
        dp[0][end] = (v[0] == end || !v[0]);
    }

    // print(dp[0]);

    for(ll i = 1; i < n; i++){
    
        for(ll end = 1; end <= m; end++){

            if(v[i] != 0 && v[i] != end) continue;  // 0 such arrays possible 

            dp[i][end] = ((dp[i-1][end-1] + dp[i-1][end] ) % mod + dp[i-1][end+1]) % mod;
        }

        // print(dp[i]);
    }

    ll ans = 0;

    for(ll end = 1; end <= m; end++){
    
        ans = (ans + dp[n-1][end]) % mod;  
    }
    
    cout << ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, m;
        
        cin >> n >> m;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, m);
    }
}

