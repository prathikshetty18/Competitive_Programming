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
#define vvll vector<vector<ll>>
#define vpll vector<pair<ll, ll>>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(vll &v, ll &n, ll &m){

    priority_queue<ll> EndingZeros;
    ll digits = 0;

    for(ll i = 0; i < n; i++){
    
        digits += log10l(v[i]) + 1;

        ll zeros = 0;

        while(v[i] % 10 == 0){

            zeros++;
            v[i] /= 10;
        }

        if(zeros > 0) EndingZeros.push(zeros);
    }

    while(!EndingZeros.empty()){

        digits -= EndingZeros.top();
        if(!EndingZeros.empty()) EndingZeros.pop();
        if(!EndingZeros.empty()) EndingZeros.pop();
    }

    // cout << "digits: " << digits << nl;

    if(digits > m) cout << "Sasha\n";
    else cout << "Anna\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, m;
        
        cin >> n >> m;

        vll v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, m);
    }
}

