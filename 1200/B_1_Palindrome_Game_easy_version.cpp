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

void solve(string &s, ll &n){

    ll cnt = 0;

    for(ll i = 0; i < n; i++){
    
        cnt += s[i] == '0';
    }

    if(cnt == 0) cout << "DRAW\n";
    else if(cnt == 1) cout << "BOB\n";
    else if(cnt % 2 == 1) cout << "ALICE\n";
    else cout << "BOB\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        string s;

        cin >> s; 

        solve(s, n);
    }
}

