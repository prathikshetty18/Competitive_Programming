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

void solve(ll &n, vector<bool> &sieve, vll &primeCount){

    ll count = 0;


    for(ll a = 1; a < n; a++){

        count += primeCount[n/a];
    }

    cout << count << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    vector<bool> sieve (1e7+1, true);
    sieve[0] = sieve[1] = false;

    for(ll i = 2; i*i <= 1e7; i++){

        if(sieve[i] == true){

            for(ll j = i * i; j <= 1e7; j += i){

                sieve[j] = false;
            }
        }
    }


    vll primeCount (1e7+1, 0);

    for(ll i = 2; i <= 1e7; i++){

        primeCount[i] = sieve[i] + primeCount[i-1];
    }


    while(t--){

        ll n;
        
        cin >> n;

        solve(n, sieve, primeCount);
    }
}

