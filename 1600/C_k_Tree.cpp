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

// dp[i][j] = # paths of total weight == i with largest weight == j

void solve(ll &n, ll&k, ll &d){

    vvll dp (n+1, vll (k+1, 0));

    dp[0][0] = 1;   // for counting cases like dp[1][1] = dp[2][2] = 1, we need to set this to 1

    for(ll i = 1; i <= n; i++){

        for(ll j = 1; j <= k && j <= i; j++){

            // debug(i, j);

            // count cases when t < j
        
            for(ll t = 1; t < j; t++){

                // debug(t);
            
                if(i - t > 0){

                    dp[i][j] = mod_add(dp[i][j], dp[i-t][j]);
                }
            }

            // count cases when t == j

            for(ll m = 0; j - m >= 0; m++){

                // debug(m);

                if((i - j >= 0) && (j - m) >= 0) {
                    
                    dp[i][j] = mod_add(dp[i][j], dp[i-j][j-m]);
                }
            }
        }
    }

    // debug(dp);

    ll ans = 0;

    for(ll j = d; j <= k; j++){
    
        ans = mod_add(ans, dp[n][j]);
    }

    cout << ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, k, d;
        
        cin >> n >> k >> d;

        solve(n, k, d);
    }
}

