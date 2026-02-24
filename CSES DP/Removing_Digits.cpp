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

void solve(ll &sum){

    vll dp(sum+1, 1e6);

    dp[0] = 0;

    for(ll tar = 0; tar <= sum; tar++){

        ll num = tar;

        while(num > 0){

            ll digit = num % 10;
            num /= 10;
        
            if(tar >= digit) dp[tar] = min(dp[tar], 1 + dp[tar-digit]);
        }
    }

    cout << (dp[sum] == 1e9 ? -1 : dp[sum])  << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll sum;
        
        cin >> sum;

        solve(sum);
    }
}

