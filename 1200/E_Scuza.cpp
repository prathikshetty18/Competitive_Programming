#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(vector<ll> &v, vector<pair<ll, ll>> &queries, ll &n, ll &q){

    vector<pair<ll, ll>> ans (q);

    ll curr = 0;
    ll ind = 0;

    for(ll i = 0; i < q; i++){

        while(ind < n && v[ind] <= queries[i].first){

            curr += v[ind];
            ind++;
        }

        ans[i].first = queries[i].second;
        ans[i].second = curr;
    }

    sort(all(ans));

    for(ll i = 0; i < q; i++){

        cout << ans[i].second << sp;
    }

    cout << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n, q;
        
        cin >> n >> q;

        vector<ll> v (n);
        vector<pair<ll, ll>> queries (q);

        for(ll i = 0; i < n; i++) cin >> v[i]; 
        for(ll i = 0; i < q; i++){
            
            cin >> queries[i].first;
            queries[i].second = i; 
        }

        sort(all(queries));

        solve(v, queries, n, q);
    }
}
