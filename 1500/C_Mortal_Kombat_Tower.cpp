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
#define vvvll vector<vector<vector<ll>>>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(vll &v, ll &n){

    ll cnt = 0;
    ll plr = 0;

    vvvll dp(n, vvll (2, vll (2)));

    dp[0][0][0] = 1e9;
    dp[0][0][1] = 1e9;
    dp[0][1][0] = v[0];
    dp[0][1][1] = 1e9;

    for(ll i = 1; i < n; i++){
    
        dp[i][0][0] = min(dp[i-1][1][0], dp[i-1][1][1]);
        dp[i][0][1] = dp[i-1][0][0];
        dp[i][1][0] = v[i] + min(dp[i-1][0][0], dp[i-1][0][1]);
        dp[i][1][1] = v[i] + dp[i-1][1][0];
    }

    cout << min({dp[n-1][0][0], dp[n-1][0][1], dp[n-1][1][0], dp[n-1][1][1]}) << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

