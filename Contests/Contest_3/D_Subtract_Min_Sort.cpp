#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(vector<ll> &v, ll n){

    for(ll i = 0; i < n-1; i++){

        if(v[i] > v[i+1]){

            cout <<"NO\n";
            return;
        }
        else{

            v[i+1] -= v[i];
            v[i] = 0; 
        }
    }

    cout <<"YES\n";
    return;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        0
        cin >> n;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n);

        t--;
    }
}

