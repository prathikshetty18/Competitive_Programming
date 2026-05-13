#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;    // find_by_order(x) -> Elements less than x, order_of_key(x) -> xth smallest element

#define ll long long
#define ld long double
#define sp " "
#define nl "\n"
#define pb push_back
#define sz size
#define ff first
#define ss second
#define vll vector<ll>
#define vvll vector<vll>
#define vvvll vector<vvll>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(vll &v, ll &n){

    vll dp(n+1, 0); // shift indexes by 1 for dp
    dp[0] = 1;  // no elements -> valid sequence (base case)

    for(ll i = 0; i < n; i++){ 
    
        if(dp[i] && ((i + 1 + v[i]) <= n)) dp[i + 1 + v[i]] = 1;     // i is left position -> if there is solution till v[i-1] i.e dp[i]
        if((i - v[i]) >= 0) dp[i + 1] = max(dp[i + 1], dp[i - v[i]]);    // i is right position
    }

    cout << (dp[n] ? "YES" : "NO") << nl;

    // OR without right shifting

    // map<ll, ll> dp;
    // dp[-1] = 1;

    // for(ll i = 0; i < n; i++){ 
    
    //     if(dp[i-1] && ((i + v[i]) < n)) dp[i + v[i]] = 1;     // i is left position -> if there is solution till v[i-1] i.e dp[i]
    //     if((i - v[i] - 1) >= -1) dp[i] = max(dp[i], dp[i - v[i] - 1]);    // i is right position
    // }

    // cout << (dp[n-1] ? "YES" : "NO") << nl;
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

