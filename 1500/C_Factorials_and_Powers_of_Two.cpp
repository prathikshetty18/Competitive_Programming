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

vll facts;

void init(){

    ll num = 2;

    for(ll i = 3; i <= 14; i++){
    
        num *= i;
        facts.pb(num);
    }

    reverse(all(facts));

    // debug(facts.sz());
}

void solve(ll &n){

    ll ans = __builtin_popcountll(n);

    for(ll i = 1; i < 1 << 12; i++){
    
        ll sum = 0;

        for(ll j = 0; j < 12; j++){
        
            if((i >> j) & 1){

                sum += facts[j];
            }

            if(sum > n) break;
        }

        if(sum > n) continue;

        ans = min(ans, (ll)__builtin_popcountll(i) + (ll)__builtin_popcountll(n-sum));        
    }

    cout << ans << nl;
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

