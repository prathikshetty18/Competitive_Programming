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

vector<vector<long long>>  dp(1e6+1, vector<long long> (2, 0));

void solve(ll &n){

    if(dp[n][0] != 0 && dp[n][1] != 0){

        cout << (dp[n][0] + dp[n][1]) % mod << nl;
        return;
    }

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(ll i = 2; i <= n; i++){
    
        dp[i][0] = ((4 * dp[i-1][0]) % mod + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i-1][0] + (2 * dp[i-1][1]) % mod ) % mod;
    }

    cout << (dp[n][0] + dp[n][1]) % mod << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        solve(n);
    }
}

