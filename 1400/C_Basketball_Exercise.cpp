#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

void solve(vll &v1, vll &v2, ll &n){

    // vvll dp (n, vll (2, 0));

    // dp[0][0] = v1[0];
    // dp[0][1] = v2[0];

    ll dp0 = v1[0];
    ll dp1 = v2[0];

    for(ll i = 1; i < n; i++){
    
        // dp[i][0] = max(v1[i] + dp[i-1][1], dp[i-1][0]);
        // dp[i][1] = max(v2[i] + dp[i-1][0], dp[i-1][1]);

        ll newdp0 = max(v1[i] + dp1, dp0);
        ll newdp1 = max(v2[i] + dp0, dp1);

        dp0 = newdp0;
        dp1 = newdp1;
    }

    cout << max(dp0, dp1) << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n;
        
        cin >> n;

        vll v1 (n), v2 (n);

        for(ll i = 0; i < n; i++) cin >> v1[i]; 
        for(ll i = 0; i < n; i++) cin >> v2[i]; 

        solve(v1, v2, n);
    }
}

