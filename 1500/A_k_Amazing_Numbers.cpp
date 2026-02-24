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

void solve(vpll &v, ll &n){
    
    map<ll, ll> gapsMap; // {num : gapsMap}

    sort(all(v));

    gapsMap[v[0].ff] = v[0].ss - 0;
    
    for(ll i = 1; i < n; i++){
    
        if(v[i].ff == v[i-1].ff){

            gapsMap[v[i].ff] = max(gapsMap[v[i].ff], v[i].ss - v[i-1].ss - 1);
        }
        else{
            gapsMap[v[i-1].ff] = max(gapsMap[v[i-1].ff], n - 1 - v[i-1].ss);
            gapsMap[v[i].ff] = v[i].ss - 0;
        }
    }

    gapsMap[v[n-1].ff] = max(gapsMap[v[n-1].ff], n - 1 - v[n-1].ss);

    vpll gaps;

    for(auto &[val, maxGap] : gapsMap){

        gaps.pb({maxGap, val});
    }

    sort(all(gaps));

    ll mini = LLONG_MAX;
    ll k = 1;

    for(ll i = 0; i < gaps.sz(); i++){
    
        if(gaps[i].ff <= k - 1){

            mini = min(mini, gaps[i].ss);
        }
        else{

            cout << ((mini == LLONG_MAX) ? -1 : mini) << sp;
            i--;
            k++;
        }
    }

    while(k <= n){

        cout << mini << sp;
        k++;
    }

    cout << nl;

    // debug(v);
    // debug(gaps);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vpll v (n);

        for(ll i = 0; i < n; i++){

            cin >> v[i].ff; 
            v[i].ss = i;
        }

        solve(v, n);
    }
}

