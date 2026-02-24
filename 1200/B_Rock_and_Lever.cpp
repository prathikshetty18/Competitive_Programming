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

void solve(vll &v, ll &n){

    sort(all(v));

    // vll arr, count;
    
    // arr.push_back(v[0]);
    // count.push_back(1);

    // for(ll i = 1; i < n; i++){

    //     if(v[i] != v[i-1]){

    //         arr.push_back(v[i]);
    //         count.push_back(1);
    //     }
    //     else count.back()++;
    // }

    ll count = 0;

    for(ll i = 0; i < n; i++){
    
        ll bits = log2(v[i]) + 1;

        ll maxVal = pow(2, bits) - 1;
        
        ll ind = upper_bound(v.begin(), v.end(), maxVal) - v.begin();

        count += (ind - i) * (ind - i - 1) / 2;

        // cout << "i: " << i << " ind: " << ind << nl;

        i = ind-1;
    }

    cout << count << nl;
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

