#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> 
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;    // find_by_order(x) -> Elements less than x, order_of_key(x) -> xth smallest element

#define ll long long
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

vll palims;
vvll dp;

bool palCheck(ll &i){

    string num = to_string(i);
    ll n = num.sz();

    for(ll i = 0; i < n/2; i++){
    
        if(num[i] != num[n-1-i]){

            return false;
        }
    }

    return true;
}

void init(){

    for(ll i = 1; i <= 4*1e4; i++){
    
        if(palCheck(i)){

            palims.pb(i);
        }
    }

    ll ind = palims.size();
    ll n = 4*1e4;

    dp.resize(ind, vll(n, 0));

    for(ll i = 0; i < ind; i++){
    
        for(ll tar = 0; tar <= n; tar++){

            if(i == 0){

                dp[i][tar] = 1;
                continue;
            }
        
            if(tar >= palims[i]){

                dp[i][tar] = mod_add(dp[i][tar], dp[i][tar-palims[i]]);
            }

            dp[i][tar] = mod_add(dp[i][tar], dp[i-1][tar]);
        }
    }

}


void solve(ll &n){

    cout << dp[palims.sz()-1][n] << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        solve(n);
    }
}

