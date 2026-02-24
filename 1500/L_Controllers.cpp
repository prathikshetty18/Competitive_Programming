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

void solve(ll &n, ll &pcnt, ll &ncnt){

    if(pcnt < ncnt) swap(pcnt, ncnt);

    ll q; cin >> q;

    for(ll i = 0; i < q; i++){
    
        ll x, y; cin >> x >> y;

        ll LCM = lcm(x, y);

        if(x < y) swap(x, y);

        ll a = LCM / y;
        ll b = LCM / x;

        if(pcnt == ncnt){

            cout << "YES" << nl;
            continue;
        }
        else if(a == b){

            cout << "NO" << nl;
            continue;
        }
        else if((pcnt - ncnt) % (a - b) != 0){

            cout << "NO" << nl;
        }
        else{

            ll div = (pcnt - ncnt) / (a - b);

            if(pcnt >= a * div && ncnt >= b * div){

                cout << "YES" << nl;
            }
            else cout << "NO" << nl;
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n;
        
        cin >> n;

        ll pcnt = 0, ncnt = 0;

        for(ll i = 0; i < n; i++){

            char ch; cin >> ch;

            pcnt += (ch == '+');
            ncnt += (ch == '-');
        }

        solve(n, pcnt, ncnt);
    }
}

