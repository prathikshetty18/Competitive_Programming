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
 
void solve(vll &v, ll &n, ll &x, ll &y){

    map<ll, map<ll, ll>> mp;

    for(ll i = 0; i < n; i++){

        ll remx = v[i] % x;
        ll remy = v[i] % y;

        mp[remx][remy]++;
    }

    ll count = 0;

    for(auto mod1 : mp){

        ll modx = mod1.first;
        ll reqModx = x - modx;
        reqModx %= x;

        for(auto mod2: mod1.second){

            ll mody = mod2.first;
            ll reqMody = mody;

            ll count1 = mp[modx][mody];
            ll count2 = mp[reqModx][reqMody];

            if(modx != reqModx) count += count1 * count2;
            else count += count1 * (count1 - 1) / 2;
            

            // cout << "Mp[" << modx << "][" << mody << "]: " << mp[modx][mody].size() << nl;

            // cout << "Modx: " << modx << " mody: " << mody << " ReqModx: " << reqModx << " reqMody: " << reqMody << nl;

            mp[reqModx].erase(reqMody);
        }
    }

    cout << count << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, x, y;
        
        cin >> n >> x >> y;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, x, y);
    }
}

