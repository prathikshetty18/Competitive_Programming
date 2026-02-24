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

void solve(vector<string> &grid, ll &n){

    vvll dp(n+1, vll(n+1, 0));

    dp[n-1][n-1] = (grid[n-1][n-1] != '*');

    for(ll i = n-1; i >= 0; i--){

        for(ll j = n-1; j >= 0; j--){
        
            if(i + 1 < n && grid[i][j] != '*' && grid[i+1][j] != '*') dp[i][j] = (dp[i][j] + dp[i+1][j]) % mod;
            if(j + 1 < n && grid[i][j] != '*' && grid[i][j+1] != '*') dp[i][j] = (dp[i][j] + dp[i][j+1]) % mod;
        }
    }

    cout << dp[0][0] << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n;
        
        cin >> n;

        vector<string> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

