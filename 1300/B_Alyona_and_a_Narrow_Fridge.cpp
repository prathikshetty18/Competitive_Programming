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

bool possible(vll v, ll &n, ll h, ll &bottles){

    sort(v.begin(), v.begin() + bottles + 1);

    // print(v);

    for(ll i = bottles; i >= 0; i -= 2){

        h -= v[i];

        // cout << "h: " << h << " v[i]: " << v[i] << nl;

        if(h < 0) return false;
    }

    return true;
}

void solve(vll &v, ll &n, ll &h){

    ll l = 0, r = n-1;

    while(l <= r){

        ll mid = l + (r-l)/2;

        //cout << "l: " << l << " r: " << r << " mid: " << mid << nl;

        if(possible(v, n, h, mid)){

            l = mid + 1;
        }
        else r = mid - 1;
    }

    cout << r+1 << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, h;
        
        cin >> n >> h;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, h);
    }
}

