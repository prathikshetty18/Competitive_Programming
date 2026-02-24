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

void solve(vll &pag, vll &pri, ll &n, ll &bud){

    vvll dp(n+1, vll (bud+1, 0));

    for(ll tot = 0; tot <= bud; tot++){
    
        dp[0][tot] = (tot >= pri[0] ? pag[0] : 0);
    }

    for(ll i = 1; i < n; i++){
    
        for(ll tot = 0; tot <= bud; tot++){
        
            dp[i][tot] = dp[i-1][tot];

            if(tot >= pri[i]) dp[i][tot] = max(dp[i][tot], pag[i] + dp[i-1][tot - pri[i]]);
        }
    }

    cout << dp[n-1][bud] << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, bud;
        
        cin >> n >> bud;

        vll pri (n), pag(n);

        for(ll i = 0; i < n; i++) cin >> pri[i]; 
        for(ll i = 0; i < n; i++) cin >> pag[i]; 

        solve(pag, pri, n, bud);
    }
}

