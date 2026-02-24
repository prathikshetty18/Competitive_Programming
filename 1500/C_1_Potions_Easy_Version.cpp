#include <bits/stdc++.h>
using namespace std;

/*
  ███████╗██╗  ██╗███████╗████████╗████████╗██╗   ██╗
  ██╔════╝██║  ██║██╔════╝╚══██╔══╝╚══██╔══╝╚██╗ ██╔╝
  ███████╗███████║█████╗     ██║      ██║    ╚████╔╝ 
  ╚════██║██╔══██║██╔══╝     ██║      ██║     ╚██╔╝  
  ███████║██║  ██║███████╗   ██║      ██║      ██║   
  ╚══════╝╚═╝  ╚═╝╚══════╝   ╚═╝      ╚═╝      ╚═╝   
*/

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

void solve(vll &v, ll &n){

    vvll dp (n+1, vll (n+1, -1e10));

    dp[0][0] = 0;

    // cout << "0: ";

    // print(dp[0]);

    for(ll i = 1; i <= n; i++){

        dp[i][0] = 0;

        for(ll j = 1; j <= i; j++){

            dp[i][j] = dp[i-1][j];
            
            if(dp[i-1][j-1] >= 0) dp[i][j] = max(dp[i][j], v[i-1] + dp[i-1][j-1]);
        }

        // cout << i << ": ";

        // print(dp[i]);
    }

    ll ans = 0;

    for(ll i = 1; i <= n; i++){
    
        if(dp[n][i] >= 0) ans = max(ans, i);
    }

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

