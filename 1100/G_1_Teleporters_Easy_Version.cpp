#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define print(v) for(auto ele : v) cout << ele << sp; cout << nl;


void solve(vector<ll> &v, ll &n, ll &c){

    sort(all(v));

    // print(v);
    
    ll ans = 0;

    for(int i = 0; i < n; i++){

        if(v[i] <= c){

            c -= v[i];
            ans++;
        }
        else break;
    }

    cout << ans << nl;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, c;
        
        cin >> n >> c;

        vector<ll> v (n);

        ll temp = 1;

        for(ll i = 0; i < n; i++){
            
            cin >> v[i]; 
            v[i] += temp;
            temp++;
        }

        solve(v, n, c);

        t--;
    }
}

