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

void solve(vll &v, ll &n){

    vll dp (n+1, 1);
    ll maxi = 1;

    for(ll i = 1; i <= n; i++){

        // cout << "i: " << i << nl;
    
        for(ll j = 2*i; j <= n; j += i){

            // cout << j << sp;
        
            if(v[j] > v[i] && dp[i] + 1 > dp[j]){

                dp[j] = dp[i] + 1;
                maxi = max(maxi, dp[j]);
            }
        }

        // cout << nl;
    }

    cout << maxi << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vll v (n+1);

        for(ll i = 1; i <= n; i++){
            
            cin >> v[i]; 
        }

        solve(v, n);
    }
}

