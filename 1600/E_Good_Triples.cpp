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

void solve(ll &n, vll &digitCount){

    ll ans = 1;

    while(n >= 0){

        ll digit = n % 10;
        n /= 10;

        ans *= digitCount[digit];

        if(n == 0) break;
    }

    cout << ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    vll digitCount (10, 0);

    for(ll i = 0; i < 10; i++){
    
        for(ll j = 0; j < 10; j++){
        
            for(ll k = 0; k < 10; k++){
            
                if(i + j + k <= 9){

                    digitCount[i+j+k]++;
                }
            }
        }
    }

    // debug(digitCount);

    while(t--){

        ll n;
        
        cin >> n;

        solve(n, digitCount);
    }
}

