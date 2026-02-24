#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll &n){

    if(n % 2 == 0){

        cout << n/2 << " " << n/2 << endl;
        return;
    }

    ll maxi = 1;

    for(ll i = 2; i*i <= n; i++){

        if(n % i == 0){

            maxi = n/i;
            break;
        }
    }

    cout << maxi << " " << n - maxi << endl;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t > 0){

        ll n;
        
        cin >> n;

        solve(n);

        t--;
    }
}

