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

ll f(ll i, ll j, vll &v, vll &pre, vvll &dp){

    if(i == j) return dp[i][i] = v[i];

    if(dp[i][j] != -1) return dp[i][j];

    ll mini = LLONG_MIN;

    // cout << "i: " << i << " j: " << j << nl;

    // cout << "(pre[j+1] - pre[i+1]): " << (pre[j+1] - pre[i+1]) << nl;
    // cout << "(pre[j] - pre[i]): " << (pre[j] - pre[i]) << nl;

    mini = max(mini, v[i] + (pre[j+1] - pre[i+1]) - f(i+1, j, v, pre, dp));
    mini = max(mini, v[j] + (pre[j] - pre[i]) - f(i, j-1, v, pre, dp));

    return dp[i][j] = mini;
}

void solve(vll &v, ll &n){

    vvll dp(n, vll (n, -1));
    vll pre(n+1, 0);

    for(ll i = 0; i < n; i++){
    
        // dp[i][i] = v[i];
        pre[i+1] = v[i] + pre[i];
    }

    // print(pre);

    // for(ll i = 0; i < n; i++){
    
    //     for(ll j = i+1; j < n; j++){
        
    //         dp[i][j] = min(dp[i][j], v[i] + (pre[j] - pre[i]) - dp[i+1][j]);
    //         dp[i][j] = min(dp[i][j], v[j] + (pre[j-1] - pre[i-1]) - dp[i+1][j]);
    //     }
    // }

    ll ans = f(0, n-1, v, pre, dp);

    cout << ans << nl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n;
        
        cin >> n;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

