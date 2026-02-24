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
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

// https://www.youtube.com/watch?v=ITYHRTd5W8A -> Solution

void solve(vll &l, vll &r, vector<char> &opl, vector<char> &opr, ll &n){

    vll MulFactor (2);  // Each Left gate represented as (f1 - 1), c1 where f1 = MulFactor[0], c1 = AddFactor[0]
    vll AddFactor (2);  // If only addition happens at say Left gate => f1 - 1 = 0 else c1 = 0 // similarly for right

    ll a = 1, b = 1, c = 0;     // base values of the coefficents at the end of all gates

    for(ll i = n-1; i >= 0; i--){

        MulFactor[0] = MulFactor[1] = AddFactor[0] = AddFactor[1] = 0;

        if(opl[i] == 'x') MulFactor[0] = l[i] - 1;
        else AddFactor[0] = l[i];

        if(opr[i] == 'x') MulFactor[1] = r[i] - 1;
        else AddFactor[1] = r[i];

        ll aNew, bNew, cNew;

        if(a >= b){

            aNew = a * (1 + MulFactor[0]);
            bNew = b + a * (MulFactor[1]);
            cNew = c + a * (AddFactor[0] + AddFactor[1]);
        }
        else{

            aNew = a + b * (MulFactor[0]); 
            bNew = b * (1 + MulFactor[1]);
            cNew = c + b * (AddFactor[0] + AddFactor[1]);
        }

        a = aNew;
        b = bNew;
        c = cNew;
    }

    ll sum = a + b + c;

    cout << sum << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vll l (n), r(n);
        vector<char> opl (n), opr (n);

        for(ll i = 0; i < n; i++) cin >> opl[i] >> l[i] >> opr[i] >> r[i]; 

        solve(l, r, opl, opr, n);
    }
}

