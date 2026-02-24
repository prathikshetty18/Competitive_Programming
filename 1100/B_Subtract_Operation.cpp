#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl  "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;
#define mod 1000000007

void solve(vector<ll> &v, ll &n, ll &k){

    sort(all(v));

    ll l = 0;
    ll r = 1;

    while(r < n){

        if(v[r] - v[l] == k){

            cout << "YES\n";
            return;
        }
        else if(v[r] - v[l] > k){

            l++;
        }
        else{

            r++;
        }
    }

    cout << "NO\n";
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){

        ll n, k;
        
        cin >> n >> k;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, k);
    }
}


