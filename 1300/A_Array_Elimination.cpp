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

void solve(vll &v, ll &n){

    map<ll, ll> mp;     // Set Bit : Count

    for(ll i = 0; i < n; i++){

        ll bit = 0;

        while(v[i] > 0){

            mp[bit] += (v[i] & 1);
            v[i] = v[i] >> 1;
            bit++;
        }
    }

    ll GCD = 0;

    for(auto [SetBit, count] : mp){

        GCD = gcd(GCD, count);
    }

    if(GCD == 0){

        for(ll i = 1; i <= n; i++) cout << i << sp; cout << nl;
    }

    stack<ll> rem;

    for(ll i = 1; i*i <= GCD; i++){

        if(GCD % i == 0){

            cout << i << sp;
            if(i*i != GCD) rem.push(GCD/i);
        }
    }

    while(!rem.empty()){

        cout << rem.top() << sp;
        rem.pop();
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

