#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007
ll ceil_div(ll a, ll b){ return a/b + (a%b != 0); }

void solve(vector<ll> &v, ll &n){

    if(v[n-2] <= v[n-1] && v[n-1] >= 0){

        cout << n-2 << nl;

        for(ll i = 0; i < n-2; i++){

            cout << i+1 << sp << n-1 << sp << n << nl;
        }

    }
    else{

        for(ll i = 1; i < n; i++){

            if(v[i] < v[i-1]){

                cout << -1 << nl;
                return;
            }
        }

        cout << 0 << nl;
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while(t--){

        ll n;
        
        cin >> n;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);
    }
}

