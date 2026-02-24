#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sp " "

void solve(vector<ll> &v, ll &n, ll &x){

    ll mini, maxi, newMini, newMaxi;
    mini = v[0] - x;
    maxi = v[0] + x;

    ll changes = 0;

    for(ll i = 1; i < n; i++){

        newMini = v[i] - x;
        newMaxi = v[i] + x;

        if(newMini > maxi || newMaxi < mini){

            mini = newMini;
            maxi = newMaxi;

            changes++;
            continue;
        }

        if(newMini > mini) mini = newMini;
        if(newMaxi < maxi) maxi = newMaxi;
    }
    
    cout << changes << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n, x;
        
        cin >> n >> x;

        vector<ll> v (n);

        for(ll i = 0; i < n; i++) cin >> v[i]; 

        solve(v, n, x);

        t--;
    }
}

