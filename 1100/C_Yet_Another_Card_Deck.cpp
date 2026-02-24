#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void updateVec(vector<ll> &v, ll &pos){

    for(auto &ele : v){

        if(ele != -1 && ele < pos) ele++; 
        else if(ele == pos) ele = 1;
    }
}

void solve(vector<ll> &v, vector<ll> &queries, ll &n, ll &q){
    
    for(ll i = 0; i < q; i++){

        ll val = queries[i];
        ll pos = v[val];

        cout << pos << sp;

        updateVec(v, pos);
    }

    cout << nl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, q;
        
        cin >> n >> q;

        vector<ll> v (51, -1);
        vector<ll> queries (q);

        ll temp = 0, ind = 1;

        for(ll i = 0; i < n; i++){
        
            ll temp;

            cin >> temp;

            if(v[temp] == -1){

                v[temp] = ind;
            }

            ind++;
        }

        for(ll i = 0; i < q; i++){
        
            cin >> queries[i];
        }

        // print(queries);

        solve(v, queries, n, q);
    }
}


