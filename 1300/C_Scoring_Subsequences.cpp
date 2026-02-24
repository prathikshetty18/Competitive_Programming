#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
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

ll binarySearch(vll &v, ll l, ll r){

    ll ind = r;

    while(l <= r){

        ll mid = l + (r-l)/2;

        if(v[mid]/(ind - mid + 1) >= 1){

            r = mid - 1;
        }
        else l = mid + 1;
    }

    return l;
}


void solve(vll &v, ll &n){

    for(ll i = 0; i < n; i++){
    
        ll ind = binarySearch(v, 0, i);

        // cout << "i: " << i << " ind: " << ind << nl << nl << nl;

        cout << i - ind + 1 << sp;
    }

    cout << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

