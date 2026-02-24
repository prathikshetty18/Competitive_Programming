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

void solve(vpll &v, ll &n){

    ll count = 0;

    sort(all(v));

    ll maxSum = 2*n-1;

    for(ll i = 0; i < n; i++){
        
        ll j = i + 1;

        while(j < n && v[i].first * v[j].first <= maxSum){

            if(v[i].first * v[j].first == v[i].second + v[j].second) count++;
            j++;
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

        ll n;
        
        cin >> n;

        vpll v (n);

        for(ll i = 0; i < n; i++){
            
            cin >> v[i].first;
            v[i].second = i+1; 
        }

        solve(v, n);
    }
}

