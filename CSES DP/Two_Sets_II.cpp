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

void solve(ll &n){

    ll sum = n * (n + 1) / 2;

    if((sum & 1) == 1){

        cout << 0 << nl;
        return;
    }

    sum /= 2;

    vvll dp(n+1, vll(sum+1, 0));

    dp[0][0] = 1;

    for(ll i = 1; i <= n; i++){
    
        for(ll tar = 0; tar <= sum; tar++){
        
            if(tar == 0){

                dp[i][tar] = 1;
                continue;
            }

            dp[i][tar] = (dp[i][tar] + dp[i-1][tar]) % mod;
            
            if(tar >= i) dp[i][tar] = (dp[i][tar] + dp[i-1][tar-i]) % mod; 
        }
    }

    // Cannot divide by 2 directly after doing mod as mod division works differnetly
    // you need to multiply by the mod inverse

    cout << ( dp[n][sum] * 500000004 ) % mod << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n;
        
        cin >> n;

        solve(n);
    }
}

