#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(vector<ll> &v, ll &n, ll &m){

    sort(all(v));

    vector<ll> ans;

    ll ind = 0;

    for(ll i = n-1; i >= 1; i--){

        ans.push_back(v[ind]);

        ind += i;
    }

    ans.push_back(1e9);

    print(ans);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        ll m = n*(n-1)/2;

        vector<ll> v (m);

        for(ll i = 0; i < m; i++) cin >> v[i]; 

        solve(v, n, m);
    }
}

