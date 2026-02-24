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

    vll dp;     // {+ mid, + end, - mid, - end}

    if(v[0] > 0) dp = {0, 1, 0, 0};
    else dp = {0, 0, 0, 1};

    for(ll i = 1; i < n; i++){
    
        ll pmid = dp[0];
        ll pend = dp[1];
        ll nmid = dp[2];
        ll nend = dp[3];

        if(v[i] > 0){

            dp[0] = pmid + pend;
            dp[1] = pend + 1;
            dp[2] = nmid + nend;
            dp[3] = nend;
        }
        else{

            dp[0] = pmid + pend;
            dp[1] = nend;
            dp[2] = nmid + nend;
            dp[3] = pend + 1;
        }
    }

    cout << dp[2] + dp[3] << sp << dp[0]+ dp[1] << nl;
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

