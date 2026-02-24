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

void solve(ll &n, vector<bool> &sieve){

    ll x = n/3 - 1;
    ll y = (n+1)/2 ;

    if(x <= 0){

        for(ll i = 1; i <= n; i++){
        
            cout << i << sp;
        }

        cout << nl;

        return;
    }

    for(ll i = x; i <= y; i++){
    
        if(sieve[i]){      // is prime

            ll j = 1, k = 2*i - 1;

            while(j < k){

                cout << j << sp << k << sp;
                j++;
                k--;
            }

            if(j == k) cout << j << sp;

            j = 2*i;

            while(j <= n) cout << j++ << sp;

            cout << nl;

            return;
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<bool> sieve (1e5+1, true);
    sieve[0] = sieve[1] = false;

    for(ll i = 2; i * i <= 1e5 + 1; i++){

        if(sieve[i] == true){

            for(ll j = i * i; j <= 1e5 + 1; j += i){

                sieve[j] = false;
            }
        }
    }

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        solve(n, sieve);
    }
}

