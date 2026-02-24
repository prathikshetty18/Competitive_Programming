#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(vector<ll> &v, ll &n, ll &q, ll &sum){

    unorderd_set<ll> changed;
    ll newVal = -1;

    for(ll i = 0; i < q; i++){

        ll type; cin >> type;

        if(type == 1){

            ll ind, val; cin >> ind >> val;

            // cout << "ind: " << ind << " val: " << val << nl;

            if(newVal != -1 && changed.count(ind-1) == 0){

                sum -= newVal; 
                sum += val; 
                v[ind-1] = val;
            }
            else{

                sum -= v[ind-1];
                sum += val;
                v[ind-1] = val;
            }

            cout << sum << nl;
            changed.insert(ind-1);
        }
        else{

            changed.clear();

            ll val; cin >> val;

            newVal = val;

            sum = n * val;

            cout << sum << nl;
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;

    while(t--){

        ll n, q, sum = 0;
        
        cin >> n >> q;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++){
            
            cin >> v[i]; 
            sum += v[i];
        }

        solve(v, n, q, sum);
    }
}

