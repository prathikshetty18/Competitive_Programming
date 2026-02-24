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
ll mod_add(ll a, ll b, ll m = mod) { return ((a) + (b)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(vll &v, ll &n, ll &sum){

    vll dp(sum+1, 0);

    dp[0] = 1;
    
    // you choose all the coins of a particular index first as many times as you want and only then move to the next coin 
    // This ensures all unique ordering i.e 2 5 2 will never happen only 2 2 5 can occur
    
    for(ll i = 0; i < n; i++){  // 2D dp[ind][tar] and space optimisation is much more intuitive than this solution!! Though this solution somehow works lol by switching the loops in coin combinations 1
        
        for(ll tar = 1; tar <= sum; tar++){
        
            if(tar >= v[i]) dp[tar] = mod_add(dp[tar], dp[tar - v[i]]);
        }
    }

    cout << dp[sum] << nl;
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

