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
#define vppll vector<pair<ll, pair<ll, ll>>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

bool comp(pair<ll, pair<ll, ll>> &p1, pair<ll, pair<ll, ll>> &p2){

    if(p1.ff != p2.ff){

        return p1.ff < p2.ff;
    }
    else return p1.ss.ff < p2.ss.ff;
}

void solve(vppll &v, ll &n){

    sort(all(v), comp);

    vpll res = {{v[0].ss.ss, 1LL}};

    bool group2Check = false;
    ll mini = v[0].ff, maxi = v[0].ss.ff;

    for(ll i = 1; i < n; i++){
    
        if(v[i].ff >= mini && v[i].ff <= maxi){

            maxi = max(maxi, v[i].ss.ff);
            res.pb({v[i].ss.ss, 1});
        }
        else{ 
            res.pb({v[i].ss.ss, 2});
            group2Check = true;
        }
    }

    if(group2Check){

        sort(all(res));

        for(ll i = 0; i < n; i++){
        
            cout << res[i].ss << sp;
        }

        cout << nl;
    }
    else cout << -1 << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vppll v (n);

        for(ll i = 0; i < n; i++){
            
            cin >> v[i].ff >> v[i].ss.ff; 
            v[i].ss.ss = i;
        }

        solve(v, n);
    }
}

