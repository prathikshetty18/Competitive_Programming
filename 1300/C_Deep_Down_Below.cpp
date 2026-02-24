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
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

bool isPossible(vpll &v, ll pow, ll &n){

    for(ll i = 0; i < n; i++){

        if(pow <= v[i].ff){

            // cout << "mid: " << pow << " v[i]: " << v[i].ff << " NOT POSSIBLE\n";

            return false;
        }
        else pow += v[i].ss;
    }

    return true;
}

void solve(vpll &v, ll &n){

    sort(all(v));

    ll l = 1, r = 1e9 + 1;

    // r = 100;

    while(l <= r){

        ll mid = l + (r-l)/2;

        // cout << "l: " << l << " r: " << r << nl;

        if(isPossible(v, mid, n)) r = mid-1;
        else l = mid + 1;
    }

    cout << l << nl;
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

            ll k; cin >> k;
            ll maxi = INT_MIN;

            for(ll j = 0; j < k; j++){

                ll temp; cin >> temp;

                maxi = max(maxi, temp - j);
            }

            v[i].ff = maxi;
            v[i].ss = k;
        }

        solve(v, n);
    }
}

