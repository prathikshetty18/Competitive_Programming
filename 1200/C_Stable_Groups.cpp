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

void solve(vll &v, ll &n, ll &k, ll &x){

    sort(all(v));

    priority_queue<ll, vector<ll>, greater<ll>> pq;     // mind heap with diff

    ll cnt = 1;

    for(ll i = 1; i < n; i++){
    
        ll diff = v[i] - v[i-1];

        if(diff > x){

            cnt++;
            pq.push(diff);
        }
    }

    while(!pq.empty() && k > 0){

        ll need = (pq.top()-1)/x;

        if(k - need >= 0) cnt--;

        k = k - need;
        pq.pop();
    }

    cout << cnt << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, k, x;
        
        cin >> n >> k >> x;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, k, x);
    }
}

