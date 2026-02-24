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

void solve(ll &n, ll &x, ll &y, ll &sum){

    ll num1 = x;
    ll num2 = x + 3;

    ll par1 = (num1 & 1);
    ll par2 = (num2 & 1);
    ll parSum = (sum & 1);
    ll pary = (y & 1);

    // cout << "x: " << x << " y: " << y << nl;

    // cout << "par1: " << par1 << " par2: " << par2 << " parSum: " << parSum << " pary: " << pary << nl;

    if(par1 == pary && parSum == 1){


        cout << "Bob" << nl;
        return;
    }
    else if(par1 != pary && parSum == 0){


        cout << "Bob" << nl;
        return;
    }
    else if(par2 == pary && parSum == 1){


        cout << "Alice" << nl;
        return;
    }
    else if(par2 != pary && parSum == 0){


        cout << "Alice" << nl;
        return;
    }
    // else{

    //     cout << "Alice" << nl;
    //     return;
    // }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, x, y, sum = 0;
        
        cin >> n >> x >> y;

        for(ll i = 0; i < n; i++){

            ll temp; cin >> temp;
            
            sum += temp; 
        }

        solve(n, x, y, sum);
    }
}

