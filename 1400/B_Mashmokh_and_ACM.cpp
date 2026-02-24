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

void solve(ll &n, ll &k){

    vvll dp (k+1, vll (n+1, 0));

    for(ll i = 1; i <= n; i++) dp[1][i] = 1;

    for(ll l = 1; l < k; l++){

        for(ll i = 1; i <= n; i++){

            for(ll j = i; j <= n; j += i){

                dp[l+1][j] = mod_add(dp[l+1][j], dp[l][i]);
            }
        }
    }

    ll tot = 0;

    for(ll i = 1; i <= n; i++){

        tot = mod_add(tot, dp[k][i]);
    }

    cout << tot << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, k;
        
        cin >> n >> k;

        solve(n, k);
    }
}

