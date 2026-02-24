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

void solve(string &s, ll &n, ll &k){

    map<char, ll> mp;
    ll maxCharCount = LLONG_MIN;
    vector<map<char, ll>> uniqueColourMp (ceil_div(k, 2));
    vll maxCharFoUniqueColourMp (ceil_div(k, 2), LLONG_MIN);

    for(ll i = 0; i < n; i++){
    
        mp[s[i]]++;
        maxCharCount = max(maxCharCount, mp[s[i]]);
    }

    for(ll j = 0; j < n/k; j++){
        
        for(ll i = 0; i <= k/2; i++){

            ll ind1 = i + j*k;
            ll ind2 = (1+j)*k-i-1;

            // debug(i, j, ind1, ind2);

            if(ind1 <= ind2){

                uniqueColourMp[i][s[ind1]]++;
                maxCharFoUniqueColourMp[i] = max(maxCharFoUniqueColourMp[i], uniqueColourMp[i][s[ind1]]);
            }

            if(ind1 < ind2){

                uniqueColourMp[i][s[ind2]]++;
                maxCharFoUniqueColourMp[i] = max(maxCharFoUniqueColourMp[i], uniqueColourMp[i][s[ind2]]);
            }
        }
    }

    // debug("\n");

    if(k == 1){

        cout << n - maxCharCount << nl;
        return;
    }

    cout << n - accumulate(maxCharFoUniqueColourMp.begin(), maxCharFoUniqueColourMp.end(), 0) << nl;
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, k;
        
        cin >> n >> k;

        string s;

        cin >> s;

        solve(s, n, k);
    }
}

