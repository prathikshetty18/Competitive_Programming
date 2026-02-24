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
#define print(v) for(auto &ele : v) cout << ele << sp; cout << nl;
#define mod 998244353
ll mod_add(ll a, ll b, ll m = mod) { return ((a % m) + (b % m)) % m; }
ll mod_mul(ll a, ll b, ll m = mod) { return ((a % m) * (b % m)) % m; }
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(string &s, ll &n){

    vll diff;

    ll count = 1;

    for(ll i = 1; i < n; i++){
    
        if(s[i] != s[i-1]){

            diff.push_back(count);
            count = 1;
        }
        else count++;
    }

    diff.push_back(count);

    count = 1;   // ways to make alterating
    ll minSteps = 0;

    ll total_groups = diff.size();

    for(auto &it : diff){

        minSteps += it - 1;

        count = mod_mul(count, it);
    }


    while((n - total_groups) > 1){

        count = mod_mul(count, n - total_groups);
        total_groups++;
    }

    cout << minSteps << sp << count << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;

        string s;

        cin >> s;

        n = s.size();

        solve(s, n);
    }
}

