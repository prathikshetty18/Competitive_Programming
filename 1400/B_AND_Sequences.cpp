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

void solve(vll &v, ll &n){

    vll allOnes (30, 1);

    for(ll i = 0; i < n; i++){
    
        for(ll j = 0; j < 30; j++){

            if(((v[i] >> j) & 1) == 0){

                allOnes[j] = 0;
            }
        }
    }

    ll cnt = 0;

    for(ll i = 0; i < n; i++){

        ll flag = 0;
    
        for(ll j = 0; j < 30; j++){

            if((!allOnes[j] && ((v[i] >> j) & 1) == 1)){

                flag = 1;
                break;
            }
        }

        if(flag == 0) cnt++;
    }

    if(cnt < 2){

        cout << 0 << nl;
        return;
    }

    ll tot = 1;

    tot = mod_mul(tot, cnt);
    tot = mod_mul(tot, cnt-1);

    for(ll i = 2;  i <= n-2; i++){

        tot = mod_mul(tot, i);
    }

    cout << tot << nl;
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

