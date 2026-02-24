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

    map<ll, ll> cnt;
    
    ll maxi = 0;
    
    for(ll i = 0; i < n; i++){
        
        cnt[v[i]]++;
        maxi = max(maxi, v[i]);
    }
    
    vector<ll> dp (maxi+1, 0);

    dp[0] = 0;
    dp[1] = cnt[1];

    for(ll i = 2; i <= maxi; i++){
    
        // for i >= 2

        // don't use i

        ll donttake = dp[i-1];

        // use i 

        ll take = cnt[i]*i + dp[i-2];

        dp[i] = max(take, donttake);
    }

    cout << dp[maxi] << nl;
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


