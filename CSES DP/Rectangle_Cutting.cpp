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

void solve(ll &n, ll &m){

    vvll dp(n+1, vll (m+1, 1e3+1));

    for(ll l = 1; l <= n; l++){
    
        for(ll b = 1; b <= m; b++){

            if(l == b){
                
                dp[l][b] = 0;
                continue;
            }
    
            for(ll i = 1; i <= l-1; i++){
            
                dp[l][b] = min(dp[l][b], 1 + dp[i][b] + dp[l-i][b]);
            }

            for(ll i = 1; i <= b-1; i++){
            
                dp[l][b] = min(dp[l][b], 1 + dp[l][i] + dp[l][b-i]);
            }
        }
    }

    cout << dp[n][m] << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, m;

        cin >> n >> m;

        solve(n, m);
    }
}

