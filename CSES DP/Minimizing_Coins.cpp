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

ll f(ll tar, vll &v, vll &dp, ll &n){

    if(tar == 0) return 0;

    if(dp[tar] != -1) return dp[tar];

    ll mini = 1e9;

    for(ll i = 0; i < n; i++){
    
        if(tar >= v[i]) mini = min(mini, 1 + f(tar - v[i], v, dp, n));
    }

    return dp[tar] = mini;
}

void solve(vll &v, ll &n, ll &sum){

    vll dp(sum+1, 1e9);

    // ll mini = f(tar, v, dp, n);

    dp[0] = 0;

    for(ll tar = 0; tar <= sum; tar++){
    
        for(ll i = 0; i < n; i++){
        
            if(tar >= v[i]) dp[tar] = min(dp[tar], 1 + dp[tar-v[i]]);
        }
    }

    cout << (dp[sum] == 1e9 ? -1 : dp[sum])  << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, sum;
        
        cin >> n >> sum;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, sum);
    }
}

