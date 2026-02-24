#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "
#define nl "\n"

void solve(vector<ll> &v, ll &n){

    sort(v.begin(), v.end());

    if(v[0] != 1){

        cout << "NO\n";
        return;
    }

    ll sum = 1;

    for(ll i = 1; i < n; i++){

        if(v[i] > sum){

            cout << "NO\n";
            return;        
        }

        sum += v[i];
    }

    cout << "YES\n";
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;
    }
}

