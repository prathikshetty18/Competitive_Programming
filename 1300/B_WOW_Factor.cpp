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

void solve(string &s){

    ll n = s.size();

    ll count = 0;
    vll WCount;

    for(ll i = 0; i < n; i++){
    
        if(s[i] == 'o'){

            WCount.pb(count);
        }
        else if(i > 0 && s[i] == 'v' && s[i-1] == 'v'){

            count++;
        }
    }

    WCount.pb(count);

    ll ans = 0;
    ll m = WCount.size();

    for(ll i = 0; i < m-1; i++){

        ll left = WCount[i];
        ll right = WCount[m-1] - WCount[i];

        // cout << "left: " << left << " right: " << right << nl;

        ans += left*right;
    }

    cout << ans << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        string s;

        cin >> s;

        solve(s);
    }
}

